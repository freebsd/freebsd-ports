--- src/SDCCralloc.hpp.orig	2015-02-25 10:25:50 UTC
+++ src/SDCCralloc.hpp
@@ -51,6 +51,12 @@
 #include <sstream>
 #include <fstream>
 
+// Workaround for boost bug #11880
+#include <boost/version.hpp>
+#if BOOST_VERSION == 106000
+	#include <boost/type_traits/ice.hpp>
+#endif
+
 #include <boost/graph/graphviz.hpp>
 #include <boost/graph/adjacency_matrix.hpp>
 #include <boost/graph/connected_components.hpp>
