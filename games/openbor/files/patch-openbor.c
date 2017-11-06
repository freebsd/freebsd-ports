Fix potential crashes found by ASan/Clang/GCC
Fix an infinite loop in lcmScriptDeleteMain()
Avoid accidental rounding from abs()

--- openbor.c.orig	2017-04-22 14:20:08 UTC
+++ openbor.c
@@ -5747,17 +5747,17 @@ s_collision_attack *collision_alloc_attack_instance(s_
 //
 // Allocate an empty collision attack list.
 s_collision_attack **collision_alloc_attack_list()
 {
     s_collision_attack **result;
     size_t             alloc_size;
 
     // Get amount of memory we'll need.
-    alloc_size = sizeof(*result);
+    alloc_size = max_collisons * sizeof(*result);
 
     // Allocate memory and get pointer.
     result = malloc(alloc_size);
 
     // Make sure the list is blank.
     memset(result, 0, alloc_size);
 
     // return result.
@@ -5796,17 +5796,17 @@ s_collision_body *collision_alloc_body_instance(s_coll
 //
 // Allocate an empty collision attack list.
 s_collision_body **collision_alloc_body_list()
 {
     s_collision_body **result;
     size_t             alloc_size;
 
     // Get amount of memory we'll need.
-    alloc_size = sizeof(*result);
+    alloc_size = max_collisons * sizeof(*result);
 
     // Allocate memory and get pointer.
     result = malloc(alloc_size);
 
     // Make sure the list is blank.
     memset(result, 0, alloc_size);
 
     // return result.
@@ -8204,7 +8204,8 @@ size_t lcmScriptCopyBuffer(ArgList *argl
 
 size_t lcmScriptDeleteMain(char **buf)
 {
-    size_t len = 0, i = 0;
+    size_t len = 0;
+    long i = 0;
     ptrdiff_t pos = 0;
     char *newbuf = NULL;
 
@@ -15210,6 +15210,11 @@ void bar(int x, int y, int value, int ma
         return;
     }
 
+    if (value < 0)
+    {
+        value = 0;
+    }
+
     if (value > maxvalue)
     {
         value = maxvalue;
@@ -21710,8 +21716,8 @@ int reset_backpain(entity *ent)
         if (ent->normaldamageflipdir == DIRECTION_RIGHT) ent->direction = DIRECTION_RIGHT;
         else ent->direction = DIRECTION_LEFT;
 
-        if(ent->direction == DIRECTION_RIGHT) ent->velocity.x = -1*abs(ent->velocity.x);
-        else ent->velocity.x = abs(ent->velocity.x);
+        if(ent->direction == DIRECTION_RIGHT) ent->velocity.x = -1*ABS(ent->velocity.x);
+        else ent->velocity.x = ABS(ent->velocity.x);
 
         return 1;
     }
@@ -25831,7 +25837,7 @@ int common_try_wander(entity *target, in
         mod = -mod;
     }
     //if ((self->sortid / 100) % 2)
-    if (abs(rand32()) % 2)
+    if (rand32() % 2)
     {
         mod = 3 - mod;
     }
