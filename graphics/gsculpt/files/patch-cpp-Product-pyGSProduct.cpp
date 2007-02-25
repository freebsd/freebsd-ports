--- cpp/Product/pyGSProduct.cpp.orig	Tue Feb 20 16:24:38 2007
+++ cpp/Product/pyGSProduct.cpp	Tue Feb 20 16:24:49 2007
@@ -8,11 +8,12 @@
 #ifndef PYGSPRODUCT_CPP__
 #define PYGSPRODUCT_CPP__
 
+#include <boost/python.hpp>
+using namespace boost::python;
+
 #include <Product/GSProduct.h>
 
 
-#include <boost/python.hpp>
-using namespace boost::python;
 
 
 
