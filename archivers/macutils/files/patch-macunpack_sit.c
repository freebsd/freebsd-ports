--- macunpack/sit.c.orig	Fri Apr 16 00:18:28 1999
+++ macunpack/sit.c	Fri Apr 16 00:18:34 1999
@@ -19,7 +19,7 @@
 extern void de_lzah();
 extern unsigned char (*lzah_getbyte)();
 
-typedef struct methodinfo {
+struct methodinfo {
 	char *name;
 	int number;
 };
