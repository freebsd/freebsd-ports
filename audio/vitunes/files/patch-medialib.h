--- ./medialib.h.orig	2010-01-04 03:17:55.000000000 +0100
+++ ./medialib.h	2010-01-05 18:32:57.000000000 +0100
@@ -7,9 +7,15 @@
 #ifndef MEDIA_LIBRARY_H
 #define MEDIA_LIBRARY_H
 
+#include <limits.h>
+#include <stdlib.h>
 #include <sys/errno.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <unistd.h>
+
+typedef unsigned short u_short;
+
 #include <fts.h>
 
 #include "meta_info.h"
