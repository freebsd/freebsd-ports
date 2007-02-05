--- qvfbshmem.cpp.orig	Sun Jan 14 15:50:33 2007
+++ qvfbshmem.cpp	Sun Jan 14 15:50:46 2007
@@ -39,7 +39,7 @@
 #include <sys/stat.h>
 #include <sys/sem.h>
 #include <sys/mman.h>
-#include <asm/page.h>
+#include <machine/param.h>
 #include <fcntl.h>
 #include <errno.h>
 #include <math.h>
