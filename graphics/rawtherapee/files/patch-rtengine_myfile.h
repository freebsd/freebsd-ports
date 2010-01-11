--- rtengine/myfile.h.orig	2010-01-10 18:33:11.000000000 -0800
+++ rtengine/myfile.h	2010-01-10 18:33:35.000000000 -0800
@@ -22,6 +22,9 @@
 #include <glib/gstdio.h>
 #include <stdio.h>
 #include <string.h>
+
+#undef feof
+#undef getc
 struct IMFILE {
 
 	int pos;
