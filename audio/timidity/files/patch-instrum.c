--- instrum.c.orig	1996-05-20 13:15:10 UTC
+++ instrum.c
@@ -25,7 +25,7 @@
 
 #include <stdio.h>
 
-#if defined(SOLARIS) || defined(__WIN32__)
+#if defined(SOLARIS) || defined(__WIN32__) || defined(__FreeBSD__)
 #include <string.h>
 #else
 #include <strings.h>
