--- src/liborcus/dom_tree.cpp.orig	2012-11-28 07:21:10.000000000 -0500
+++ src/liborcus/dom_tree.cpp	2013-02-19 16:17:53.000000000 -0500
@@ -34,6 +34,8 @@
 #include <iostream>
 #include <sstream>
 
+#include <boost/noncopyable.hpp>
+
 using namespace std;
 
 namespace orcus {
