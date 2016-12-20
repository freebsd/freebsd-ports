--- openbor.c.orig	2016-12-19 15:29:57 UTC
+++ openbor.c
@@ -5810,7 +5810,7 @@ s_collision_attack **collision_alloc_att
     size_t             alloc_size;
 
     // Get amount of memory we'll need.
-    alloc_size = sizeof(*result);
+    alloc_size = max_collisons * sizeof(*result);
 
     // Allocate memory and get pointer.
     result = malloc(alloc_size);
@@ -5859,7 +5859,7 @@ s_collision_body **collision_alloc_body_
     size_t             alloc_size;
 
     // Get amount of memory we'll need.
-    alloc_size = sizeof(*result);
+    alloc_size = max_collisons * sizeof(*result);
 
     // Allocate memory and get pointer.
     result = malloc(alloc_size);
@@ -20480,7 +20480,7 @@ void common_dot()
     entity     *eOpp;       //Owner of dot effect.
     s_collision_attack    attack;     //Attack struct.
 
-    for(iIndex = 0; iIndex <= MAX_DOTS; iIndex++)                                               //Loop through all DOT indexes.
+    for(iIndex = 0; iIndex < MAX_DOTS; iIndex++)                                               //Loop through all DOT indexes.
     {
         iDot_time   =   self->dot_time[iIndex];                                                 //Get expire time.
         iDot_cnt    =   self->dot_cnt[iIndex];                                                  //Get next tick time.
@@ -34617,7 +34617,7 @@ void keyboard_setup(int player)
     strncpy(buttonnames[SDID_SPECIAL], "Special", 16);
     strncpy(buttonnames[SDID_START], "Start", 16);
     strncpy(buttonnames[SDID_SCREENSHOT], "Screenshot", 16);
-    strncpy(buttonnames[SDID_ESC], "Exit", 16);
+//    strncpy(buttonnames[SDID_ESC], "Exit", 16);
 
     savesettings();
     bothnewkeys = 0;
