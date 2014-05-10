--- ./common.c.orig	1996-06-01 07:20:19.000000000 -0500
+++ ./common.c	2013-04-21 10:18:23.000000000 -0500
@@ -24,7 +24,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-#if defined(SOLARIS) || defined(__WIN32__)
+#if defined(SOLARIS) || defined(__WIN32__) || defined(__FreeBSD__)
 #include <string.h>
 #else
 #include <strings.h>
