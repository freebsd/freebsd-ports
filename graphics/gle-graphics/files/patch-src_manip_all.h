--- src/manip/all.h.orig	2010-12-26 17:07:31 UTC
+++ src/manip/all.h
@@ -143,7 +143,7 @@ typedef char (*(*TOKENS)[500]);
 typedef unsigned char uchar;
 typedef double dbl;
 char *unquote(char *s);
-const char *gledir(const char *s);
+string gledir(const char *s);
 int set_missing(int x, int y);
 double vcell(int x, int y);
 void var_find_rc(int *idx, int *var, int *nd, int c);
