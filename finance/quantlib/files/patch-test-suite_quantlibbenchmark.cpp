--- test-suite/quantlibbenchmark.cpp.orig	2010-02-17 20:58:39.000000000 +0900
+++ test-suite/quantlibbenchmark.cpp	2010-02-17 20:59:32.000000000 +0900
@@ -64,6 +64,9 @@
   copyrights therein.
 */
 
+#define BOOST_TEST_DYN_LINK
+#define BOOST_TEST_MAIN
+
 #include <ql/types.hpp>
 #include <ql/version.hpp>
 #include <boost/test/unit_test.hpp>
