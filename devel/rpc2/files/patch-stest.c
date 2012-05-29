--- rpc2-src/stest.c.orig	2012-05-29 11:11:06.000000000 +0800
+++ rpc2-src/stest.c	2012-05-29 11:11:14.000000000 +0800
@@ -95,7 +95,7 @@ long VMCurrFileSize; /* number of useful
 char *VMFileBuf;    /* for FILEINVM transfers */
 
 int main(argc, argv)
-    long argc;
+    int argc;
     char *argv[];
 {
     SFTP_Initializer sftpi;
