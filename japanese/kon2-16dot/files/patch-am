--- include/vga.h.orig	Fri Jan 24 16:08:01 1997
+++ include/vga.h	Mon Jan 31 14:13:08 2000
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
 
