--- src/funcs.c.orig	2022-10-19 10:26:29 UTC
+++ src/funcs.c
@@ -29,9 +29,7 @@
 
 #include <unistd.h>
 
-#ifdef HAVE_SYS_FILE_H
-#include <sys/file.h>
-#endif
+#include <fcntl.h>
 
 #include <sys/types.h>
 
