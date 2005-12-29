--- lib/gvc/gvconfig.c.orig	Thu Dec 29 12:33:58 2005
+++ lib/gvc/gvconfig.c	Thu Dec 29 11:02:51 2005
@@ -21,6 +21,7 @@
 #include	<string.h>
 
 #ifndef DISABLE_LTDL
+#include	<sys/types.h>
 #include	<regex.h>
 #include	<sys/stat.h>
 #include	<unistd.h>
