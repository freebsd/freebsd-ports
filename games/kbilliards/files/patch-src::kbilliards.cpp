--- src/kbilliards.cpp.orig	Wed Jan 19 10:43:51 2005
+++ src/kbilliards.cpp	Thu Jan 20 19:40:29 2005
@@ -84,7 +84,7 @@
     // and load musicconfiguration
     loadSettings();
     
-    MaxThrowPower=round((actualconfig.check_speed)*0.36) ;
+    MaxThrowPower=rint((actualconfig.check_speed)*0.36) ;
     
     KStandardDirs sd;
     path_data=(QString)(sd.findResourceDir("data","kbilliards/top_left_corner.png") + (QString)"kbilliards/");
@@ -806,7 +806,7 @@
 
       canvas->setAdvancePeriod(actualconfig.check_speed); // set current animation speed
 
-      MaxThrowPower=round((actualconfig.check_speed)*0.36) ; // set proportional max power
+      MaxThrowPower=rint((actualconfig.check_speed)*0.36) ; // set proportional max power
 
       }
 
