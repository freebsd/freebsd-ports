--- smbd/vfs.c.orig	Sat Oct  9 09:49:52 2004
+++ smbd/vfs.c	Sat Oct  9 09:50:17 2004
@@ -790,7 +790,6 @@
 	*dir2 = *wd = *base_name = *newname = 0;
 
 	if (widelinks) {
-		unix_clean_name(s);
 		/* can't have a leading .. */
 		if (strncmp(s,"..",2) == 0 && (s[2]==0 || s[2]=='/')) {
 			DEBUG(3,("Illegal file name? (%s)\n",s));
