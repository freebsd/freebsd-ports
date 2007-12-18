--- tqsllib-2.0/tqslconvert.cpp.orig	2007-12-18 08:39:49.000000000 -0500
+++ tqsllib-2.0/tqslconvert.cpp	2007-12-18 08:42:31.000000000 -0500
@@ -23,6 +23,7 @@
 #include <string>
 #include <ctype.h>
 #include <set>
+#include <locale.h>
 
 //#include <iostream>
 
@@ -264,6 +265,7 @@
 
 static const char *
 tqsl_infer_band(const char* infreq) {
+	setlocale(LC_NUMERIC, "C");
 	double freq = atof(infreq);
 	double freq_khz = freq * 1000.0;
 	int nband = 0;
