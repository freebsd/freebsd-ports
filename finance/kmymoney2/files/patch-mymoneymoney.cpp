--- kmymoney2/mymoney/mymoneymoney.cpp.orig	Sun Jul 25 13:53:54 2004
+++ kmymoney2/mymoney/mymoneymoney.cpp	Sun Jul 25 14:06:09 2004
@@ -21,8 +21,13 @@
  ***************************************************************************/
 
 #define __STDC_LIMIT_MACROS         // force definition of min and max values 
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
-
+#else
+#include <limits.h>
+#define INT64_MAX LLONG_MAX
+#define INT64_MIN LLONG_MIN
+#endif
 // ----------------------------------------------------------------------------
 // QT Includes
 
