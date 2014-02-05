--- main.cpp.orig	2014-02-05 10:21:41.000000000 +0100
+++ main.cpp	2014-02-05 10:22:16.000000000 +0100
@@ -58,6 +58,10 @@
 
   initsound(&argc, argv);
 
+  /* initialize glut here, so we have 
+   * access to argv and argc */
+  glutInit (&argc, argv);
+
   DoInitializations();
 
   playsound(NewLifeSound);
