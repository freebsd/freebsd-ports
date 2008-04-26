--- panomatic/TestCode.h.orig	2008-03-05 22:12:18.000000000 +0100
+++ panomatic/TestCode.h	2008-04-26 20:21:56.000000000 +0200
@@ -29,7 +29,7 @@
 {
 public:
 	static void drawRansacMatches(std::string& i1, std::string& i2, 
-						PointMatchVector_t& iOK, PointMatchVector_t& iNOK, Ransac& iRansac, bool iHalf);
+						PointMatchVector_t& iOK, PointMatchVector_t& iNOK, Ransac& iRansac, float iScale);
 
 
 
