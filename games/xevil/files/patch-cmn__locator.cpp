--- cmn/locator.cpp.orig	2012-05-27 06:52:30.000000000 +0900
+++ cmn/locator.cpp	2012-05-27 06:53:11.000000000 +0900
@@ -50,6 +50,7 @@
 
 #include "bitmaps/locator/locator.bitmaps" // for arrows
 
+using namespace std;
 
 // When we reach this, start deleting objects.
 #define OL_LIST_WARN ((int)(OL_LIST_MAX * 0.9))
