--- stlport/stl/_bvector.h.orig	Fri Oct  3 23:22:06 2003
+++ stlport/stl/_bvector.h	Fri Oct  3 23:22:38 2003
@@ -34,7 +34,9 @@
 # include <stl/_vector.h>
 # endif
 
+#ifndef __WORD_BIT
 #define __WORD_BIT (int(CHAR_BIT*sizeof(unsigned int)))
+#endif
 
 _STLP_BEGIN_NAMESPACE 
 
