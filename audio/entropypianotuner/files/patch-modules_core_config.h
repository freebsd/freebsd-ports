--- modules/core/config.h.orig	2026-03-12 21:24:54 UTC
+++ modules/core/config.h
@@ -106,8 +106,13 @@
 #   endif
 #else
 
+/* FreeBSD change enable same as for Linux */
+#define CONFIG_ENABLE_RTMIDI           1
+#define CONFIG_ENABLE_XMGRACE          0
+#define CONFIG_OPTIMIZE_FFT            1
+#define CONFIG_USE_SIMPLE_FILE_DIALOG  0
 
-#error Unknown system
+/* #error Unknown system */
 #endif
 
 
