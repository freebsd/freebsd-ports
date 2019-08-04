--- src/LDscoreCalibration.cpp.orig	2019-08-03 00:18:05 UTC
+++ src/LDscoreCalibration.cpp
@@ -201,8 +201,8 @@ namespace LDscoreCalibration {
 	snps[m].MAF >= minMAF &&      // MAF threshold
 	statsRef[m] > 0 &&            // ref stat available
 	statsCur[m] > 0 &&            // cur stat available
-	!isnan(LDscores[m]) &&   // LD Score available
-	!isnan(LDscoresChip[m]); // LD Score weight available
+	!std::isnan(LDscores[m]) &&   // LD Score available
+	!std::isnan(LDscoresChip[m]); // LD Score weight available
     
     // perform outlier removal
     double outlierChisqThresh = std::max(MIN_OUTLIER_CHISQ_THRESH, N * outlierVarFracThresh);
@@ -256,8 +256,8 @@ namespace LDscoreCalibration {
       maskSnps[m] =
 	snps[m].MAF >= minMAF &&      // MAF threshold
 	stats[m] > 0 &&               // stat available
-	!isnan(LDscores[m]) &&   // LD Score available
-	!isnan(LDscoresChip[m]); // LD Score weight available
+	!std::isnan(LDscores[m]) &&   // LD Score available
+	!std::isnan(LDscoresChip[m]); // LD Score weight available
     
     // perform outlier removal
     double outlierChisqThresh = std::max(MIN_OUTLIER_CHISQ_THRESH, N * outlierVarFracThresh);
