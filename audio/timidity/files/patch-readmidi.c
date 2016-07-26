--- readmidi.c.orig	1996-05-20 13:09:47 UTC
+++ readmidi.c
@@ -23,7 +23,7 @@
 #include <stdlib.h>
 #include <errno.h>
 
-#if defined(SOLARIS) | defined(__WIN32__)
+#if defined(SOLARIS) || defined(__WIN32__) || defined(__FreeBSD__)
 # include <string.h>
 #else
 #include <strings.h>
