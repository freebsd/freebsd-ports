--- cgx_2.15/src/readFoam.c.orig	2018-12-15 10:23:59.490288980 -0500
+++ cgx_2.15/src/readFoam.c	2019-06-11 17:49:23.469502000 -0400
@@ -4,7 +4,7 @@
 
 
 #include <cgx.h>
-#include <sys/dir.h>
+#include <dirent.h>
 
 #define kappa    1.4
 
@@ -289,7 +289,7 @@
   int eface[8], sum_dir, ncomps;
   FILE *handle;
   DIR *dirp;
-  struct direct *dp;
+  struct dirent *dp;
   Rsort *rsort=NULL;
   Ds ds;
 
--- cgx_2.15/src/setFunktions.c.orig	2019-06-11 17:50:19.651248000 -0400
+++ cgx_2.15/src/setFunktions.c	2019-06-11 17:50:41.211341000 -0400
@@ -30,7 +30,7 @@
 */
 
 #include <cgx.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <xwd.h>
 
 
@@ -11859,7 +11859,7 @@
   int pics;
   int pnts[3];
   DIR *dirp;
-  struct direct *dp;
+  struct dirent *dp;
   static int ifFlag=1, whileFlag=1, returnFlag=1;
   Scale scaleSet[1];
 
