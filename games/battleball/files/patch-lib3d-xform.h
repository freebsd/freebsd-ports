--- lib3d/xform.h.orig	Fri Jul 18 17:28:08 2003
+++ lib3d/xform.h	Fri Jul 18 17:26:11 2003
@@ -64,6 +64,7 @@
 
 //===========================================================================
 class tmtrx {
+  friend struct player;
   typedef double fourby3[4][3];
   fourby3 m;
 
