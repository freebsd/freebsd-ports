Reduce namespace pollution from #undef BOOST_TEST_DYN_LINK after
https://github.com/boostorg/test/commit/86bcffea6dfb

--- libs/mime/test/mime-roundtrip.cpp.orig	2015-08-27 05:04:59 UTC
+++ libs/mime/test/mime-roundtrip.cpp
@@ -16,7 +16,7 @@
 #ifdef BOOST_TEST_DYN_LINK
 #define BOOST_TEST_ALTERNATIVE_INIT_API
 #endif
-#include <boost/test/included/unit_test.hpp>
+#include <boost/test/unit_test.hpp>
 
 #include <fstream>
 #include <iostream>
