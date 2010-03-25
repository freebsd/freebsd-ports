--- modules/gzip-method.c.orig	2010-03-25 16:05:12.000000000 -0400
+++ modules/gzip-method.c	2010-03-25 16:06:56.000000000 -0400
@@ -30,6 +30,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <time.h>
+#undef _LARGEFILE64_SOURCE
 #include <zlib.h>
 
 struct _GZipMethodHandle {
