--- src/lsz.c.orig	1998-12-29 22:07:59 UTC
+++ src/lsz.c
@@ -1191,6 +1191,7 @@ wctxpn(struct zm_fileinfo *zi)
 	struct stat f;
 
 	name2=alloca(PATH_MAX+1);
+	f.st_size = 0;
 
 	if (protocol==ZM_XMODEM) {
 		if (Verbose && *zi->fname && fstat(fileno(input_f), &f)!= -1) {
