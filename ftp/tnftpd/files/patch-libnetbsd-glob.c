--- libnetbsd/glob.c.orig	Mon Dec 15 13:18:43 2003
+++ libnetbsd/glob.c	Wed Dec 13 08:16:13 2006
@@ -497,7 +497,8 @@
 	 * we save one character so that we can use ptr >= limit,
 	 * in the general case when we are appending non nul chars only.
 	 */
-	return(glob2(pathbuf, pathbuf, pathbuf + sizeof(pathbuf) - 1, pattern,
+	return(glob2(pathbuf, pathbuf,
+		pathbuf + (sizeof(pathbuf) / sizeof(*pathbuf)) - 1, pattern, 
 	    pglob, limit));
 }
 
