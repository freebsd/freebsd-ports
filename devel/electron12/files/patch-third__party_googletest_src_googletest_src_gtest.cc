--- third_party/googletest/src/googletest/src/gtest.cc.orig	2021-01-07 00:39:29 UTC
+++ third_party/googletest/src/googletest/src/gtest.cc
@@ -117,6 +117,7 @@
 
 #if GTEST_CAN_STREAM_RESULTS_
 # include <arpa/inet.h>  // NOLINT
+# include <sys/socket.h> // NOLINT
 # include <netdb.h>  // NOLINT
 # include <sys/socket.h>  // NOLINT
 # include <sys/types.h>  // NOLINT
