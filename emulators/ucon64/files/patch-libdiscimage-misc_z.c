--- libdiscmage/misc_z.c.orig	2013-02-24 18:50:29.788944291 -0800
+++ libdiscmage/misc_z.c	2013-02-24 18:51:00.403942771 -0800
@@ -27,6 +27,7 @@
 #include <string.h>
 #include <errno.h>
 #include <sys/stat.h>
+#define Z_SOLO
 #include <zlib.h>
 #include "misc_z.h"
 #include "misc.h"
