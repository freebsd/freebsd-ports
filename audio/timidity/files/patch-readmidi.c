--- ./readmidi.c.orig	1996-05-20 08:09:47.000000000 -0500
+++ ./readmidi.c	2013-04-21 10:18:23.000000000 -0500
@@ -23,7 +23,7 @@
 #include <stdlib.h>
 #include <errno.h>
 
-#if defined(SOLARIS) | defined(__WIN32__)
+#if defined(SOLARIS) || defined(__WIN32__) || defined(__FreeBSD__)
 # include <string.h>
 #else
 #include <strings.h>
