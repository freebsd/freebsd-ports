--- src/FreqPhase.cpp.orig	2019-11-13 14:19:06 UTC
+++ src/FreqPhase.cpp
@@ -5,6 +5,7 @@
  * Email:  sanlucas@gmail.com
  */
 
+#include <sysexits.h>
 #include "FreqPhase.h"
 
 namespace haplohseq {
@@ -180,10 +181,17 @@ double FreqPhase::meanValue(const std::v
 double FreqPhase::medianValue(const std::vector<double>& values) {
 	double median;
 	size_t size = values.size();
+
+	// We can probably detect this condition earlier while loading the VCF
+	if ( size == 0 ) {
+		std::cerr << "FreqPhase::medianValue(): values vector is empty." << std::endl;
+		std::cerr << "Make sure your VCF has all of GT:AD:DP in the FORMAT column." << std::endl;
+		exit(EX_DATAERR);
+	}
 	std::vector<double> tempFreqs(values);
 	sort(tempFreqs.begin(), tempFreqs.end());
 
-	if (size  % 2 == 0) {
+	if (size % 2 == 0) {
 		median = (tempFreqs[size / 2 - 1] + tempFreqs[size / 2]) / 2;
 	}
 	else {
