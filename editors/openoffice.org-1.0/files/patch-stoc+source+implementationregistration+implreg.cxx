--- stoc/source/implementationregistration/implreg.cxx.orig	Tue Apr 16 19:54:58 2002
+++ stoc/source/implementationregistration/implreg.cxx	Tue Apr 16 19:55:26 2002
@@ -60,6 +60,8 @@
  ************************************************************************/
 #include <list>
 
+#include <unistd.h>
+
 #ifndef _CPPUHELPER_QUERYINTERFACE_HXX_
 #include <cppuhelper/queryinterface.hxx>
 #endif
