--- leif/newpy/xaux/aux_win.c	Fri Mar 16 00:52:22 2001
+++ leif/newpy/xaux/aux_win.c	Wed Feb 16 20:42:20 2005
@@ -61,7 +61,7 @@
 #include "gif_lib.h"
 #include "getarg.h"
 
-#define IMAGE_PATH "/usr/lib/im/locale/zh_CN/newpy/"
+#define IMAGE_PATH (IMDIR "/locale/zh_CN/newpy/")
 
 Pixmap LoadGIFFile(char * filename);
 static void AllocateColors1(void);
