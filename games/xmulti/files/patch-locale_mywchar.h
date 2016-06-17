--- locale/mywchar.h.orig	1997-12-22 04:20:04 UTC
+++ locale/mywchar.h
@@ -10,7 +10,9 @@
 #endif
 
 #ifdef BSD
+#if !defined(__FreeBSD__) || (__FreeBSD__ < 5)
 #include <machine/ansi.h>
+#endif
 #include <machine/limits.h>
 
 #ifndef NULL
