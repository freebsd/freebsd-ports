--- playmidi.c.orig	1996-05-20 13:09:46 UTC
+++ playmidi.c
@@ -27,7 +27,7 @@
 #endif
 #include <stdlib.h>
 
-#if defined(SOLARIS) || defined(__WIN32__)
+#if defined(SOLARIS) || defined(__WIN32__) || defined(__FreeBSD__)
 # include <string.h>
 #else
 #include <strings.h>
