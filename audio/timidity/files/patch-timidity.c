--- timidity.c.orig	1996-05-21 19:16:20 UTC
+++ timidity.c
@@ -21,7 +21,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-#if defined(SOLARIS) || defined(__WIN32__)
+#if defined(SOLARIS) || defined(__WIN32__) || defined(__FreeBSD__)
 #include <string.h>
 #else
 #include <strings.h>
