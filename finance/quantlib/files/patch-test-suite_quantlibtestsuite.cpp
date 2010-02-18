--- test-suite/quantlibtestsuite.cpp.orig	2010-02-17 19:23:25.000000000 +0900
+++ test-suite/quantlibtestsuite.cpp	2010-02-17 19:24:06.000000000 +0900
@@ -18,6 +18,9 @@
  FOR A PARTICULAR PURPOSE.  See the license for more details.
 */
 
+#define BOOST_TEST_DYN_LINK
+#define BOOST_TEST_MAIN
+
 #include <ql/types.hpp>
 #include <ql/settings.hpp>
 #include <ql/version.hpp>
