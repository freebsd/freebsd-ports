--- test-suite/quantlibtestsuite.cpp.orig	Mon Jul  9 08:35:31 2007
+++ test-suite/quantlibtestsuite.cpp	Mon Jul  9 08:36:10 2007
@@ -18,6 +18,9 @@
  FOR A PARTICULAR PURPOSE.  See the license for more details.
 */
 
+#define BOOST_TEST_DYN_LINK
+#define BOOST_TEST_MAIN
+
 #include <ql/types.hpp>
 #include <boost/test/unit_test.hpp>
 #include <boost/timer.hpp>
