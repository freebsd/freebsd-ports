Fix potential crashes found by ASan/Clang/GCC
Fix an infinite loop in lcmScriptDeleteMain()

--- openbor.c.orig	2018-07-06 15:13:16 UTC
+++ openbor.c
@@ -6259,17 +6259,17 @@ s_collision_attack *collision_alloc_attack_instance(s_
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
@@ -6308,17 +6308,17 @@ s_collision_body *collision_alloc_body_instance(s_coll
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
@@ -8743,7 +8743,8 @@ size_t lcmScriptCopyBuffer(ArgList *arglist, char *buf
 
 size_t lcmScriptDeleteMain(char **buf)
 {
-    size_t len = 0, i = 0;
+    size_t len = 0;
+    long i = 0;
     ptrdiff_t pos = 0;
     char *newbuf = NULL;
 
@@ -15920,6 +15921,11 @@ void bar(int x, int y, int value, int maxvalue, s_bars
     else
     {
         return;
+    }
+
+    if (value < 0)
+    {
+        value = 0;
     }
 
     if (value > maxvalue)
