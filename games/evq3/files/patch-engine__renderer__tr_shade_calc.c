--- ./engine/renderer/tr_shade_calc.c.orig	Thu Mar 29 18:53:40 2007
+++ ./engine/renderer/tr_shade_calc.c	Mon Apr 16 23:59:03 2007
@@ -1645,7 +1645,7 @@
 	}
 }
 
-#if id386 && !( (defined __linux__ || defined __FreeBSD__ ) && (defined __i386__ ) )	// rb010123
+#if id386 && !( (defined __unix__ ) && (defined __i386__ ) )	// rb010123
 
 long myftol(float f)
 {
