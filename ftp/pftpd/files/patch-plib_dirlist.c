--- plib/dirlist.c.orig	Tue Feb  1 10:43:35 2005
+++ plib/dirlist.c	Mon May 23 18:35:47 2005
@@ -80,7 +80,9 @@
     len = strlen(name);
     dp = a_malloc(sizeof(*dp)+len, "struct dirent");
     dp->d_ino = ino;
+#ifdef		linux
     dp->d_off = 0;
+#endif		/* linux */
     dp->d_reclen = len;
     strcpy(dp->d_name, name);
 
