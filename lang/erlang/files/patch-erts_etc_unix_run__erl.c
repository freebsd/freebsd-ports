
$FreeBSD$

--- erts/etc/unix/run_erl.c.orig
+++ erts/etc/unix/run_erl.c
@@ -738,7 +738,7 @@
  */
 static int create_fifo(char *name, int perm)
 {
-  if ((mknod(name, S_IFIFO | perm, 0) < 0) && (errno != EEXIST))
+  if ((mkfifo(name, perm) < 0) && (errno != EEXIST))
     return -1;
   return 0;
 }
