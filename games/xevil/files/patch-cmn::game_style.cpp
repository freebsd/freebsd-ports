--- cmn/game_style.cpp.orig	2012-05-27 06:52:29.000000000 +0900
+++ cmn/game_style.cpp	2012-05-27 06:53:11.000000000 +0900
@@ -33,15 +33,9 @@
 #include <string.h>
 }
 
-#if X11
-#include <strstream.h>
-#endif
-
-#if WIN32
-#include <strstrea.h>
-#endif
+#include <sstream>
 
-#include <iomanip.h>
+#include <iomanip>
 #include "utils.h"
 #include "coord.h"
 #include "world.h"
@@ -109,13 +103,13 @@
   /* DEFAULT: True */
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP) = 0;
 
   virtual void setup_world(WorldP,LocatorP,const DifficultyLevel &) = 0;
   virtual void new_level(int level,WorldP world,LocatorP locator,
                          const DifficultyLevel &dLevel,
-                         ostrstream &lStr,ostrstream &lTitleStr,
+                         stringstream &lStr,stringstream &lTitleStr,
                          IPhysicalManagerP manager,int humansNum) = 0;
   /* EFFECTS: These two functions start a new level in a scenario.  setup_world() should
      just setup the map and size of the world.  new_level() is called after world.reset()
@@ -158,13 +152,13 @@
   virtual ScenarioType get_scenario_type() {return EXTERMINATE;}
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP);
 
   virtual void setup_world(WorldP,LocatorP,const DifficultyLevel &);
   virtual void new_level(int level,WorldP world,LocatorP locator,
                          const DifficultyLevel &dLevel,
-                         ostrstream &lStr,ostrstream &lTitleStr,
+                         stringstream &lStr,stringstream &lTitleStr,
                          IPhysicalManagerP manager,int humansNum);
 
 
@@ -183,13 +177,13 @@
   virtual Boolean can_refill_game_objects();
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP);
 
   virtual void setup_world(WorldP,LocatorP,const DifficultyLevel &);
   virtual void new_level(int level,WorldP world,LocatorP locator,
                          const DifficultyLevel &dLevel,
-                         ostrstream &lStr,ostrstream &lTitleStr,
+                         stringstream &lStr,stringstream &lTitleStr,
                          IPhysicalManagerP manager,int humansNum);
 
   virtual void new_level_set_timer(Timer &timer);
@@ -209,7 +203,7 @@
   virtual ScenarioType get_scenario_type() {return HIVE;}
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP);
 
   virtual Boolean award_bonus();
@@ -218,7 +212,7 @@
   virtual void setup_world(WorldP,LocatorP,const DifficultyLevel &);
   virtual void new_level(int level,WorldP world,LocatorP locator,
                          const DifficultyLevel &dLevel,
-                         ostrstream &lStr,ostrstream &lTitleStr,
+                         stringstream &lStr,stringstream &lTitleStr,
                          IPhysicalManagerP manager,int humansNum);
 
   virtual void refill_enemies(Boolean enemiesRefill,WorldP,LocatorP,IPhysicalManagerP);
@@ -242,13 +236,13 @@
   virtual ScenarioType get_scenario_type() {return CAPTURE_THE_FLAG;}
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP);
 
   virtual void setup_world(WorldP,LocatorP,const DifficultyLevel &);
   virtual void new_level(int level,WorldP world,LocatorP locator,
                          const DifficultyLevel &dLevel,
-                         ostrstream &lStr,ostrstream &lTitleStr,
+                         stringstream &lStr,stringstream &lTitleStr,
                          IPhysicalManagerP manager,int humansNum);
 
   virtual void refill_enemies(Boolean enemiesRefill,WorldP,LocatorP,IPhysicalManagerP);
@@ -269,7 +263,7 @@
   virtual void setup_world(WorldP,LocatorP,const DifficultyLevel &);
   virtual void new_level(int level,WorldP world,LocatorP locator,
                          const DifficultyLevel &dLevel,
-                         ostrstream &lStr,ostrstream &lTitleStr,
+                         stringstream &lStr,stringstream &lTitleStr,
                          IPhysicalManagerP manager,int humansNum);
 
   virtual Boolean advance_level();  
@@ -292,7 +286,7 @@
   
   virtual Boolean (*get_team())(LocatorP,PhysicalP,PhysicalP) = 0;
   
-  virtual void set_level_strings(int level,ostrstream &lStr,ostrstream &lTitleStr) = 0;
+  virtual void set_level_strings(int level,stringstream &lStr,stringstream &lTitleStr) = 0;
   /* EFFECTS: Called in new_level() to set the appropriate messages. */
 
   
@@ -311,7 +305,7 @@
   virtual ScenarioType get_scenario_type() {return SEALS;}
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP);
 
   virtual Boolean award_bonus();
@@ -323,7 +317,7 @@
 #endif
   virtual Boolean (*get_team())(LocatorP,PhysicalP,PhysicalP);
 
-  virtual void set_level_strings(int level,ostrstream &lStr,ostrstream &lTitleStr);
+  virtual void set_level_strings(int level,stringstream &lStr,stringstream &lTitleStr);
 
 
 private:
@@ -342,7 +336,7 @@
   virtual ScenarioType get_scenario_type() {return ANTI_SEALS;}
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP);
 
 
@@ -351,7 +345,7 @@
 #endif
   virtual Boolean (*get_team())(LocatorP,PhysicalP,PhysicalP);
 
-  virtual void set_level_strings(int level,ostrstream &lStr,ostrstream &lTitleStr);
+  virtual void set_level_strings(int level,stringstream &lStr,stringstream &lTitleStr);
 
 
 private:
@@ -369,13 +363,13 @@
   virtual SoundName get_midisoundtrack(){return SoundNames::FIRE_SOUNDTRACK;}
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP);
 
   virtual void setup_world(WorldP,LocatorP,const DifficultyLevel &);
   virtual void new_level(int level,WorldP world,LocatorP locator,
                          const DifficultyLevel &dLevel,
-                         ostrstream &lStr,ostrstream &lTitleStr,
+                         stringstream &lStr,stringstream &lTitleStr,
                          IPhysicalManagerP manager,int humansNum);
 
   virtual Boolean award_bonus();
@@ -391,13 +385,13 @@
   virtual ScenarioType get_scenario_type() {return KILL_THE_DRAGON;}
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP);
 
   virtual void setup_world(WorldP,LocatorP,const DifficultyLevel &);
   virtual void new_level(int level,WorldP world,LocatorP locator,
                          const DifficultyLevel &dLevel,
-                         ostrstream &lStr,ostrstream &lTitleStr,
+                         stringstream &lStr,stringstream &lTitleStr,
                          IPhysicalManagerP manager,int humansNum);
 
   virtual SoundName get_midisoundtrack(){return SoundNames::FIRE_SOUNDTRACK;}
@@ -419,13 +413,13 @@
   virtual Pos human_initial_pos(WorldP,LocatorP,const Size &s);
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP);
 
   virtual void setup_world(WorldP,LocatorP,const DifficultyLevel &);
   virtual void new_level(int level,WorldP world,LocatorP locator,
                          const DifficultyLevel &dLevel,
-                         ostrstream &lStr,ostrstream &lTitleStr,
+                         stringstream &lStr,stringstream &lTitleStr,
                          IPhysicalManagerP manager,int humansNum);
 
   virtual void refill_enemies(Boolean enemiesRefill,WorldP,LocatorP,IPhysicalManagerP);
@@ -447,13 +441,13 @@
   virtual ScenarioType get_scenario_type() {return THE_POUND;}
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP);
 
   virtual void setup_world(WorldP,LocatorP,const DifficultyLevel &);
   virtual void new_level(int level,WorldP world,LocatorP locator,
                          const DifficultyLevel &dLevel,
-                         ostrstream &lStr,ostrstream &lTitleStr,
+                         stringstream &lStr,stringstream &lTitleStr,
                          IPhysicalManagerP manager,int humansNum);
 };
 
@@ -466,13 +460,13 @@
   virtual ScenarioType get_scenario_type() {return JAPAN_TOWN;}
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP);
 
   virtual void setup_world(WorldP,LocatorP,const DifficultyLevel &);
   virtual void new_level(int level,WorldP world,LocatorP locator,
                          const DifficultyLevel &dLevel,
-                         ostrstream &lStr,ostrstream &lTitleStr,
+                         stringstream &lStr,stringstream &lTitleStr,
                          IPhysicalManagerP manager,int humansNum);
 
   virtual void filter_weapons_and_other_items(LocatorP,int &weaponsNum,
@@ -581,7 +575,7 @@
 
 
 int GameStyle::new_level_check(int,WorldP,LocatorP,
-                                  int,Boolean &,ostrstream &,Timer &timer,
+                                  int,Boolean &,stringstream &,Timer &timer,
                                   IPhysicalManagerP) {  
   // A timer-based level.
   if (timer.ready()) {
@@ -791,8 +785,8 @@
 
 
 
-void Normal::describe(ostrstream &str) {
-  str << "Complete each level/scenario to proceed to the next one." << ends;
+void Normal::describe(stringstream &str) {
+  str << "Complete each level/scenario to proceed to the next one.";
 }
 
 
@@ -852,7 +846,7 @@
 
 
 int Normal::new_level_check(int enemiesPlaying,WorldP w,LocatorP l,
-                             int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                             int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                              IPhysicalManagerP manager) {
   GameStyleP delegate = get_delegate();
   return delegate->new_level_check(enemiesPlaying,w,l,level,lStrChanged,levelStr,timer,manager);
@@ -876,7 +870,7 @@
 
 void Normal::new_level(int level,WorldP world,LocatorP locator,
                        const DifficultyLevel &dLevel,
-                       ostrstream &lStr,ostrstream &lTitleStr,
+                       stringstream &lStr,stringstream &lTitleStr,
                        IPhysicalManagerP manager,int humansNum) {
   // Choose which delegate to use.
   if (level % NORMAL_SCENARIOS_FREQUENCY == 0) {
@@ -934,11 +928,10 @@
 
 
 
-void Levels::describe(ostrstream &str) {
+void Levels::describe(stringstream &str) {
   str << "Human player(s) fights through increasing levels of "
 	    << "difficulty." << "\n" 
-	    << "To complete a level you must kill all enemy players." 
-	    << ends;
+	    << "To complete a level you must kill all enemy players.";
 }
 
 
@@ -969,7 +962,7 @@
 
 
 int Levels::new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int,Boolean &,ostrstream &,Timer &,
+                              int,Boolean &,stringstream &,Timer &,
                               IPhysicalManagerP) {
   if (enemiesPlaying == 0) {
     return 1;
@@ -983,7 +976,7 @@
 
 void Levels::new_level(int level,WorldP world,LocatorP locator,
                        const DifficultyLevel &dLevel,
-                       ostrstream &lStr,ostrstream &lTitleStr,
+                       stringstream &lStr,stringstream &lTitleStr,
                        IPhysicalManagerP manager,int) {
   world->reset();  
 
@@ -991,8 +984,8 @@
   clean_physicals(False,world,locator,manager);
 
 
-  lTitleStr << "[" << level << "] Kill All Machines" << ends;
-  lStr << "Level: " << level << ends;
+  lTitleStr << "[" << level << "] Kill All Machines";
+  lStr << "Level: " << level;
 
   enemiesNum += dLevel.enemiesIncr;
   enemiesNum = Utils::minimum(enemiesNum,dLevel.enemiesMax);
@@ -1037,8 +1030,8 @@
 
 
 
-void KillKillKill::describe(ostrstream &str) {
-  str << "Every human and machine for him/her/itself." << ends;
+void KillKillKill::describe(stringstream &str) {
+  str << "Every human and machine for him/her/itself.";
 }
 
 
@@ -1095,15 +1088,15 @@
 
 void KillKillKill::new_level(int level,WorldP world,LocatorP locator,
                              const DifficultyLevel &,
-                             ostrstream &lStr,ostrstream &lTitleStr,
+                             stringstream &lStr,stringstream &lTitleStr,
                              IPhysicalManagerP manager,int) {
   world->reset();
 
   // Don't wipe out the Enemies.
   clean_physicals(True,world,locator,manager);
 
-  lTitleStr << "Level: " << level << ends;
-  lStr << "Level: " << level << ends;
+  lTitleStr << "Level: " << level;
+  lStr << "Level: " << level;
 
   // Only create enemies first time or if enemiesRefill is set.
   if (justReset) {
@@ -1152,9 +1145,9 @@
 
 
 
-void Duel::describe(ostrstream &str) {
+void Duel::describe(stringstream &str) {
   str << "Human vs. human battle to the death." 
-	    << "\n" << "Each human has 3 lives." << ends;
+	    << "\n" << "Each human has 3 lives.";
 }
 
 
@@ -1207,13 +1200,13 @@
 
 void Duel::new_level(int level,WorldP world,LocatorP locator,
                      const DifficultyLevel &,
-                     ostrstream &lStr,ostrstream &lTitleStr,
+                     stringstream &lStr,stringstream &lTitleStr,
                      IPhysicalManagerP manager,int) {
   world->reset();
   clean_physicals(False,world,locator,manager);
 
-  lTitleStr << "Level: " << level << ends;
-  lStr << "Level: " << level << ends;
+  lTitleStr << "Level: " << level;
+  lStr << "Level: " << level;
 
   // Only create enemies first time.
   if (justReset) {
@@ -1256,9 +1249,9 @@
 
 
 
-void ExtendedDuel::describe(ostrstream &str) {
+void ExtendedDuel::describe(stringstream &str) {
   str << "Human vs. human battle to the death." 
-	    << "\n" << "Unlimited lives." << ends;
+	    << "\n" << "Unlimited lives.";
 }
 
 
@@ -1318,13 +1311,13 @@
 
 void ExtendedDuel::new_level(int level,WorldP world,LocatorP locator,
                              const DifficultyLevel &,
-                             ostrstream &lStr,ostrstream &lTitleStr,
+                             stringstream &lStr,stringstream &lTitleStr,
                              IPhysicalManagerP manager,int) {
   world->reset();
   clean_physicals(False,world,locator,manager);
 
-  lTitleStr << "Level: " << level << ends;
-  lStr << "Level: " << level << ends;
+  lTitleStr << "Level: " << level;
+  lStr << "Level: " << level;
 
   // Only create enemies first time.
   if (justReset) {
@@ -1367,8 +1360,8 @@
 
 
 
-void Training::describe(ostrstream &str) {
-  str << "No enemies.  Useful for learning the controls." << ends;
+void Training::describe(stringstream &str) {
+  str << "No enemies.  Useful for learning the controls.";
 }
 
 
@@ -1392,13 +1385,13 @@
 
 void Training::new_level(int level,WorldP world,LocatorP locator,
                         const DifficultyLevel &,
-                        ostrstream &lStr,ostrstream &lTitleStr,
+                        stringstream &lStr,stringstream &lTitleStr,
                         IPhysicalManagerP manager,int) {
   world->reset();
   clean_physicals(False,world,locator,manager);
 
-  lTitleStr << "Level: " << level << ends;
-  lStr << "Level: " << level << ends;
+  lTitleStr << "Level: " << level;
+  lStr << "Level: " << level;
 }
 
 
@@ -1428,10 +1421,10 @@
 
 
 
-void Scenarios::describe(ostrstream &str) {
+void Scenarios::describe(stringstream &str) {
   str << "A number of different scenarios." << "\n"
 	    << "You must complete each scenario to continue on to the "
-	    << "next one." << ends;
+	    << "next one.";
 }
 
 
@@ -1499,7 +1492,7 @@
 
 int Scenarios::new_level_check(int enemiesPlaying,WorldP w,LocatorP l,
                              int level,Boolean &lStrChanged,
-                               ostrstream &levelStr,Timer &timer,
+                               stringstream &levelStr,Timer &timer,
                              IPhysicalManagerP manager) {
   assert(scenario);
   return scenario->new_level_check(enemiesPlaying,w,l,level,
@@ -1534,7 +1527,7 @@
 
 void Scenarios::new_level(int level,WorldP world,LocatorP locator,
                        const DifficultyLevel &dLevel,
-                       ostrstream &lStr,ostrstream &lTitleStr,
+                       stringstream &lStr,stringstream &lTitleStr,
                        IPhysicalManagerP manager,int humansNum) {
   // Works even if scenario is NULL.
   if (!scenario || scenario->advance_level()) {
@@ -1804,7 +1797,7 @@
 
 
 int Exterminate::new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                                 int,Boolean &,ostrstream &,Timer &,
+                                 int,Boolean &,stringstream &,Timer &,
                                  IPhysicalManagerP) {
   if (enemiesPlaying == 0) {
     return 1;
@@ -1822,10 +1815,10 @@
 
 void Exterminate::new_level(int level,WorldP,LocatorP,
                             const DifficultyLevel &dLevel,
-                            ostrstream &lStr,ostrstream &lTitleStr,
+                            stringstream &lStr,stringstream &lTitleStr,
                             IPhysicalManagerP manager,int) {
-  lTitleStr << "[" << level << "] EXTERMINATE" << ends;
-  lStr << "[" << level << "] EXTERMINATE\nKill all machines." << ends;
+  lTitleStr << "[" << level << "] EXTERMINATE";
+  lStr << "[" << level << "] EXTERMINATE\nKill all machines.";
 
   // Doesn't increment like LEVELS game style
   enemiesNum = dLevel.enemiesIncr;
@@ -1852,7 +1845,7 @@
 
 int Bonus::new_level_check(int,WorldP,LocatorP locator,
                            int level,Boolean &lStrChanged,
-                           ostrstream &levelStr,Timer &timer,
+                           stringstream &levelStr,Timer &timer,
                            IPhysicalManagerP) {
   // Ran out of time.
   if (timer.ready()) {
@@ -1873,13 +1866,13 @@
   if (remaining != frogsRemaining) {
     frogsRemaining = remaining;
     levelStr << "[" << level << "] BONUS LEVEL\nfrogs remaining: " 
-	      << remaining << ends;
+	      << remaining;
     lStrChanged = True;
     if (remaining > 0) {
-	    ostrstream arenaStr;
+	    stringstream arenaStr;
 	    arenaStr << remaining << " Frog" << 
-	      (remaining > 1 ? "s" : "") << " Remaining" << ends;
-	    locator->arena_message_enq(arenaStr.str());
+	      (remaining > 1 ? "s" : "") << " Remaining";
+	    locator->arena_message_enq(Utils::strdup(arenaStr.str().c_str()));
     }
 
     // Will only be called once per level.
@@ -1907,7 +1900,7 @@
 
 void Bonus::new_level(int level,WorldP world,LocatorP locator,
                       const DifficultyLevel &,
-                      ostrstream &lStr,ostrstream &lTitleStr,
+                      stringstream &lStr,stringstream &lTitleStr,
                       IPhysicalManagerP manager,int) {
   // Create frogs
   for (int n = 0; n < SCENARIO_BONUS_FROGS; n++) {
@@ -1940,9 +1933,9 @@
   frogsRemaining = SCENARIO_BONUS_FROGS;
 
   lTitleStr << "[" << level << "] Bonus Level: Kill " 
-		  << (int)SCENARIO_BONUS_FROGS << " Frogs"  << ends;
+		  << (int)SCENARIO_BONUS_FROGS << " Frogs";
   lStr << "[" << level << "] BONUS LEVEL\nfrogs remaining: " 
-	     << (int)SCENARIO_BONUS_FROGS << ends;
+	     << (int)SCENARIO_BONUS_FROGS;
 }
 
 
@@ -1960,7 +1953,7 @@
 
 
 int Hive::new_level_check(int,WorldP,LocatorP locator,
-                          int,Boolean &,ostrstream &,Timer &,
+                          int,Boolean &,stringstream &,Timer &,
                           IPhysicalManagerP) {
   PhysicalP xit = locator->lookup(xitId);
   assert(xit); // The Xit should never be destroyed.
@@ -1987,7 +1980,7 @@
 
 void Hive::new_level(int level,WorldP world,LocatorP locator,
                      const DifficultyLevel &,
-                     ostrstream &lStr,ostrstream &lTitleStr,
+                     stringstream &lStr,stringstream &lTitleStr,
                      IPhysicalManagerP manager,int) {
 	// Aliens are created in Game::clock.
 
@@ -2012,8 +2005,8 @@
     locator->add(egg);
   }
   
-  lTitleStr << "[" << level << "] HIVE" << ends;
-  lStr << "[" << level << "] HIVE.\nFind the exit." << ends;
+  lTitleStr << "[" << level << "] HIVE";
+  lStr << "[" << level << "] HIVE.\nFind the exit.";
 }
 
 
@@ -2073,7 +2066,7 @@
 
 
 int CaptureTheFlag::new_level_check(int,WorldP,LocatorP locator,
-                                    int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &,
+                                    int level,Boolean &lStrChanged,stringstream &levelStr,Timer &,
                                     IPhysicalManagerP manager) {
   int fRemaining = 0;
   for (int n = 0; n < SCENARIO_FLAG_FLAGS; n++) {
@@ -2091,19 +2084,19 @@
     flagsRemaining = fRemaining;
     levelStr <<  "[" <<  level <<  "] COLLECT " 
 	     <<  (int)SCENARIO_FLAG_FLAGS 
-	     << " FLAGS\nremaining: "<<  flagsRemaining <<   ends;
+	     << " FLAGS\nremaining: "<<  flagsRemaining;
     lStrChanged = True;
 
-    ostrstream arenaStr;
+    stringstream arenaStr;
     if (fRemaining != 0) {
       arenaStr << flagsRemaining << " Flag" <<
-	      (flagsRemaining > 1 ? "s" : "") << " Remaining" << ends;
+	      (flagsRemaining > 1 ? "s" : "") << " Remaining";
     }
     else {
-      arenaStr << "All Flags Collected" << ends;
+      arenaStr << "All Flags Collected";
     }
       
-    locator->arena_message_enq(arenaStr.str());
+    locator->arena_message_enq(Utils::strdup(arenaStr.str().c_str()));
   }
 
   if (fRemaining == 0) { // All flags are gone, so end level.
@@ -2124,7 +2117,7 @@
 
 void CaptureTheFlag::new_level(int level,WorldP world,LocatorP locator,
                                const DifficultyLevel &,
-                               ostrstream &lStr,ostrstream &lTitleStr,
+                               stringstream &lStr,stringstream &lTitleStr,
                                IPhysicalManagerP,int) {
   for (int n = 0; n < SCENARIO_FLAG_FLAGS; n++) {
 	  Pos pos = world->empty_accessible_rect(Flag::get_size_max());
@@ -2136,9 +2129,9 @@
   flagsRemaining = SCENARIO_FLAG_FLAGS;
 
   lTitleStr << "[" << level << "] Capture The Flag: " 
-		  << (int)SCENARIO_FLAG_FLAGS << " Flags" << ends;
+		  << (int)SCENARIO_FLAG_FLAGS << " Flags";
   lStr << "[" << level << "] COLLECT " << (int)SCENARIO_FLAG_FLAGS 
-	     << " FLAGS.\nremaining: " << (int)SCENARIO_FLAG_FLAGS << ends;
+	     << " FLAGS.\nremaining: " << (int)SCENARIO_FLAG_FLAGS;
 }
 
 
@@ -2169,7 +2162,7 @@
 
 void GenericSeals::new_level(int level,WorldP world,LocatorP locator,
                          const DifficultyLevel &,
-                         ostrstream &lStr,ostrstream &lTitleStr,
+                         stringstream &lStr,stringstream &lTitleStr,
                          IPhysicalManagerP,int) {
   // Add a team for each human in the game.
   // Don't use locator->humans_registered() because they may not have been
@@ -2298,7 +2291,7 @@
 
 
 int Seals::new_level_check(int,WorldP,LocatorP locator,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &,
                               IPhysicalManagerP) {  
   int lemOut,lemSafe,lemActive,lemDead;
   compute_out_safe_active_dead(locator,lemOut,lemSafe,lemActive,lemDead);
@@ -2312,10 +2305,10 @@
 
     // Only update arena string if sealsSafe has changed.
     if (lemSafe != sealsSafe && lemSafe != SCENARIO_SEALS_NEED) {
-      ostrstream arenaStr;
+      stringstream arenaStr;
       arenaStr << "Save " << (SCENARIO_SEALS_NEED - lemSafe)
-               << " More Baby Seals" << ends;
-      locator->arena_message_enq(arenaStr.str());
+               << " More Baby Seals";
+      locator->arena_message_enq(Utils::strdup(arenaStr.str().c_str()));
     }
 
     sealsSafe = lemSafe;
@@ -2324,18 +2317,17 @@
     levelStr << "[" << level << "] SAVE " 
             << (int)SCENARIO_SEALS_NEED << " BABY SEALS\n" 
             << "out: " << sealsOut << " safe: " << sealsSafe
-            << " dead: " << lemDead
-            << ends;
+            << " dead: " << lemDead;
     lStrChanged = True;
 
     // New level if enough seals are safe or too many are dead.
     if (lemDead > (SCENARIO_SEALS_SEALS - SCENARIO_SEALS_NEED)
 	      || lemSafe >= SCENARIO_SEALS_NEED) {
       if (lemSafe < SCENARIO_SEALS_NEED) {
-	      ostrstream msg;
+	      stringstream msg;
 	      msg << "YOU FAILED TO SAVE " << (int)SCENARIO_SEALS_NEED
-	          << " BABY SEALS. TRY THIS LEVEL AGAIN." << ends;
-	      locator->arena_message_enq(msg.str());
+	          << " BABY SEALS. TRY THIS LEVEL AGAIN.";
+	      locator->arena_message_enq(Utils::strdup(msg.str().c_str()));
       }
       else {
         locator->arena_message_enq(Utils::strdup("Good work.  Go to the next level."));
@@ -2365,11 +2357,10 @@
 
 
   
-void Seals::set_level_strings(int level,ostrstream &lStr,ostrstream &lTitleStr) {
-  lTitleStr << "[" << level << "] SAVE THE BABY SEALS" << ends;
+void Seals::set_level_strings(int level,stringstream &lStr,stringstream &lTitleStr) {
+  lTitleStr << "[" << level << "] SAVE THE BABY SEALS";
   lStr << "[" << level << "] SAVE "<< 
-	  (int)SCENARIO_SEALS_NEED << " BABY SEALS\n" 
-	     << "out: 0 safe: 0 dead: 0" << ends;
+	  (int)SCENARIO_SEALS_NEED << " BABY SEALS\n" << "out: 0 safe: 0 dead: 0";
 }
 
 
@@ -2430,7 +2421,7 @@
 
 
 int AntiSeals::new_level_check(int,WorldP,LocatorP locator,
-                                  int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &,
+                                  int level,Boolean &lStrChanged,stringstream &levelStr,Timer &,
                                   IPhysicalManagerP) {  
   // level not over by default.
   int ret = -1;
@@ -2441,15 +2432,13 @@
 
   // Failure
   if (lemSafe > SCENARIO_ANTI_SEALS_MAX_SLIPPAGE) {
-	  ostrstream msg;
 #if 0
     // Not enough space on screen, need two lines.
 	  msg << "YOU LET TOO MANY OF THE FAT BASTARDS GET AWAY\n"
 	      << "Try this level again" << ends;
 #else
-	  msg << "YOU LET TOO MANY OF THE FAT BASTARDS GET AWAY" << ends;
 #endif
-	  locator->arena_message_enq(msg.str());
+	  locator->arena_message_enq(Utils::strdup("YOU LET TOO MANY OF THE FAT BASTARDS GET AWAY"));
 
     // start new level
     ret = 1;
@@ -2473,13 +2462,11 @@
       }
       // Update UI
       else if (lemSafe == sealsSafe) {  // o.w. the "one got away" message takes priority
-        ostrstream arenaStr;
-        arenaStr << "Kill "
-          << lemToKill << " More Baby Seals" << ends;
-        locator->arena_message_enq(arenaStr.str());
+        stringstream arenaStr;
+        arenaStr << "Kill " << lemToKill << " More Baby Seals";
+        locator->arena_message_enq(Utils::strdup(arenaStr.str().c_str()));
 
-        levelStr << "[" << level << "] KILL " 
-                << lemToKill << " BABY SEALS" << ends;
+        levelStr << "[" << level << "] KILL " << lemToKill << " BABY SEALS";
         lStrChanged = True;
       }
     }  // lemDead != sealsDead
@@ -2502,10 +2489,10 @@
 
 
   
-void AntiSeals::set_level_strings(int level,ostrstream &lStr,ostrstream &lTitleStr) {
-  lTitleStr << "[" << level << "] KILL THE BABY SEALS" << ends;
+void AntiSeals::set_level_strings(int level,stringstream &lStr,stringstream &lTitleStr) {
+  lTitleStr << "[" << level << "] KILL THE BABY SEALS";
   lStr << "[" << level << "] KILL "<< 
-	  (int)SCENARIO_SEALS_SEALS << " BABY SEALS" << ends;
+	  (int)SCENARIO_SEALS_SEALS << " BABY SEALS";
 }
 
 
@@ -2552,7 +2539,7 @@
 
 
 int KillTheFireDemon::new_level_check(int enemiesPlaying,WorldP,LocatorP locator,
-                                   int,Boolean &,ostrstream &,Timer &,
+                                   int,Boolean &,stringstream &,Timer &,
                                    IPhysicalManagerP) {
   if (enemiesPlaying == 0) {
     locator->arena_message_enq(Utils::strdup("Take That, You Mother-Fucking Spawn From Hell"));
@@ -2572,12 +2559,12 @@
 
 void KillTheFireDemon::new_level(int level,WorldP,LocatorP,
                                  const DifficultyLevel &,
-                                 ostrstream &lStr,ostrstream &lTitleStr,
+                                 stringstream &lStr,stringstream &lTitleStr,
                                  IPhysicalManagerP manager,int) {
   manager->create_enemy(manager->enemy_physical(A_FireDemon));
 
-  lTitleStr << "[" << level << "] FIRE DEMON" << ends;
-  lStr << "[" << level << "] Kill the Fire Demon." << ends;
+  lTitleStr << "[" << level << "] FIRE DEMON";
+  lStr << "[" << level << "] Kill the Fire Demon.";
 }
 
 
@@ -2594,7 +2581,7 @@
 
 
 int KillTheDragon::new_level_check(int enemiesPlaying,WorldP,LocatorP locator,
-                                   int,Boolean &,ostrstream &,Timer &,
+                                   int,Boolean &,stringstream &,Timer &,
                                    IPhysicalManagerP) {
   if (enemiesPlaying == 0) {
     locator->arena_message_enq(Utils::strdup("The Infernal Worm has been vanquished"));
@@ -2614,7 +2601,7 @@
 
 void KillTheDragon::new_level(int level,WorldP w,LocatorP l,
                                  const DifficultyLevel &,
-                                 ostrstream &lStr,ostrstream &lTitleStr,
+                                 stringstream &lStr,stringstream &lTitleStr,
                                  IPhysicalManagerP manager,int) {
   const PhysicalContext *cx = &Dragon::creatureContext.movingContext.physicalContext;
   Pos pos = w->empty_rect(cx->sizeMax);
@@ -2628,8 +2615,8 @@
     manager->create_enemy(p,False);
   }
 
-  lTitleStr << "[" << level << "] Dragon" << ends;
-  lStr << "[" << level << "] Kill the Dragon." << ends;
+  lTitleStr << "[" << level << "] Dragon";
+  lStr << "[" << level << "] Kill the Dragon.";
 }
 
 
@@ -2667,7 +2654,7 @@
 
 
 int ZigZag::new_level_check(int,WorldP world,LocatorP locator,
-                            int,Boolean &,ostrstream &,Timer &,
+                            int,Boolean &,stringstream &,Timer &,
                             IPhysicalManagerP) {
   PhysicalP xit = locator->lookup(xitId);
   assert(xit); // The Xit should never be destroyed.
@@ -2680,7 +2667,7 @@
     HumanP human = locator->get_human(n);
     if (human) {
       // previous depth
-      int depthOld = (int)human->get_data();
+      long depthOld = (long)human->get_data();
       Id id = human->get_id();
 
       // Get physical for intelligence
@@ -2697,9 +2684,9 @@
 	        human->set_data((void *)depth);
 
           // Use 1-based counting for the User.
-	        ostrstream str;
-	        str << "Depth " << (depth + 1) << ends;
-	        locator->arena_message_enq(str.str(),p);
+	        stringstream str;
+	        str << "Depth " << (depth + 1);
+	        locator->arena_message_enq(Utils::strdup(str.str().c_str()),p);
         }
       }
   	}
@@ -2718,7 +2705,7 @@
 
 void ZigZag::new_level(int level,WorldP world,LocatorP locator,
                        const DifficultyLevel &,
-                       ostrstream &lStr,ostrstream &lTitleStr,
+                       stringstream &lStr,stringstream &lTitleStr,
                        IPhysicalManagerP,int) {
   Rooms worldRooms = world->get_rooms();
   RoomIndex upperRight(0,worldRooms.acrossMax - 1);
@@ -2731,9 +2718,8 @@
   xitId = p->get_id();
 
   // 1-based counting of depth for the user.
-  lTitleStr << "[" << level << "] ZIG-ZAG: Depth " 
-		  << worldRooms.downMax << ends;
-  lStr << "[" << level << "] ZIG-ZAG.\nFind the exit." << ends;
+  lTitleStr << "[" << level << "] ZIG-ZAG: Depth " << worldRooms.downMax;
+  lStr << "[" << level << "] ZIG-ZAG.\nFind the exit.";
 }
 
 
@@ -2761,7 +2747,7 @@
 
 
 int ThePound::new_level_check(int enemiesPlaying,WorldP,LocatorP locator,
-                              int,Boolean &,ostrstream &,Timer &,
+                              int,Boolean &,stringstream &,Timer &,
                               IPhysicalManagerP) {
   if (enemiesPlaying == 0) {
     locator->arena_message_enq(Utils::strdup("Killed the Mutts"));
@@ -2781,7 +2767,7 @@
 
 void ThePound::new_level(int level,WorldP,LocatorP locator,
                          const DifficultyLevel &,
-                         ostrstream &lStr,ostrstream &lTitleStr,
+                         stringstream &lStr,stringstream &lTitleStr,
                          IPhysicalManagerP manager,int) {
   locator->add_team(Scenarios::dog_team,NULL);
 
@@ -2789,8 +2775,8 @@
     manager->create_enemy(manager->enemy_physical(A_Dog));
   }
 
-  lTitleStr << "[" << level << "] The Pound" << ends;
-  lStr << "[" << level << "] The Pound" << ends;
+  lTitleStr << "[" << level << "] The Pound";
+  lStr << "[" << level << "] The Pound";
 }
 
 
@@ -2801,7 +2787,7 @@
 
 
 int JapanTown::new_level_check(int enemiesPlaying,WorldP,LocatorP locator,
-                              int,Boolean &,ostrstream &,Timer &,
+                              int,Boolean &,stringstream &,Timer &,
                               IPhysicalManagerP) {
   if (enemiesPlaying == 0) {
     locator->arena_message_enq(Utils::strdup("Damn Ninjas.  Worse than roaches."));
@@ -2821,7 +2807,7 @@
 
 void JapanTown::new_level(int level,WorldP,LocatorP locator,
                          const DifficultyLevel &,
-                         ostrstream &lStr,ostrstream &lTitleStr,
+                         stringstream &lStr,stringstream &lTitleStr,
                          IPhysicalManagerP manager,int) {
   locator->add_team(JapanTown::ninja_team,NULL);
 
@@ -2829,8 +2815,8 @@
     manager->create_enemy(manager->enemy_physical(A_Ninja));
   }
 
-  lTitleStr << "[" << level << "] Japan-Town" << ends;
-  lStr << "[" << level << "] Japan-Town" << ends;
+  lTitleStr << "[" << level << "] Japan-Town";
+  lStr << "[" << level << "] Japan-Town";
 }
 
 
