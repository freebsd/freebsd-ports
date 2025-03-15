- workaorund for https://github.com/apache/arrow/issues/45803

--- src/arrow/testing/process.cc.orig	2025-03-15 05:43:36 UTC
+++ src/arrow/testing/process.cc
@@ -33,6 +33,7 @@
 #  include <boost/asio/io_context.hpp>
 
 #  ifdef BOOST_PROCESS_USE_V2
+#undef BOOST_PROCESS_NEED_SOURCE
 #    ifdef BOOST_PROCESS_NEED_SOURCE
 // Workaround for https://github.com/boostorg/process/issues/312
 #      define BOOST_PROCESS_V2_SEPARATE_COMPILATION
