--- src/graphdev.cpp.ori	Tue Apr  9 14:54:28 2002
+++ src/graphdev.cpp	Tue Apr  9 15:27:14 2002
@@ -29,7 +29,7 @@
 
 #include "display/fbdev.h"
 #include "display/vgadev.h"
-#if defined(linux)
+#if defined(linux) || defined(__FreeBSD__)
     #ifdef HAVE_GGI_LIB
     #include "display/libggi.h"
     #endif
