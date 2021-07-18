--- universe/Conditions.cpp.orig	2020-09-25 11:06:39 UTC
+++ universe/Conditions.cpp
@@ -32,6 +32,8 @@
 #include <boost/graph/adjacency_list.hpp>
 #include <boost/graph/st_connected.hpp>
 
+#include <cfloat>  // for FLT_MAX
+
 
 using boost::io::str;
 
