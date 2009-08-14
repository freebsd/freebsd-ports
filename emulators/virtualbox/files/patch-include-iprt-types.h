--- include/iprt/types.h.orig	2009-07-12 21:17:13.000000000 +0200
+++ include/iprt/types.h	2009-08-12 21:38:17.000000000 +0200
@@ -92,6 +92,11 @@
 #  undef true
 #  undef bool
 
+# elif defined(RT_OS_FREEBSD)
+#  define _UINT64_T_DECLARED
+#  define _INT64_T_DECLARED
+#  include <stddef.h>
+#  include <sys/types.h>
 # else
 #  include <stddef.h>
 #  include <sys/types.h>
