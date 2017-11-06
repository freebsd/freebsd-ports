--- common/unicode/uvernum.h.orig	2017-03-21 01:03:49 UTC
+++ common/unicode/uvernum.h
@@ -125,4 +125,4 @@
  *  This value will change in the subsequent releases of ICU
  *  @stable ICU 2.6
  */
-#if U_PLATFORM_HAS_WINUWP_API == 0
+#ifndef U_PLATFORM_HAS_WINUWP_API
