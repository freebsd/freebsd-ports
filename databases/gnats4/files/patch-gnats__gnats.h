--- gnats/gnats.h.orig	2013-06-10 10:33:17.000000000 +0300
+++ gnats/gnats.h	2013-06-10 10:33:26.000000000 +0300
@@ -137,9 +137,6 @@
 # define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
 #endif
 
-extern int asprintf (char **buf, const char *fmt, ...);
-extern int vasprintf (char **buf, const char *fmt, va_list args);
-
 #if ! HAVE_DECL_UNSETENV
 extern void unsetenv (const char *name);
 #endif
