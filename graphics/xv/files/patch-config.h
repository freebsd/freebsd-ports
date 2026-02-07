--- src/config.h.orig	2023-07-17 01:25:42 UTC
+++ src/config.h
@@ -191,7 +191,7 @@
  * in the following line.
  */
 
-#undef MACBINARY
+#define MACBINARY
 
 
 /***************************************************************************
@@ -207,8 +207,8 @@
  * is read-only), change 'undef' to 'define' the VIRTUAL_TD line.
  */
 
-#undef AUTO_EXPAND
-#undef VIRTUAL_TD
+#define AUTO_EXPAND
+#define VIRTUAL_TD
 
 #if defined(VIRTUAL_TD) && !defined(AUTO_EXPAND)
 #  undef VIRTUAL_TD
@@ -291,7 +291,7 @@
  * magic number or suffix in "~/.xv_mgcsfx" .
  * To enable this feature, change 'undef' to 'define' in the following line.
  */
-#undef HAVE_MGCSFX
+#define HAVE_MGCSFX
 
 #ifdef HAVE_MGCSFX
 /*
@@ -352,7 +352,7 @@
  * 'undef' to 'define' in the following line.
  */
 
-#undef TV_MULTILINGUAL
+/* #undef TV_MULTILINGUAL */
 
 #define TV_DEFAULT_CODESET TV_EUC_JAPAN
 
