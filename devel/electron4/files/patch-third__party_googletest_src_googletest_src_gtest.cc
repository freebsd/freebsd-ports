--- third_party/googletest/src/googletest/src/gtest.cc.orig	2019-03-15 06:40:20 UTC
+++ third_party/googletest/src/googletest/src/gtest.cc
@@ -128,6 +128,7 @@
 
 #if GTEST_CAN_STREAM_RESULTS_
 # include <arpa/inet.h>  // NOLINT
+# include <sys/socket.h> // NOLINT
 # include <netdb.h>  // NOLINT
 # include <sys/socket.h>  // NOLINT
 # include <sys/types.h>  // NOLINT
