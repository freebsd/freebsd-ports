--- src/argyll/spectro/unixio.c.orig	2008-02-20 00:02:24.000000000 +0300
+++ src/argyll/spectro/unixio.c	2008-08-03 21:47:17.000000000 +0400
@@ -585,9 +585,8 @@
 				break;
 
 			if (!(
-			    (   strncmp(de->d_name, "ttyS", 4) == 0
-			     && de->d_name[4] >= '0' && de->d_name[4] <= '9')
-			 || (   strncmp(de->d_name, "ttyUSB", 5) == 0)
+			    (strncmp(de->d_name, "cuad", 4) == 0 || strncmp(de->d_name, "cuaU", 4) == 0) &&
+			    strstr(de->d_name, ".init") == 0 && strstr(de->d_name, ".lock") == 0
 			))
 				continue;
 
