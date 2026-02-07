--- src/misc/util/abc_global.h.orig	2018-04-10 14:33:45 UTC
+++ src/misc/util/abc_global.h
@@ -97,6 +97,15 @@ ABC_NAMESPACE_HEADER_START
 ////////////////////////////////////////////////////////////////////////
 
 #ifdef ABC_USE_STDINT_H
+
+#ifndef __STDC_LIMIT_MACROS
+  #define __STDC_LIMIT_MACROS
+#endif
+
+#ifndef __STDC_CONSTANT_MACROS
+  #define __STDC_CONSTANT_MACROS
+#endif
+
 // If there is stdint.h, assume this is a reasonably-modern platform that
 // would also have stddef.h and limits.h
 #include <limits.h>
