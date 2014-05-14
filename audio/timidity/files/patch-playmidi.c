--- ./playmidi.c.orig	1996-05-20 08:09:46.000000000 -0500
+++ ./playmidi.c	2013-04-21 10:18:23.000000000 -0500
@@ -27,7 +27,7 @@
 #endif
 #include <stdlib.h>
 
-#if defined(SOLARIS) || defined(__WIN32__)
+#if defined(SOLARIS) || defined(__WIN32__) || defined(__FreeBSD__)
 # include <string.h>
 #else
 #include <strings.h>
