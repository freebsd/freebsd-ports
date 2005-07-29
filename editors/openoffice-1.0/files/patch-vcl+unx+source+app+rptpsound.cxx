--- vcl/unx/source/app/rptpsound.cxx.orig	Wed Oct 24 18:32:21 2001
+++ vcl/unx/source/app/rptpsound.cxx	Sun Jun  2 22:01:07 2002
@@ -78,6 +78,10 @@
 extern "C" int usleep(unsigned int);
 #endif
 
+#ifdef FREEBSD
+#include <unistd.h>
+#endif
+
 #ifdef _USE_NAMESPACE
 using namespace vcl_sal;
 using namespace vos;
