--- uta/blitters.cc.orig	Wed May 14 05:23:15 2003
+++ uta/blitters.cc	Wed May 14 15:39:28 2003
@@ -28,6 +28,8 @@
 #endif
 #if !defined(X86_ASSEMBLER)
 
+using namespace std;
+
 /** Apply const gamma value.
     Blit just copies alpha value of the source to the destination surface.
  */
