--- gdb/common/common-defs.h.orig	2017-09-12 12:25:12 UTC
+++ gdb/common/common-defs.h
@@ -44,9 +44,15 @@
 
    Must do this before including any system header, since other system
    headers may include stdint.h/inttypes.h.  */
+#ifndef __STDC_CONSTANT_MACROS
 #define __STDC_CONSTANT_MACROS 1
+#endif
+#ifndef __STDC_LIMIT_MACROS
 #define __STDC_LIMIT_MACROS 1
+#endif
+#ifndef __STDC_FORMAT_MACROS
 #define __STDC_FORMAT_MACROS 1
+#endif
 
 #include <stdarg.h>
 #include <stdio.h>
