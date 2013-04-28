--- filters/fir-filters.cpp.orig
+++ filters/fir-filters.cpp
@@ -28,8 +28,12 @@
 
 #include	"fir-filters.h"
 #ifndef	__MINGW32__
+#ifdef __FreeBSD__
+#include	<stdlib.h>
+#else
 #include	"alloca.h"
 #endif
+#endif
 
 //===================================================================
 //=====================================================================
