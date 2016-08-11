--- common.c.orig	1996-06-01 12:20:19 UTC
+++ common.c
@@ -24,7 +24,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-#if defined(SOLARIS) || defined(__WIN32__)
+#if defined(SOLARIS) || defined(__WIN32__) || defined(__FreeBSD__)
 #include <string.h>
 #else
 #include <strings.h>
