--- src/tests/main.cpp~
+++ src/tests/main.cpp
@@ -15,6 +15,7 @@
 #define GETTEXT_DOMAIN "wesnoth-test"
 
 
+#define BOOST_TEST_DYN_LINK
 #define BOOST_TEST_MODULE wesnoth unit tests master suite
 #include <boost/test/unit_test.hpp>
 #include <boost/test/unit_test_monitor.hpp>
