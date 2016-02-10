--- src/SDCCnaddr.hpp.orig	2015-04-01 13:50:35 UTC
+++ src/SDCCnaddr.hpp
@@ -37,6 +37,12 @@
 #include <sstream>
 #include <fstream>
 
+// Workaround for boost bug #11880
+#include <boost/version.hpp>
+#if BOOST_VERSION == 106000
+	#include <boost/type_traits/ice.hpp>
+#endif
+
 #include <boost/graph/graphviz.hpp>
 
 #include "SDCCtree_dec.hpp"
