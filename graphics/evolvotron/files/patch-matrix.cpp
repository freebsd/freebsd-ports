--- matrix.cpp.orig	Thu Apr 17 17:49:39 2003
+++ matrix.cpp	Thu Apr 17 17:49:52 2003
@@ -26,6 +26,7 @@
 #include "random.h"
 
 #include <iostream>
+#include <time.h>
 
 void testmatrix_extract_runtime(Matrix<2,2,float>& m_out,const Matrix<3,3,float>& m_in)
 {
