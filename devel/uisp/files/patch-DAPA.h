diff -urN DAPA.h.orig DAPA.h
--- DAPA.h.orig	Tue Aug 29 17:08:28 2000
+++ DAPA.h	Fri Feb 16 19:58:33 2001
@@ -12,7 +12,9 @@
 #include <sys/types.h>
 #include <time.h>
 #include <unistd.h>
+#if !defined (__FreeBSD__)
 #include <string>
+#endif
 #include "Error.h"
 
 class TDAPA {
