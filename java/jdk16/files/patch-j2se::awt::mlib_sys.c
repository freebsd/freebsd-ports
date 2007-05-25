--- ../../j2se/src/share/native/sun/awt/medialib/mlib_sys.c
+++ ../../j2se/src/share/native/sun/awt/medialib/mlib_sys.c
@@ -15,6 +15,9 @@
 #include <mlib_types.h>
 #include <mlib_sys_proto.h>
 #include "mlib_SysMath.h"
+#if defined(_ALLBSD_SOURCE)
+#include <sys/param.h>
+#endif
 
 /***************************************************************/
 
@@ -72,6 +75,9 @@
    * alignment. -- from stdlib.h of MS VC++5.0.
    */
   return (void *) malloc(size);
+#elif defined(__FreeBSD__) && (__FreeBSD_version >= 700013)
+  void *ret;
+  return posix_memalign(&ret, 8, size) ? NULL : ret;
 #elif defined(_ALLBSD_SOURCE)
   return valloc(size);
 #else
