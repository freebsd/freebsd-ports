--- intl/dcigettext.c.orig	Mon Nov 25 23:59:34 2002
+++ intl/dcigettext.c	Tue Nov 26 00:19:20 2002
@@ -57,10 +57,12 @@
 #include <stdlib.h>
 
 #include <string.h>
+#if 0
 #if !HAVE_STRCHR && !defined _LIBC
 # ifndef strchr
 #  define strchr index
 # endif
+#endif
 #endif
 
 #if defined HAVE_UNISTD_H || defined _LIBC
