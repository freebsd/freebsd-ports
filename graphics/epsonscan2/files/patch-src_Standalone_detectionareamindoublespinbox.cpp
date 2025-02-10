--- src/Standalone/detectionareamindoublespinbox.cpp.orig	2024-09-12 07:10:40 UTC
+++ src/Standalone/detectionareamindoublespinbox.cpp
@@ -97,7 +97,7 @@ bool DetectionAreaMinDoubleSpinBox::isUnit_inchi(void)
     Units units = config.config_para.units;
     if(units == unit_inchi){
         return true;
-    }else if(units == unit_mm){
+    }else{
         return false;
     }
 }
