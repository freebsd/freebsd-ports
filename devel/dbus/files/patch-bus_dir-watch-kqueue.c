--- bus/dir-watch-kqueue.c.orig	2010-04-04 17:59:18.000000000 -0400
+++ bus/dir-watch-kqueue.c	2010-04-04 17:59:55.000000000 -0400
@@ -169,7 +169,7 @@ bus_set_watched_dirs (BusContext *contex
    */
   for (i = 0; new_dirs[i]; i++)
     {
-      for (j = 0; i < num_fds; j++)
+      for (j = 0; j < num_fds; j++)
         {
           if (dirs[j] && strcmp (new_dirs[i], dirs[j]) == 0)
             {
