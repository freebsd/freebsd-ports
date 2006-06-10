--- digikam/libs/dcraw/dcraw_parse.cpp.orig	Tue Apr 11 13:17:23 2006
+++ digikam/libs/dcraw/dcraw_parse.cpp	Tue Apr 11 13:34:31 2006
@@ -25,7 +25,11 @@
 extern "C" 
 {
 #include <ctype.h>
+#if defined(__FreeBSD__) && __FreeBSD__ < 5
+#include <sys/param.h>
+#else
 #include <netinet/in.h>
+#endif
 }
 
 // C++ includes
