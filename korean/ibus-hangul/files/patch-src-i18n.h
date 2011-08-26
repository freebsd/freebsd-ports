--- src/i18n.h.orig	2009-10-31 02:59:39.000000000 -0400
+++ src/i18n.h	2011-08-25 19:58:34.000000000 -0400
@@ -3,9 +3,18 @@
 #ifndef ibus_hangul_i18n_h
 #define ibus_hangul_i18n_h
 
+#ifdef ENABLE_NLS
+
 #include <libintl.h>
 
 #define _(str)	    gettext(str)
 #define N_(str)	    (str)
 
+#else /* ENABLE_NLS */
+
+#define _(str)	    (str)
+#define N_(str)	    str
+
+#endif /* ENABLE_NLS */
+
 #endif /* ibus_hangul_i18n_h */
