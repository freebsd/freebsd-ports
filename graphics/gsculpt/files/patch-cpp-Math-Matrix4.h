--- cpp/Math/Matrix4.h.orig	Sat Mar  3 10:31:14 2007
+++ cpp/Math/Matrix4.h	Sat Apr 14 02:21:26 2007
@@ -21,7 +21,6 @@
 #ifndef MATRIX4_H__
 #define MATRIX4_H__
 
-#include <boost/python.hpp>
 
 
 
@@ -50,6 +49,7 @@
 #include <Math/Triangle2.h>
 #include <Math/Triangle3.h>
 #include <Math/epsilon.h>
+#include <boost/python.hpp>
 
 //a selection of macros to make acessing the members of the matrix easy
 #define iMA d[0]
