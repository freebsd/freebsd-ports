--- muse/app.cpp.orig	2022-07-09 17:10:01 UTC
+++ muse/app.cpp
@@ -49,6 +49,7 @@
 #include <iostream>
 #include <algorithm>
 //#include <typeinfo>
+#include <random>
 
 #include "app.h"
 #include "master/lmaster.h"
@@ -2743,7 +2744,8 @@ void MusE::showDidYouKnowDialog()
       didYouKnow.tipList.append(tipMessage);
     }
 
-    std::random_shuffle(didYouKnow.tipList.begin(),didYouKnow.tipList.end());
+    std::random_device randomDevice;
+    std::shuffle(didYouKnow.tipList.begin(),didYouKnow.tipList.end(), randomDevice);
 
     didYouKnow.show();
     if( didYouKnow.exec()) {
