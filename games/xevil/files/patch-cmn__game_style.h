--- cmn/game_style.h.orig	2012-05-27 06:52:31.000000000 +0900
+++ cmn/game_style.h	2012-05-27 06:53:11.000000000 +0900
@@ -30,12 +30,7 @@
 	#endif
 #endif 
 
-#if X11
-#include <strstream.h>
-#endif
-#if WIN32
-#include <strstrea.h>
-#endif
+#include <sstream>
 
 #include "utils.h"
 #include "coord.h"
@@ -44,6 +39,8 @@
 #include "intel.h"
 
 
+using namespace std;
+
 #define SCENARIO_SEALS_TRAPDOORS 2
 #define SCENARIO_BONUS_FROGS 12
 #define SCENARIO_FLAG_FLAGS 15
@@ -91,7 +88,7 @@
   
   virtual GameStyle *clone() = 0;
   
-  virtual void describe(ostrstream &) = 0;
+  virtual void describe(stringstream &) = 0;
   /* EFFECTS: Write a two-line description of the style to the stream. */
 
   virtual GameStyleType get_type() = 0;
@@ -137,7 +134,7 @@
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
                               int level,
-                              Boolean &lStrChanged,ostrstream &levelStr,
+                              Boolean &lStrChanged,stringstream &levelStr,
                               Timer &timer,
                               IPhysicalManagerP);
   /* MODIFIES: lStrChanged */
@@ -166,7 +163,7 @@
 
   virtual void new_level(int level,WorldP,LocatorP,
                          const DifficultyLevel &dLevel,
-                         ostrstream &levelStr,ostrstream &levelTitleStr,
+                         stringstream &levelStr,stringstream &levelTitleStr,
                          IPhysicalManagerP,int humansNum) = 0;
   /* MODIFIES: level */
   /* EFFECTS: Start a new level.  Use levelStr levelTitleStr to 
@@ -249,7 +246,7 @@
 
   virtual GameStyleP clone();
 
-  virtual void describe(ostrstream &);
+  virtual void describe(stringstream &);
   
   virtual GameStyleType get_type();
 
@@ -269,7 +266,7 @@
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
                               int level,Boolean &lStrChanged,
-                              ostrstream &levelStr,Timer &timer,
+                              stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP);
 
   virtual Boolean advance_level();
@@ -277,7 +274,7 @@
   virtual Boolean award_bonus();
 
   virtual void new_level(int level,WorldP,LocatorP,const DifficultyLevel &dLevel,
-                         ostrstream &levelStr,ostrstream &levelTitleStr,
+                         stringstream &levelStr,stringstream &levelTitleStr,
                          IPhysicalManagerP,int humansNum);
 
   virtual void new_level_set_timer(Timer &timer);
@@ -305,7 +302,7 @@
   
   virtual GameStyleP clone();
 
-  virtual void describe(ostrstream &);
+  virtual void describe(stringstream &);
   
   virtual GameStyleType get_type();
 
@@ -314,11 +311,11 @@
   virtual void reset(WorldP,LocatorP,const DifficultyLevel &,int enemiesNumNext);
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP);
 
   virtual void new_level(int level,WorldP,LocatorP,const DifficultyLevel &dLevel,
-                         ostrstream &levelStr,ostrstream &levelTitleStr,
+                         stringstream &levelStr,stringstream &levelTitleStr,
                          IPhysicalManagerP,int humansNum);
 
   virtual void new_level_set_timer(Timer &timer);
@@ -340,7 +337,7 @@
 
   virtual GameStyleP clone();
 
-  virtual void describe(ostrstream &);
+  virtual void describe(stringstream &);
 
   virtual GameStyleType get_type();
 
@@ -355,7 +352,7 @@
   virtual Boolean game_over_check(int humansPlaying,int enemiesPlaying);
 
   virtual void new_level(int level,WorldP,LocatorP,const DifficultyLevel &dLevel,
-                         ostrstream &levelStr,ostrstream &levelTitleStr,
+                         stringstream &levelStr,stringstream &levelTitleStr,
                          IPhysicalManagerP,int humansNum);
 
   virtual void refill_enemies(Boolean enemiesRefill,WorldP,LocatorP,IPhysicalManagerP);
@@ -376,7 +373,7 @@
   
   virtual GameStyleP clone();
 
-  virtual void describe(ostrstream &);
+  virtual void describe(stringstream &);
 
   virtual GameStyleType get_type();
 
@@ -389,7 +386,7 @@
   virtual Boolean game_over_check(int humansPlaying,int enemiesPlaying);
 
   virtual void new_level(int level,WorldP,LocatorP,const DifficultyLevel &dLevel,
-                         ostrstream &levelStr,ostrstream &levelTitleStr,
+                         stringstream &levelStr,stringstream &levelTitleStr,
                          IPhysicalManagerP,int humansNum);
 
   virtual void refill_enemies(Boolean enemiesRefill,WorldP,LocatorP,IPhysicalManagerP);
@@ -408,7 +405,7 @@
   
   virtual GameStyleP clone();
 
-  virtual void describe(ostrstream &);
+  virtual void describe(stringstream &);
 
   virtual GameStyleType get_type();
 
@@ -423,7 +420,7 @@
   virtual Boolean game_over_check(int humansPlaying,int enemiesPlaying);
 
   virtual void new_level(int level,WorldP,LocatorP,const DifficultyLevel &dLevel,
-                         ostrstream &levelStr,ostrstream &levelTitleStr,
+                         stringstream &levelStr,stringstream &levelTitleStr,
                          IPhysicalManagerP,int humansNum);
 
   virtual void refill_enemies(Boolean enemiesRefill,WorldP,LocatorP,IPhysicalManagerP);
@@ -442,7 +439,7 @@
 
   virtual GameStyleP clone();
 
-  virtual void describe(ostrstream &);
+  virtual void describe(stringstream &);
 
   virtual GameStyleType get_type();
 
@@ -451,7 +448,7 @@
   virtual void reset(WorldP,LocatorP,const DifficultyLevel &dLevel,int);
 
   virtual void new_level(int level,WorldP,LocatorP,const DifficultyLevel &dLevel,
-                         ostrstream &levelStr,ostrstream &levelTitleStr,
+                         stringstream &levelStr,stringstream &levelTitleStr,
                          IPhysicalManagerP,int humansNum);
 
   virtual void refill_enemies(Boolean enemiesRefill,WorldP,LocatorP,IPhysicalManagerP);
@@ -466,7 +463,7 @@
 
   virtual GameStyleP clone();
 
-  virtual void describe(ostrstream &);
+  virtual void describe(stringstream &);
 
   virtual GameStyleType get_type();
 
@@ -485,7 +482,7 @@
   virtual void reset(WorldP,LocatorP,const DifficultyLevel &,int enemiesNumNext);
 
   virtual int new_level_check(int enemiesPlaying,WorldP,LocatorP,
-                              int level,Boolean &lStrChanged,ostrstream &levelStr,Timer &timer,
+                              int level,Boolean &lStrChanged,stringstream &levelStr,Timer &timer,
                               IPhysicalManagerP);
 
   virtual Boolean advance_level();
@@ -493,7 +490,7 @@
   virtual Boolean award_bonus();
 
   virtual void new_level(int level,WorldP,LocatorP,const DifficultyLevel &dLevel,
-                         ostrstream &levelStr,ostrstream &levelTitleStr,
+                         stringstream &levelStr,stringstream &levelTitleStr,
                          IPhysicalManagerP manager,int humansNum);
 
   virtual void new_level_set_timer(Timer &timer);
