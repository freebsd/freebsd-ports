--- panomatic/PanoDetector.cpp.orig	2008-03-10 20:17:33.000000000 +0000
+++ panomatic/PanoDetector.cpp	2012-09-24 12:02:46.529117189 +0000
@@ -26,7 +26,7 @@
 	_sieve1Width(10), _sieve1Height(10), _sieve1Size(10),
 	_kdTreeSearchSteps(40), _kdTreeSecondDistance(0.15), _sieve2Width(5), _sieve2Height(5),
 	_sieve2Size(1), _test(false), _cores(utils::getCPUCount()), _ransacIters(1000), _ransacDistanceThres(25),
-	_minimumMatches(4), _linearMatch(false), _linearMatchLen(1), _downscale(true)
+	_minimumMatches(4), _linearMatch(false), _linearMatchLen(1), _scale(0.5)
 {
 	
 }
@@ -67,7 +67,7 @@
 	cout << "Output file       : " << _outputFile << endl;
 	cout << "Number of CPU     : " << _cores << endl << endl;
 	cout << "Input image options" << endl;
-    cout << "  Downscale to half-size : " << (_downscale?"yes":"no") << endl;
+    cout << "  Scale factor : " << _scale << endl;
     cout << "SURF Options" << endl;
 	cout << "  Extended : " << (_extendedSurf?"yes":"no") << endl;
 	cout << "  Score threshold : " << _surfScoreThreshold << endl;
