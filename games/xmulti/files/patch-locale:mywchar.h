--- locale/mywchar.h.old	Mon Dec 22 13:20:04 1997
+++ locale/mywchar.h	Tue Oct 15 16:19:11 2002
@@ -10,7 +10,9 @@
 #endif
 
 #ifdef BSD
+#if !defined(__FreeBSD__) || (__FreeBSD__ < 5)
 #include <machine/ansi.h>
+#endif
 #include <machine/limits.h>
 
 #ifndef NULL
