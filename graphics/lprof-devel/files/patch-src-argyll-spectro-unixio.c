--- src/argyll/spectro/unixio.c.orig	2008-02-20 00:02:24.000000000 +0300
+++ src/argyll/spectro/unixio.c	2008-05-14 06:16:33.000000000 +0400
@@ -585,9 +585,8 @@
 				break;
 
 			if (!(
-			    (   strncmp(de->d_name, "ttyS", 4) == 0
-			     && de->d_name[4] >= '0' && de->d_name[4] <= '9')
-			 || (   strncmp(de->d_name, "ttyUSB", 5) == 0)
+			    (   strncmp(de->d_name, "ttyd", 4) == 0 || strncmp(de->d_name, "ttyU", 4) == 0)
+			     && de->d_name[4] >= '0' && de->d_name[4] <= '9' && de->d_name[5] == '\0'
 			))
 				continue;
 
@@ -598,12 +597,6 @@
 			strcpy(dpath, dirn);
 			strcat(dpath, de->d_name);
 
-			if ((fd = open(dpath, O_RDWR | O_NOCTTY )) < 0) {
-				free(dpath);
-				continue;
-			}
-			close(fd);
-
 			/* Add the path to the list */
 			if (p->paths == NULL) {
 				if ((p->paths = (icompath **)calloc(sizeof(icompath *), 1 + 1)) == NULL) {
