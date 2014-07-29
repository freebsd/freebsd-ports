--- cmn/area.cpp.orig	2012-05-27 06:52:29.000000000 +0900
+++ cmn/area.cpp	2012-05-27 06:53:11.000000000 +0900
@@ -34,12 +34,13 @@
 extern "C" {
 #include <limits.h> // For INT_MAX
 }
-#include <iostream.h>
+#include <iostream>
 #include "utils.h"
 #include "coord.h"
 #include "area.h"
 
 
+using namespace std;
 
 Size Area::operator - (const Area &other) const {
   assert ((shape == AR_RECT) && (other.shape == AR_RECT));
