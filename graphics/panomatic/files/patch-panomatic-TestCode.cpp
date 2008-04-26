--- panomatic/TestCode.cpp.orig	2008-03-10 20:17:33.000000000 +0000
+++ panomatic/TestCode.cpp	2008-03-11 08:52:59.000000000 +0000
@@ -88,13 +88,10 @@
 }
 
 void TestCode::drawRansacMatches(std::string& i1, std::string& i2, 
-								 PointMatchVector_t& iOK, PointMatchVector_t& iNOK, Ransac& iRansac, bool iHalf)
+								 PointMatchVector_t& iOK, PointMatchVector_t& iNOK, Ransac& iRansac, float iScale)
 {
-	double aDoubleFactor = 1.0;
-    if (iHalf)
-        aDoubleFactor = 2.0;
+	double aDoubleFactor = 1.0 / iScale;
 
-    
     std::cout << "writing file outcomp.png ..." << endl;
 	
 	// write a side by side image with match pairs and
