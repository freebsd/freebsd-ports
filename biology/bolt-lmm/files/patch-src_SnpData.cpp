--- src/SnpData.cpp.orig	2019-08-03 00:23:17 UTC
+++ src/SnpData.cpp
@@ -996,7 +996,7 @@ namespace LMM {
     for (int w = 0; w < W; w++)
       if (isProximal(m, mp, windows[w].first, windows[w].second)) {
 	foundProximal = true;
-	if (!isnan(r2)) {
+	if (!std::isnan(r2)) {
 	  for (int a = 0; a < A; a++) {
 	    double weight = pow((snps[mp].MAF * (1-snps[mp].MAF)), alphaMAFdeps[a]);
 	    LDscores[w*A+a] += weight * r2;
@@ -1048,7 +1048,7 @@ namespace LMM {
       if (snps[mp].chrom != snps[m].chrom) {
 	fillSnpRow(&mpRow[0], mp);
 	double r2 = compute_r2(&mRow[0], &mpRow[0], Nstride);
-	if (!isnan(r2)) {
+	if (!std::isnan(r2)) {
 	  totOffChrom_r2s += r2;
 	  numOffChrom_r2s++;
 	}
