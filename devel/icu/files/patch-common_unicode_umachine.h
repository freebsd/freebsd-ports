--- common/unicode/umachine.h.orig	2017-03-16 19:01:12 UTC
+++ common/unicode/umachine.h
@@ -295,7 +295,7 @@ typedef int8_t UBool;
  * If 1, then char16_t is a typedef and not a real type (yet)
  * @internal
  */
-#if (U_PLATFORM == U_PF_AIX) && defined(__cplusplus) &&(U_CPLUSPLUS_VERSION < 11)
+#if defined(__cplusplus) && (U_CPLUSPLUS_VERSION < 11)
 // for AIX, uchar.h needs to be included
 # include <uchar.h>
 # define U_CHAR16_IS_TYPEDEF 1
