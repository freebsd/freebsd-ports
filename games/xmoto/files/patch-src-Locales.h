--- src/Locales.h.orig	Tue Sep 19 05:51:55 2006
+++ src/Locales.h	Tue Sep 19 05:55:02 2006
@@ -22,6 +22,8 @@
 #ifndef __LOCALES_H__
 #define __LOCALES_H__
 
+#include "BuildConfig.h"
+
 #ifndef USE_GETTEXT
 #define _(a) a
 #else
