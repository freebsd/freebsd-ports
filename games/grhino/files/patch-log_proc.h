--- log_proc.h.orig	Fri Apr 15 23:03:04 2005
+++ log_proc.h	Fri Apr 29 15:36:28 2005
@@ -39,6 +39,7 @@
 #undef N_
 #endif
 
+#define _INTL_REDIRECT_MACROS
 #include <libintl.h>
 #define _(x) gettext(x)
 #define N_(x) x
