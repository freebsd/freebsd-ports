--- scaddins/source/analysis/analysishelper.hxx.orig	2014-09-19 18:07:44 UTC
+++ scaddins/source/analysis/analysishelper.hxx
@@ -35,7 +35,7 @@
 
 #include <math.h>
 
-#include <boost/tr1/complex.hpp>
+#include <complex>
 #ifndef double_complex
 typedef std::complex<double>		double_complex;
 #endif
