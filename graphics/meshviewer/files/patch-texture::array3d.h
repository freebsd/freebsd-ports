--- texture/array3d.h.orig	Sun Nov  9 21:13:01 2003
+++ texture/array3d.h	Fri Aug 27 12:53:54 2004
@@ -16,6 +16,7 @@
 
   Array3D()
     {
+      int x, y, z;
       x=y=z=0;
       data=NULL;
     }
