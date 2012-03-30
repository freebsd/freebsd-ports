--- ./rtengine/myfile.h.orig	2012-01-31 05:00:05.000000000 +0400
+++ ./rtengine/myfile.h	2012-03-29 19:28:04.000000000 +0400
@@ -22,6 +22,8 @@
 #include <glib/gstdio.h>
 #include <cstdio>
 #include <cstring>
+#undef feof
+#undef getc
 struct IMFILE {
 	int fd;
 	int pos;
