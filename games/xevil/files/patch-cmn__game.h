--- cmn/game.h.orig	2012-05-27 06:52:31.000000000 +0900
+++ cmn/game.h	2012-05-27 06:53:11.000000000 +0900
@@ -35,7 +35,7 @@
 extern "C" {
 #include <time.h>
 }
-#include <iostream.h>
+#include <iostream>
 #include "utils.h"
 #include "ui.h"
 #include "world.h"
@@ -136,7 +136,7 @@
 struct RankingSet {
   enum {RANKING_SET_MAX = 8}; // Max number of rankings in a set.
   int killsMin; // Min number of kills to get this rank.
-  char *rankings[RANKING_SET_MAX + 1]; // Extra for NULL.
+  const char *rankings[RANKING_SET_MAX + 1]; // Extra for NULL.
 };
 
 
@@ -268,8 +268,8 @@
   
 private:
   enum { 
-    WITTY_SAYINGS_NUM = 147,
-    INTEL_NAMES_NUM  = 74,
+    WITTY_SAYINGS_NUM = 155,
+    INTEL_NAMES_NUM  = 77,
     RANKING_SETS_NUM = 12,
   };
 
@@ -306,7 +306,7 @@
   static Boolean potential_enemy_filter(const PhysicalContext* pc,void*);
   /* EFFECTS: Filter those classes whose potentialEnemy flag is True. */
 
-  char *choose_ranking(int kills);
+  const char *choose_ranking(int kills);
   /* EFFECTS: Choose a rank for the player at the end of game based on the
      number of kills. */
   
@@ -412,8 +412,8 @@
   SoundName currentSoundName;
   //keeps track of current sound track being played: can be 0
 
-  static char *wittySayings[WITTY_SAYINGS_NUM];
-  static char *intelNames[INTEL_NAMES_NUM];
+  static const char *wittySayings[WITTY_SAYINGS_NUM];
+  static const char *intelNames[INTEL_NAMES_NUM];
   static DifficultyLevel difficultyLevels[DIFFICULTY_LEVELS_NUM];
   static RankingSet rankingSets[RANKING_SETS_NUM];
 
