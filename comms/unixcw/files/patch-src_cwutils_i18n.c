--- src/cwutils/i18n.c.orig	2018-08-07 18:50:26 UTC
+++ src/cwutils/i18n.c
@@ -50,7 +50,7 @@ i18n_initialize (void)
 const char *
 i18n_gettext (const char *msgid)
 {
-#if defined(HAVE_LIBINTL_H)
+#if defined(HAVE_GETTEXT)
   static int is_initialized = FALSE;
 
   if (!is_initialized)
