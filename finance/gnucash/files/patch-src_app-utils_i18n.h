--- src/app-utils/i18n.h.orig	Fri Feb 14 12:35:54 2003
+++ src/app-utils/i18n.h	Fri Feb 14 12:36:07 2003
@@ -26,4 +26,4 @@
 #endif
 
 #define TEXT_DOMAIN		"gnucash"
-#define LOCALE_DIR		"/usr/local/share/locale"
+#define LOCALE_DIR		"%%PREFIX%%/share/locale"
