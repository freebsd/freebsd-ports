/usr/local/bin/ld: ./libU.a(MPri.o): in function `CMatrixPri::findfree(int, CNet&)':
src/nero/src/MPri.cpp:78: undefined reference to `TMatrix<char>::operator[](int)'
/usr/local/bin/ld: src/nero/src/MPri.cpp:79: undefined reference to `TMatrix<char>::operator[](int)'
/usr/local/bin/ld: ./libU.a(MPri.o): in function `CMatrixPri::take(int, int)':
src/nero/src/MPri.cpp:284: undefined reference to `TMatrix<char>::operator[](int)'
/usr/local/bin/ld: ./libU.a(MPri.o): in function `operator<<(std::ostream&, CMatrixPri&)':
src/nero/src/MPri.cpp:317: undefined reference to `TMatrix<char>::operator[](int)'
/usr/local/bin/ld: ./libU.a(MPri.o): in function `CMatrixPri::load(CNet&, bool, int)':
src/nero/src/MPri.cpp:175: undefined reference to `TMatrix<char>::operator[](int)'
/usr/local/bin/ld: ./libU.a(MPri.o):src/nero/src/MPri.cpp:186: more undefined references to `TMatrix<char>::operator[](int)' follow

--- nero/src/MDRGrid.cpp.orig	2014-08-02 23:38:00 UTC
+++ nero/src/MDRGrid.cpp
@@ -17,6 +17,7 @@
 
 
 # include  "MDefs.h"
+template class TMatrix<char>;
 
 
 
