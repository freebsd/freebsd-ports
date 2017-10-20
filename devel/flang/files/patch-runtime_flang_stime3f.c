--- runtime/flang/stime3f.c.orig	2017-10-19 11:03:03 UTC
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
