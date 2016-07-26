--- src/main.cc.orig	2011-01-30 21:01:30 UTC
+++ src/main.cc
@@ -33,7 +33,7 @@
     4 October 1999: Rewrite ;) - back to C++
 */
 
-#define TX_GTKRC "/usr/share/themes/terminatorX/gtk/gtkrc"
+#define TX_GTKRC "%%LOCALBASE%%/share/themes/terminatorX/gtk/gtkrc"
 
 #define BENCH_CYCLES 100000
 
