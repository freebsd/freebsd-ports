--- ./image.c.orig	Sat Apr  8 10:15:01 2006
+++ ./image.c	Tue Aug 29 20:59:12 2006
@@ -20,6 +20,7 @@
 	$Id: image.c,v 1.20 2006/04/08 13:15:01 disconn3ct Exp $
 */
 
+#include <dlfcn.h>
 #include "quakedef.h"
 
 
@@ -1271,7 +1272,7 @@
 
 static QLIB_HANDLETYPE_T jpeg_handle = NULL;
 
-#define qjpeg_create_compress(cinfo) \
+#define qjpeg_create_compress(cinfo) \
     qjpeg_CreateCompress((cinfo), JPEG_LIB_VERSION, (size_t) sizeof(struct jpeg_compress_struct))
 
 static struct jpeg_error_mgr *(*qjpeg_std_error)(struct jpeg_error_mgr *);
