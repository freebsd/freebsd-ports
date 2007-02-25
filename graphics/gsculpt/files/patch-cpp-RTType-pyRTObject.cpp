--- cpp/RTType/pyRTObject.cpp.orig	Tue Feb 20 16:26:57 2007
+++ cpp/RTType/pyRTObject.cpp	Tue Feb 20 16:27:07 2007
@@ -8,11 +8,12 @@
 #ifndef PYOBJECTPAINTERFACTORY_CPP__
 #define PYOBJECTPAINTERFACTORY_CPP__
 
+#include <boost/python.hpp>
+using namespace boost::python;
+
 #include <RTType/RTType.h>
 
 
-#include <boost/python.hpp>
-using namespace boost::python;
 
 
 
