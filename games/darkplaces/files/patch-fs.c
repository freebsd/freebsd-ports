--- fs.c.orig	Sun May 28 18:26:08 2006
+++ fs.c	Sun Jul 23 16:31:17 2006
@@ -1061,7 +1061,7 @@
 
 	fs_mempool = Mem_AllocPool("file management", 0, NULL);
 
-	strcpy(fs_basedir, "");
+	strcpy(fs_basedir, Q1DIR);
 	strcpy(fs_gamedir, "");
 
 #ifdef MACOSX
