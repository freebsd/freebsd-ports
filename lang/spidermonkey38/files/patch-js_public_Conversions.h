https://hg.mozilla.org/mozilla-central/rev/bd25b06261c8

--- ../../js/public/Conversions.h.orig	2017-06-05 21:05:02.575788000 +0200
+++ ../../js/public/Conversions.h	2017-06-05 21:06:42.668207000 +0200
@@ -349,7 +349,9 @@ ToIntWidth(double d)
 inline int32_t
 ToInt32(double d)
 {
-#if defined (__arm__) && defined (__GNUC__)
+// clang crashes compiling this when targeting arm:
+// https://llvm.org/bugs/show_bug.cgi?id=22974
+#if defined (__arm__) && defined (__GNUC__) && !defined(__clang__)
     int32_t i;
     uint32_t    tmp0;
     uint32_t    tmp1;
