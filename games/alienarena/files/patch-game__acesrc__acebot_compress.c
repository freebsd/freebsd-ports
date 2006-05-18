--- ./game/acesrc/acebot_compress.c.orig	Tue May 16 15:20:10 2006
+++ ./game/acesrc/acebot_compress.c	Tue May 16 15:20:10 2006
@@ -17,7 +17,6 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
-#include <malloc.h>
 
 #define N		 4096	/* size of ring buffer */
 #define F		   18	/* upper limit for match_length */
