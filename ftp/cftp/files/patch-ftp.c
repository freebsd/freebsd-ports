
$FreeBSD$

--- ftp.c.orig	Tue Sep 17 16:58:18 2002
+++ ftp.c	Sat Sep 28 15:49:05 2002
@@ -311,7 +311,7 @@
 rftp_list(char *path)
 {
     directory *dir;
-    int fd;
+    int fd, resp;
     FILE *f;
     
     if (ftp_mode('a') == -1 || ftp_cwd(path) == -1)
@@ -321,7 +321,7 @@
 	return NULL;
     
     ftp_put("list");
-    if (ftp_resp() != 150) {
+    if ((resp=ftp_resp()) != 150 && resp != 125) {
 	close(fd);
 	dir = (directory *)malloc(sizeof(directory));
 	dir->line = (direntry *)malloc(sizeof(direntry));
@@ -379,7 +379,7 @@
 void *
 rftp_retr(char *file, int mode, long *startp, long *sizep)
 {
-    int fd;
+    int fd, resp;
     char *dir, *name, *can, *p;
     FILE *fin;
     
@@ -400,7 +400,7 @@
     }
     
     ftp_put("retr %s", name);
-    if (ftp_resp() != 150) {
+    if ((resp=ftp_resp()) != 150 && resp != 125) {
 	close(fd);
 	return NULL;
     }
