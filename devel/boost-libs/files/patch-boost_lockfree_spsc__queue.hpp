https://github.com/boostorg/lockfree/commit/12726cda009a

--- boost/lockfree/spsc_queue.hpp.orig	2018-04-11 13:49:04 UTC
+++ boost/lockfree/spsc_queue.hpp
@@ -17,6 +17,7 @@
 #include <boost/assert.hpp>
 #include <boost/static_assert.hpp>
 #include <boost/utility.hpp>
+#include <boost/next_prior.hpp>
 #include <boost/utility/enable_if.hpp>
 #include <boost/config.hpp> // for BOOST_LIKELY
 
