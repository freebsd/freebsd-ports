--- lib/qhacc.cpp.orig	Thu Jul  8 07:06:55 2004
+++ lib/qhacc.cpp	Thu Aug 12 03:10:59 2004
@@ -55,7 +55,7 @@
 #include "localfileplugin.h"
 #include "qhacc.moc"
 
-#include <math.h>
+#include <cmath>
 
 //const int QHacc::ROLLOVER=( int )std::pow( ( double )10, QC::DECIMALS );
 const int QHacc::ROLLOVER=100;
