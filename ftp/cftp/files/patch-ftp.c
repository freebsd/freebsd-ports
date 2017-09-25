--- ftp.c.orig	2002-09-17 14:58:18 UTC
+++ ftp.c
@@ -311,7 +311,7 @@ directory *
 rftp_list(char *path)
 {
     directory *dir;
-    int fd;
+    int fd, resp;
     FILE *f;
     
     if (ftp_mode('a') == -1 || ftp_cwd(path) == -1)
@@ -321,7 +321,7 @@ rftp_list(char *path)
 	return NULL;
     
     ftp_put("list");
-    if (ftp_resp() != 150) {
+    if ((resp=ftp_resp()) != 150 && resp != 125) {
 	close(fd);
 	dir = (directory *)malloc(sizeof(directory));
 	dir->line = (direntry *)malloc(sizeof(direntry));
@@ -379,7 +379,7 @@ ftp_cd(char *wd, int force)
 void *
 rftp_retr(char *file, int mode, long *startp, long *sizep)
 {
-    int fd;
+    int fd, resp;
     char *dir, *name, *can, *p;
     FILE *fin;
     
@@ -400,7 +400,7 @@ rftp_retr(char *file, int mode, long *st
     }
     
     ftp_put("retr %s", name);
-    if (ftp_resp() != 150) {
+    if ((resp=ftp_resp()) != 150 && resp != 125) {
 	close(fd);
 	return NULL;
     }
