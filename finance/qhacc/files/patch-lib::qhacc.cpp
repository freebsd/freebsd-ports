--- lib/qhacc.cpp.orig	Thu Dec  9 08:25:23 2004
+++ lib/qhacc.cpp	Fri Dec 10 00:05:58 2004
@@ -55,7 +55,7 @@
 #include "localfileplugin.h"
 #include "qhacc.moc"
 
-#include <math.h>
+#include <cmath>
 
 //const int QHacc::ROLLOVER=( int )std::pow( ( double )10, QC::DECIMALS );
 const int QHacc::ROLLOVER=100;
