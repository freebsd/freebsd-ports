--- make-x64/jff-include.h.orig
+++ make-x64/jff-include.h
@@ -32,10 +32,16 @@
 #include	<complex>
 #include	<stdint.h>
 
+#ifdef __FreeBSD__
+#include	<stdlib.h>
+#else
 #include	<malloc.h>
+#endif
 #ifndef __MINGW32__
+#ifndef __FreeBSD__
 #include	"alloca.h"
 #endif
+#endif
 
 #ifdef __MINGW32__
 #define	CURRENT_VERSION		"4.1:x64"
