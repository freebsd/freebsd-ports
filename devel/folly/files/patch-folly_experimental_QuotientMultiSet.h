--- folly/experimental/QuotientMultiSet.h.orig	2021-03-06 00:00:24 UTC
+++ folly/experimental/QuotientMultiSet.h
@@ -26,7 +26,9 @@
 #include <folly/io/IOBufQueue.h>
 
 // A 128-bit integer type is needed for fast division.
+#ifndef FOLLY_QUOTIENT_MULTI_SET_SUPPORTED
 #define FOLLY_QUOTIENT_MULTI_SET_SUPPORTED FOLLY_HAVE_INT128_T
+#endif
 
 #if FOLLY_QUOTIENT_MULTI_SET_SUPPORTED
 
