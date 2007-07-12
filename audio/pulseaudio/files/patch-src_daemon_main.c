--- src/daemon/main.c.orig	Thu Jul 12 00:04:22 2007
+++ src/daemon/main.c	Thu Jul 12 00:04:40 2007
@@ -40,6 +40,7 @@
 #include <unistd.h>
 #include <locale.h>
 #include <sys/types.h>
+#include <sys/stat.h>
 
 #include <liboil/liboil.h>
 
