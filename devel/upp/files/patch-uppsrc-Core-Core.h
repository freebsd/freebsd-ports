--- uppsrc/Core/Core.h.orig	Thu Jul 19 19:57:53 2007
+++ uppsrc/Core/Core.h	Thu Jul 19 19:59:16 2007
@@ -300,8 +300,16 @@
 #include <string>
 
 #ifdef PLATFORM_POSIX
+#ifdef COMPILER_GCC
+#if __GNUC__ > 3
+#include <ext/atomicity.h>
+#else
+#include <bits/atomicity.h>
+#endif
+#else
 #include <bits/atomicity.h>
 #endif
+#endif
 
 // fix MSC8 beta problem....
 #ifdef COMPILER_MSC
