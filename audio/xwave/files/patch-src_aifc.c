--- src/aifc.c.orig	1998-11-08 23:22:55 UTC
+++ src/aifc.c
@@ -9,7 +9,7 @@
 
 #ifdef linux
 #include <endian.h>
-#elif defined (FreeBSD)
+#elif defined (__FreeBSD__)
 #include <machine/endian.h>
 #elif defined (sgi)
 #include <sys/endian.h>
