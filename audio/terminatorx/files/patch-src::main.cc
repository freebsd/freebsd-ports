--- src/main.cc.orig	Thu Aug 21 06:41:24 2003
+++ src/main.cc	Sat Aug 23 04:52:05 2003
@@ -33,7 +33,7 @@
     4 October 1999: Rewrite ;) - back to C++
 */
 
-#define TX_GTKRC "/usr/share/themes/terminatorX/gtk/gtkrc"
+#define TX_GTKRC "%%X11BASE%%/share/themes/terminatorX/gtk/gtkrc"
 
 #define BENCH_CYCLES 100000
 
