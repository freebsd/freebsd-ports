--- debug.c.orig	2012-07-01 20:00:16.000000000 +0200
+++ debug.c	2012-07-01 20:00:39.000000000 +0200
@@ -352,7 +352,7 @@
 void gbz80_debugger(void *garbage)
 {
 	printf("Debugger not available!\n");
-	return 0;
+	return;
 }
 
 #endif
