--- macunpack/sit.c.orig	1993-10-02 20:16:00 UTC
+++ macunpack/sit.c
@@ -19,7 +19,7 @@ extern void set_huffman();
 extern void de_lzah();
 extern unsigned char (*lzah_getbyte)();
 
-typedef struct methodinfo {
+struct methodinfo {
 	char *name;
 	int number;
 };
