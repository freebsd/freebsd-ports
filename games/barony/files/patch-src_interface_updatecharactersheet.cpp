--- src/interface/updatecharactersheet.cpp.orig	2022-10-30 19:09:47 UTC
+++ src/interface/updatecharactersheet.cpp
@@ -848,7 +848,7 @@ void drawSkillsSheet()
 						skillDetails[1] += 20;
 						if ( stats[clientnum]->PROFICIENCIES[PRO_RANGED] < SKILL_LEVEL_LEGENDARY )
 						{
-							skillDetails[1] = std::min(skillDetails[1], 90.0);
+							skillDetails[1] = std::min(skillDetails[1], (real_t)90.0);
 						}
 					}
 					if ( players[clientnum] && players[clientnum]->entity )
