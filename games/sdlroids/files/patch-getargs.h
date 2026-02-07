--- getargs.h.orig	2023-04-13 13:43:47 UTC
+++ getargs.h
@@ -37,4 +37,4 @@
 
 /* getargs() prototype */
 void getargs(int, char *[]);
-int flagargs[NUMARGS];
+extern int flagargs[NUMARGS];
