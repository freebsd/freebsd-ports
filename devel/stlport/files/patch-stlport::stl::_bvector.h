--- stlport/stl/_bvector.h.orig	Sun Nov  2 16:59:07 2003
+++ stlport/stl/_bvector.h	Sun Oct 31 16:48:31 2004
@@ -34,7 +34,9 @@
 # include <stl/_vector.h>
 # endif
 
+#ifndef __WORD_BIT
 #define __WORD_BIT (int(CHAR_BIT*sizeof(unsigned int)))
+#endif
 
 _STLP_BEGIN_NAMESPACE 
 
