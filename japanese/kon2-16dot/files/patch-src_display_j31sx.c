--- src/display/j31sx.c.orig	1997-01-24 09:38:09.000000000 +0900
+++ src/display/j31sx.c	2012-05-10 00:14:28.873551067 +0900
@@ -49,7 +49,6 @@
 #include	<sys/mman.h>
 #include	<linux/mm.h>
 #include	<sys/kd.h>
-#undef free
 #include	<stdlib.h>
 
 #include	<mem.h>
@@ -365,8 +364,6 @@
 	ioperm(CGA_COLOR, 1, 0);
 
 	munmap(gram, GRAPH_SIZE);
-
-	SafeFree((void **)&gram);
 }
 
 static struct videoInfo J31SXInfo =
