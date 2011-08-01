--- rtengine/myfile.h.orig	2011-07-30 14:05:38.000000000 -0700
+++ rtengine/myfile.h	2011-07-31 19:27:22.000000000 -0700
@@ -22,6 +22,8 @@
 #include <glib/gstdio.h>
 #include <stdio.h>
 #include <string.h>
+#undef feof
+#undef getc
 struct IMFILE {
 	int fd;
 	int pos;
