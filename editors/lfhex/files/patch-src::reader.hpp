--- src/reader.hpp.orig	Fri Feb 13 13:28:32 2004
+++ src/reader.hpp	Sat Dec 18 01:46:26 2004
@@ -34,9 +34,13 @@
 #include "local.h"
 
 #ifdef DEBUG
-#define INLINE
+#  define INLINE
 #else
-#define INLINE inline
+#  if defined(__GNUC__) && __GNUC__ == 3 && __GNUC_MINOR__ >= 1
+#    define INLINE __attribute__((always_inline))
+#  else
+#    define INLINE inline
+#  endif
 #endif
 
 typedef vector<uchar> ReadBuffer;
