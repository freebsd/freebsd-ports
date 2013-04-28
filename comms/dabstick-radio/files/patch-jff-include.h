--- jff-include.h.orig
+++ jff-include.h
@@ -32,12 +32,18 @@
 #include	<complex>
 #include	<stdint.h>
 
+#ifdef __FreeBSD__
+#include	<stdlib.h>
+#else
 #include	<malloc.h>
+#endif
 
 #ifdef __MINGW32__
 #include	"windows.h"
 #else
+#ifndef __FreeBSD__
 #include	"alloca.h"
+#endif
 #include	"dlfcn.h"
 typedef	void	*HINSTANCE;
 #endif
