--- fs.c.orig	Tue Aug  2 23:18:34 2005
+++ fs.c	Sun Jan 15 17:38:11 2006
@@ -933,7 +933,7 @@
 
 	fs_mempool = Mem_AllocPool("file management", 0, NULL);
 
-	strcpy(fs_basedir, ".");
+	strcpy(fs_basedir, Q1DIR);
 	strcpy(fs_gamedir, "");
 
 #ifdef MACOSX
