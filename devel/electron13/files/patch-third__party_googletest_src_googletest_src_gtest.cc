--- third_party/googletest/src/googletest/src/gtest.cc.orig	2021-07-15 19:15:45 UTC
+++ third_party/googletest/src/googletest/src/gtest.cc
@@ -110,6 +110,7 @@
 
 #if GTEST_CAN_STREAM_RESULTS_
 # include <arpa/inet.h>  // NOLINT
+# include <sys/socket.h> // NOLINT
 # include <netdb.h>  // NOLINT
 # include <sys/socket.h>  // NOLINT
 # include <sys/types.h>  // NOLINT
