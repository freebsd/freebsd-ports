--- third_party/googletest/src/googletest/src/gtest.cc.orig	2020-05-26 08:04:00 UTC
+++ third_party/googletest/src/googletest/src/gtest.cc
@@ -118,6 +118,7 @@
 
 #if GTEST_CAN_STREAM_RESULTS_
 # include <arpa/inet.h>  // NOLINT
+# include <sys/socket.h> // NOLINT
 # include <netdb.h>  // NOLINT
 # include <sys/socket.h>  // NOLINT
 # include <sys/types.h>  // NOLINT
