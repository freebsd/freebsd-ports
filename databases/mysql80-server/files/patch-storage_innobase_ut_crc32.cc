--- storage/innobase/ut/crc32.cc.orig	2018-08-12 11:09:52 UTC
+++ storage/innobase/ut/crc32.cc
@@ -108,7 +108,7 @@ external tools. */
 */
 #if defined(__SSE4_2__) || defined(__clang__) || !defined(__GNUC__) || \
     __GNUC__ >= 5 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 9)
-#include <nmmintrin.h>
+#include <x86intrin.h>
 #else
 // GCC 4.8 without -msse4.2.
 MY_ATTRIBUTE((target("sse4.2")))
