--- src/cwutils/i18n.h.orig	2018-08-07 18:50:31 UTC
+++ src/cwutils/i18n.h
@@ -20,7 +20,7 @@
 #ifndef _CWI18N_H
 #define _CWI18N_H
 
-#if defined(HAVE_LIBINTL_H)
+#if defined(HAVE_GETTEXT)
 # include <libintl.h>
 
 # define _(STR) i18n_gettext (STR)
