--- src/kbilliards.cpp.orig	Thu Feb 17 23:58:08 2005
+++ src/kbilliards.cpp	Fri Feb 18 13:20:19 2005
@@ -105,7 +105,7 @@
     // load game optios like players name , multiplayer, game type ..
     loadGameOptions();
 
-    MaxThrowPower=round((actualconfig.check_speed)*0.36) ;
+    MaxThrowPower=rint((actualconfig.check_speed)*0.36) ;
 
     KStandardDirs sd;
     path_data=(QString)(sd.findResourceDir("data","kbilliards/top_left_corner.png") + (QString)"kbilliards/");
@@ -901,7 +901,7 @@
 
            canvas->setAdvancePeriod(actualconfig.check_speed); // set current animation speed
 
-           MaxThrowPower=round((actualconfig.check_speed)*0.36) ; // set proportional max power
+           MaxThrowPower=rint((actualconfig.check_speed)*0.36) ; // set proportional max power
       }
 
       if (isvisible) {
