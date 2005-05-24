--- leif/newpy/xaux/aux_win.c.orig	Mon May 16 23:16:54 2005
+++ leif/newpy/xaux/aux_win.c	Mon May 16 23:19:12 2005
@@ -61,7 +61,7 @@
 #include "gif_lib.h"
 #include "getarg.h"
 
-#define IMAGE_PATH "/usr/lib/im/locale/zh_CN/newpy/"
+#define IMAGE_PATH "%%LOCALBASE%%" "/lib/iiim/le/newpy/"
 
 Pixmap LoadGIFFile(char * filename);
 static void AllocateColors1(void);
