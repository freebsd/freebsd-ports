--- frontend/scanimage.c.orig	2022-01-19 16:38:00 UTC
+++ frontend/scanimage.c
@@ -39,6 +39,9 @@
 #include <string.h>
 #include <unistd.h>
 #include <stdarg.h>
+#ifdef __FreeBSD__
+#include <libgen.h>
+#endif
 
 #include <sys/types.h>
 #include <sys/stat.h>
