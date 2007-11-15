--- dir.c.orig	2007-11-16 03:10:42.000000000 +0600
+++ dir.c	2007-11-16 03:11:11.000000000 +0600
@@ -105,7 +105,7 @@
 					if (direct->ino)
 						filldir (dir, direct->name, direct->namelen, direct->ino);
 
-					(char *) direct += direct->reclen;
+					direct = (char *) direct + direct->reclen;
 				}
 
 			free (block);
