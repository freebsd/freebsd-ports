--- src/lsz.c.orig	1998-12-30 07:07:59.000000000 +0900
+++ src/lsz.c	2012-01-21 10:44:49.000000000 +0900
@@ -1191,6 +1191,7 @@
 	struct stat f;
 
 	name2=alloca(PATH_MAX+1);
+	f.st_size = 0;
 
 	if (protocol==ZM_XMODEM) {
 		if (Verbose && *zi->fname && fstat(fileno(input_f), &f)!= -1) {
