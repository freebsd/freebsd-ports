--- runtime/flang/stime3f.c.orig	2017-05-17 00:40:01 UTC
+++ runtime/flang/stime3f.c
@@ -27,13 +27,7 @@
 
 int ENT3F(STIME, stime)(int *tp)
 {
-  int i;
-  time_t t = *tp;
-
-  if ((i = stime(&t)))
-    i = __io_errno();
-
-  return i;
+  return EPERM;
 }
 
 #endif /* !WINNT */
