--- src/uade.c.orig	Sat Jun  7 23:29:10 2003
+++ src/uade.c	Sat Jun  7 23:29:54 2003
@@ -7,6 +7,7 @@
 #include <stdlib.h>
 #include <ctype.h>
 #include <dirent.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <limits.h>
 #ifndef PATH_MAX
