--- src/SDCClospre.hpp.orig	2014-01-03 17:18:45 UTC
+++ src/SDCClospre.hpp
@@ -19,6 +19,12 @@
 //
 // Lifetime-optimal speculative partial redundancy elimination.
 
+// Workaround for boost bug #11880
+#include <boost/version.hpp>
+#if BOOST_VERSION == 106000
+	#include <boost/type_traits/ice.hpp>
+#endif
+
 #include <boost/graph/graphviz.hpp>
 #include <boost/tuple/tuple.hpp>
 #include <boost/tuple/tuple_comparison.hpp>
