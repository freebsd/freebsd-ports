
$FreeBSD$

--- src/DAPA.C.orig	Thu Jun 13 15:17:24 2002
+++ src/DAPA.C	Thu Nov 21 20:37:08 2002
@@ -72,6 +72,7 @@
 
 #elif defined(__FreeBSD__) && defined(__i386__)
 
+#include <sys/types.h>
 #include <sys/fcntl.h>
 #include <machine/cpufunc.h>
 #include <machine/sysarch.h>
