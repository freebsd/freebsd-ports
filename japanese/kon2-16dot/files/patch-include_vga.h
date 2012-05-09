--- include/vga.h.orig	1997-01-24 16:08:01.000000000 +0900
+++ include/vga.h	2012-05-10 00:14:28.621553061 +0900
@@ -59,7 +59,11 @@
 #if defined(linux)
 #define GRAPH_BASE 0xA0000
 #elif defined(__FreeBSD__)
-#define GRAPH_BASE 0x0
+# if (__FreeBSD__ <= 3)
+# define GRAPH_BASE 0x0
+# else
+# define GRAPH_BASE 0xA0000
+# endif
 #endif
 #define FONT_SIZE  0x2000
 
