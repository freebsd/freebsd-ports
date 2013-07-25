--- filters/iir-filters.cpp.orig
+++ filters/iir-filters.cpp
@@ -28,8 +28,12 @@
 
 #include	"iir-filters.h"
 #ifndef	__MINGW32__
+#ifdef __FreeBSD__
+#include	<stdlib.h>
+#else
 #include	"alloca.h"
 #endif
+#endif
 
 #define	MAXORDER	0176
 
