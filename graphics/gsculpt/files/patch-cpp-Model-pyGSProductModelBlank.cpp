--- cpp/Model/pyGSProductModelBlank.cpp.orig	Tue Feb 20 16:17:02 2007
+++ cpp/Model/pyGSProductModelBlank.cpp	Tue Feb 20 16:17:43 2007
@@ -8,13 +8,14 @@
 #ifndef PYGSPRODUCTMODELBLANK_CPP__
 #define PYGSPRODUCTMODELBLANK_CPP__
 
+#include <boost/python.hpp>
+using namespace boost::python;
+
 #include <Product/GSProduct.h>
 
 #include <Model/GSProductModelBlank.h>
 
 
-#include <boost/python.hpp>
-using namespace boost::python;
 
 
 
