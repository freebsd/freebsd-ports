--- cover.c.orig	2013-09-26 21:05:08.000000000 +0800
+++ cover.c	2013-09-26 21:05:14.000000000 +0800
@@ -25,6 +25,7 @@ char coverPS[50];
 #define COVERPAGE "cover.ps"
 #endif
 
+void
 coverpage() 
 {
 	int	tmp;
