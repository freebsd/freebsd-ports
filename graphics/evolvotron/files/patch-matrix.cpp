--- libevolvotron/matrix.cpp.orig	Mon Dec  1 03:12:54 2003
+++ libevolvotron/matrix.cpp	Mon Dec  1 03:13:12 2003
@@ -26,6 +26,7 @@
 #include "random.h"
 
 #include <iostream>
+#include <time.h>
 
 //! Test code
 void testmatrix_extract_runtime(Matrix<2,2,float>& m_out,const Matrix<3,3,float>& m_in)
