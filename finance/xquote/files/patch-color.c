--- ./color.c.orig	Sun Apr 16 15:08:31 2006
+++ ./color.c	Sun Apr 16 15:09:07 2006
@@ -34,7 +34,7 @@
 
 #include <stdio.h>
 
-#if !defined(__NetBSD__)
+#if !defined(__NetBSD__) && !defined(__FreeBSD__)
 #include <values.h>
 #endif
 
