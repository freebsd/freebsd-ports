--- cgx_1.4/src/readFoam.c	Tue Sep 13 06:34:28 2005
+++ cgx_1.4/src/readFoam.c	Sun Nov 20 08:27:42 2005
@@ -4,7 +4,13 @@
 
 
 #include <cgx.h>
+//dirent.h should oveeride sys/dir.h...
+#include <osreldate.h>
+#if __FreeBSD_version > 500000
 #include <sys/dir.h>
+#else
+#include <dirent.h>
+#endif
 
 #define R_GAS    287.1
 #define kappa    1.4
