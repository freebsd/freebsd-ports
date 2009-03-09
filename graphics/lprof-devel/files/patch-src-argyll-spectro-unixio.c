--- src/argyll/spectro/unixio.c.orig	2008-02-20 00:02:24.000000000 +0300
+++ src/argyll/spectro/unixio.c	2009-03-07 21:19:48.000000000 +0300
@@ -35,6 +35,7 @@
 #include "insttypes.h"
 #include "icoms.h"
 #include "usbio.h"
+#include <dirent.h>
 
 #undef DEBUG
 
@@ -585,9 +586,8 @@
 				break;
 
 			if (!(
-			    (   strncmp(de->d_name, "ttyS", 4) == 0
-			     && de->d_name[4] >= '0' && de->d_name[4] <= '9')
-			 || (   strncmp(de->d_name, "ttyUSB", 5) == 0)
+			    (strncmp(de->d_name, "cuad", 4) == 0 || strncmp(de->d_name, "cuaU", 4) == 0) &&
+			    strstr(de->d_name, ".init") == 0 && strstr(de->d_name, ".lock") == 0
 			))
 				continue;
 
