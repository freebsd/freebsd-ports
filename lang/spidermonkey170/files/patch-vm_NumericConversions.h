--- vm/NumericConversions.h.orig	2016-12-23 10:40:02 UTC
+++ vm/NumericConversions.h
@@ -154,7 +154,7 @@ ToIntWidth(double d)
 inline int32_t
 ToInt32(double d)
 {
-#if defined (__arm__) && defined (__GNUC__)
+#if defined (__arm__) && defined (__GNUC__)  && !defined(__clang__)
     int32_t i;
     uint32_t    tmp0;
     uint32_t    tmp1;
