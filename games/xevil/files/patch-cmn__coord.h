--- cmn/coord.h.orig	2012-05-27 06:52:31.000000000 +0900
+++ cmn/coord.h	2012-05-27 06:53:11.000000000 +0900
@@ -619,7 +619,7 @@
   int enemiesInitial; // enemies on first level
   int enemiesIncr; // this many more enemies each level
   int enemiesMax; // maximum number of enemies (for levels)
-  char *name; // of this difficulty level
+  const char *name; // of this difficulty level
 };
 enum {DIFF_TRIVIAL,DIFF_NORMAL,DIFF_HARD,DIFF_BEND_OVER,
       DIFFICULTY_LEVELS_NUM, DIFF_NONE=DIFFICULTY_LEVELS_NUM};
