--- htype.c.orig	Fri May 19 16:52:08 1995
+++ htype.c	Mon Dec 23 08:38:17 2002
@@ -132,10 +132,14 @@
 	printf("\n#define CHARS_ARE_%sSIGNED\n", (((char)-1) < 0) ? "" : "UN");
 
 	if (*p == 1) {
+		puts("#ifndef BIG_ENDIAN");
 		puts("#define BIG_ENDIAN");
+		puts("#endif");
 	}
 	else {
+		puts("#ifndef LITTLE_ENDIAN");
 		puts("#define LITTLE_ENDIAN");
+		puts("#endif");
 	}
 
 	return 0;
