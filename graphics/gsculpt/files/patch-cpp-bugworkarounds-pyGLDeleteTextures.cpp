--- cpp/bugworkarounds/pyGLDeleteTextures/pyGLDeleteTextures.cpp.orig	Tue Feb 20 16:39:18 2007
+++ cpp/bugworkarounds/pyGLDeleteTextures.cpp	Tue Feb 20 16:38:58 2007
@@ -8,13 +8,14 @@
 #ifndef PYGLDELETETEXTURES_CPP__
 #define PYGLDELETETEXTURES_CPP__
 
+#include <boost/python.hpp>
+using namespace boost::python;
+
 #include <PlatformSpecific/IncludeGL.h>
 
 #include <Util/Array.h>
 
 
-#include <boost/python.hpp>
-using namespace boost::python;
 
 
 
