--- qvfbmmap.cpp.orig	Sun Jan 14 15:51:46 2007
+++ qvfbmmap.cpp	Sun Jan 14 15:51:59 2007
@@ -34,7 +34,7 @@
 #include <sys/stat.h>
 #include <sys/sem.h>
 #include <sys/mman.h>
-#include <asm/page.h>
+#include <machine/param.h>
 #include <fcntl.h>
 #include <errno.h>
 #include <math.h>
