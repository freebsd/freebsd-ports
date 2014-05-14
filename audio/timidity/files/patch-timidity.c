--- ./timidity.c.orig	1996-05-21 14:16:20.000000000 -0500
+++ ./timidity.c	2013-04-21 10:18:23.000000000 -0500
@@ -21,7 +21,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-#if defined(SOLARIS) || defined(__WIN32__)
+#if defined(SOLARIS) || defined(__WIN32__) || defined(__FreeBSD__)
 #include <string.h>
 #else
 #include <strings.h>
