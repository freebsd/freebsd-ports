--- ./instrum.c.orig	1996-05-20 08:15:10.000000000 -0500
+++ ./instrum.c	2013-04-21 10:18:23.000000000 -0500
@@ -25,7 +25,7 @@
 
 #include <stdio.h>
 
-#if defined(SOLARIS) || defined(__WIN32__)
+#if defined(SOLARIS) || defined(__WIN32__) || defined(__FreeBSD__)
 #include <string.h>
 #else
 #include <strings.h>
