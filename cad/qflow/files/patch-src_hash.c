--- src/hash.c.orig	2020-03-19 05:26:09 UTC
+++ src/hash.c
@@ -19,7 +19,7 @@ the Free Software Foundation, Inc., 675 Mass Ave, Camb
 
 #include <stdio.h>
 #include <string.h>	/* For strdup() */
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <stdlib.h>
 #else
 #include <malloc.h>
