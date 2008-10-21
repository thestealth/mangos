/*
 * Copyright (C) 2005-2008 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __BATTLEGROUNDAV_H
#define __BATTLEGROUNDAV_H
#define BG_AV_HONOR_TOWER   3
#define BG_AV_HONOR CAPTAIN 3
#define BG_AV_HONOR_GENERAL 4
#define BG_AV_HONOR_END 4 // only at bg-weekend else 0 i got 4 on a weekend, but it was not alterac-weekend.. maybe you get 4 all the time
const uint32 BG_AV_REPUTATION_TOWER[2] = { 12,18 };
const uint32 BG_AV_REPUTATION_CAPTAIN[2] = { 125,185 };
const uint32 BG_AV_REPUTATION_GENERAL[2] = { 350,525 };
#define BG_AV_HONOR_END_CAPTAIN_LIVES = 2
#define BG_AV_HONOR_END_TOWER_EXISTS  = 2
//TODO: look if reputation is right
//Per owned Graveyards      12        18
//Live CAPTAIN              125       175
//Per Undestroyed Tower       125        18
//Per Owned Mine               24        36

class BattleGround;

class BattleGroundAVScore : public BattleGroundScore
{
    public:
        BattleGroundAVScore() : GraveyardsAssaulted(0), GraveyardsDefended(0), TowersAssaulted(0), TowersDefended(0), MinesCaptured(0), LeadersKilled(0), SecondaryObjectives(0) {};
        virtual ~BattleGroundAVScore() {};
        uint32 GraveyardsAssaulted;
        uint32 GraveyardsDefended;
        uint32 TowersAssaulted;
        uint32 TowersDefended;
        uint32 MinesCaptured;
        uint32 LeadersKilled;
        uint32 SecondaryObjectives;
};

class BattleGroundAV : public BattleGround
{
    friend class BattleGroundMgr;

    public:
        BattleGroundAV();
        ~BattleGroundAV();
        void Update(time_t diff);

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player *plr);

        void RemovePlayer(Player *plr,uint64 guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);
        //bool SetupBattleGround();

        /* Scorekeeping */
        void UpdatePlayerScore(Player *Source, uint32 type, uint32 value);

    private:
};
#endif
