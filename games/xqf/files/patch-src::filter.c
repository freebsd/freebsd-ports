--- src/filter.c.orig	Mon Aug  2 00:03:17 2004
+++ src/filter.c	Mon Aug 16 21:41:39 2004
@@ -2140,8 +2140,9 @@
   if(!filter_current_time)
   {
     struct server* s;
+    GSList* list;
     printf("CONGRATULATION! You managed to filter more than %u times\n", UINT_MAX);
-    GSList* list = all_servers();
+    list = all_servers();
     for(;list; list = list->next)
     {
       s = (struct server *) list->data;
