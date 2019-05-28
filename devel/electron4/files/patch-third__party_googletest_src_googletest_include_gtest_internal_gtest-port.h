--- third_party/googletest/src/googletest/include/gtest/internal/gtest-port.h.orig	2019-03-15 06:40:20 UTC
+++ third_party/googletest/src/googletest/include/gtest/internal/gtest-port.h
@@ -841,7 +841,7 @@ typedef struct _RTL_CRITICAL_SECTION GTEST_CRITICAL_SE
     (GTEST_OS_WINDOWS || GTEST_OS_CYGWIN || GTEST_OS_SYMBIAN || GTEST_OS_AIX)
 
 // Determines whether test results can be streamed to a socket.
-#if GTEST_OS_LINUX
+#if GTEST_OS_LINUX || GTEST_OS_FREEBSD
 # define GTEST_CAN_STREAM_RESULTS_ 1
 #endif
 
