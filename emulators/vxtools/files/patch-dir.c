--- ./dir.c.orig	1999-12-02 17:57:40.000000000 +0100
+++ ./dir.c	2014-03-14 13:54:55.820662227 +0100
@@ -105,7 +105,7 @@
 					if (direct->ino)
 						filldir (dir, direct->name, direct->namelen, direct->ino);
 
-					(char *) direct += direct->reclen;
+					direct = (char *) direct + direct->reclen;
 				}
 
 			free (block);
