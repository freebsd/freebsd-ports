--- src/filter/pfspanoramic.cpp.orig	2010-02-18 11:27:03 UTC
+++ src/filter/pfspanoramic.cpp
@@ -93,7 +93,7 @@ class Vector3D
   }
 
   //TODO: optimize rotations by precomputing sines and cosines
-  Vector3D rotateX(double angle)
+  void rotateX(double angle)
   {
     angle *= (M_PI / 180);
 
@@ -107,7 +107,7 @@ class Vector3D
     z = z2;
   }
 
-  Vector3D rotateY(double angle)
+  void rotateY(double angle)
   {
     angle *= (M_PI / 180);
 
@@ -121,7 +121,7 @@ class Vector3D
     z = z2;
   }
 
-  Vector3D rotateZ(double angle)
+  void rotateZ(double angle)
   {
     angle *= (M_PI / 180);
 
@@ -195,7 +195,7 @@ class ProjectionFactory
     {
       char *opts;
       
-      if(opts = strchr(name, '/'))
+      if ((opts = strchr(name, '/')))
       {
         *opts++ = '\0';
       }
