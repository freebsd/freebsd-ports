--- rexxapi/RexxAPIManager.cpp.orig	2007-11-14 03:31:03.000000000 +0600
+++ rexxapi/RexxAPIManager.cpp	2007-11-14 03:32:26.000000000 +0600
@@ -108,6 +108,9 @@
 #include <signal.h>
 #include <limits.h>
 #endif
+#if defined(__FreeBSD__)
+#include <limits.h>
+#endif
 /* #if defined(LINUX) && !defined(OPSYS_SUN) */
 /* #include <bits/posix1_lim.h> */
 /* #endif */
