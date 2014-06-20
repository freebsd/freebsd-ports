--- src/filter/pfspanoramic.cpp.orig	2010-02-18 11:27:03.000000000 +0000
+++ src/filter/pfspanoramic.cpp	2014-02-20 19:04:01.556587853 +0000
@@ -93,7 +93,7 @@
   }
 
   //TODO: optimize rotations by precomputing sines and cosines
-  Vector3D rotateX(double angle)
+  void rotateX(double angle)
   {
     angle *= (M_PI / 180);
 
@@ -107,7 +107,7 @@
     z = z2;
   }
 
-  Vector3D rotateY(double angle)
+  void rotateY(double angle)
   {
     angle *= (M_PI / 180);
 
@@ -121,7 +121,7 @@
     z = z2;
   }
 
-  Vector3D rotateZ(double angle)
+  void rotateZ(double angle)
   {
     angle *= (M_PI / 180);
 
@@ -195,7 +195,7 @@
     {
       char *opts;
       
-      if(opts = strchr(name, '/'))
+      if ((opts = strchr(name, '/')))
       {
         *opts++ = '\0';
       }
