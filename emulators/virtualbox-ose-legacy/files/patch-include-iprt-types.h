--- include/iprt/types.h.orig	2012-03-05 10:48:48.000000000 +0100
+++ include/iprt/types.h	2012-03-05 11:21:25.000000000 +0100
@@ -82,6 +82,8 @@
 #  include <stddef.h>
 #  define _UINT64_T_DECLARED
 #  define _INT64_T_DECLARED
+#  define _UINTPTR_T_DECLARED
+#  define _INTPTR_T_DECLARED
 #  include <sys/types.h>
 
 # elif defined(RT_OS_LINUX) && defined(__KERNEL__)
