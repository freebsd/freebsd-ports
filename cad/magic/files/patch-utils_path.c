--- utils/path.c.orig	2025-03-17 19:16:36 UTC
+++ utils/path.c
@@ -29,6 +29,7 @@ static char rcsid[] __attribute__ ((unused)) = "$Heade
 #include <sys/param.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#include <unistd.h>
 
 #ifdef HAVE_ZLIB
 #include <zlib.h>
