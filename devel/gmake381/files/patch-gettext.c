
$FreeBSD$

--- gettext.c	2002/06/06 22:10:23	1.1
+++ gettext.c	2002/06/06 22:11:09
@@ -22,6 +22,10 @@
 # include <config.h>
 #endif
 
+#if defined HAVE_LOCALE_H || defined _LIBC
+# include <locale.h>
+#endif
+
 #ifdef __GNUC__
 # define alloca __builtin_alloca
 # define HAVE_ALLOCA 1
