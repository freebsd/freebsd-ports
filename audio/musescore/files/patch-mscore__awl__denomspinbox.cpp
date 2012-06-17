--- mscore/awl/denomspinbox.cpp.orig	2012-03-13 22:31:52.000000000 +0900
+++ mscore/awl/denomspinbox.cpp	2012-06-09 13:58:01.000000000 +0900
@@ -20,6 +20,11 @@
 
 #include "denomspinbox.h"
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x) (log(x)/log(2.0))
+#endif
+
 namespace Awl {
 
 //---------------------------------------------------------
