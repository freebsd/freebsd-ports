--- cpp/Util/pySETree.cpp.orig	Tue Feb 20 16:34:38 2007
+++ cpp/Util/pySETree.cpp	Tue Feb 20 16:34:47 2007
@@ -8,11 +8,12 @@
 #ifndef PYSETREE_CPP__
 #define PYSETREE_CPP__
 
+#include <boost/python.hpp>
+using namespace boost::python;
+
 #include <Util/SETree.h>
 
 
-#include <boost/python.hpp>
-using namespace boost::python;
 
 
 
