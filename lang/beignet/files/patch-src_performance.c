--- src/performance.c.orig	2015-08-26 11:58:45.989699000 +0200
+++ src/performance.c	2015-08-26 11:59:40.117247000 +0200
@@ -37,7 +37,6 @@ typedef struct storage
 
 
 static storage record;
-static int atexit_registered = 0;
 
 
 static context_storage_node * prev_context_pointer = NULL;
@@ -170,6 +169,7 @@ static int cmp(const void *a, const void
     return 0;
 }
 
+__attribute__((destructor))
 static void print_time_info()
 {
   context_storage_node *p_context = record.context_storage;
@@ -273,11 +273,6 @@ static void print_time_info()
 
 static void insert(cl_context context, const char *kernel_name, const char *build_opt, float time)
 {
-  if(!atexit_registered)
-  {
-    atexit_registered = 1;
-    atexit(print_time_info);
-  }
   context_storage_node *p_context = find_context(context);
   kernel_storage_node *p_kernel = find_kernel(p_context, kernel_name, build_opt);
   prev_context_pointer = p_context;
