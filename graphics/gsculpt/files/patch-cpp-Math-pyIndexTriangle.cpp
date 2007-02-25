--- cpp/Math/pyIndexTriangle.cpp.orig	Mon Jan  1 17:49:08 2007
+++ cpp/Math/pyIndexTriangle.cpp	Tue Feb 20 13:56:21 2007
@@ -8,10 +8,10 @@
 #ifndef PYINDEXTRIANGLE_CPP
 #define PYINDEXTRIANGLE_CPP
 
-#include <Math/IndexTriangle.h>
-
 #include <boost/python.hpp>
 using namespace boost::python;
+
+#include <Math/IndexTriangle.h>
 
 
 void export_IndexTriangle()
