--- camel/camel-block-file.h.orig	Tue May 15 01:48:42 2007
+++ camel/camel-block-file.h	Tue May 15 01:49:00 2007
@@ -21,6 +21,7 @@
 #ifndef _CAMEL_BLOCK_FILE_H
 #define _CAMEL_BLOCK_FILE_H
 
+#include <sys/types.h>
 #include <camel/camel-object.h>
 #include <glib.h>
 #include <libedataserver/e-msgport.h>
