--- src/Standalone/widthdoublespinbox.cpp.orig	2024-09-12 07:10:41 UTC
+++ src/Standalone/widthdoublespinbox.cpp
@@ -113,7 +113,7 @@ bool WidthDoubleSpinBox::isUnit_inchi(void)
     Units units = config.config_para.units;
     if(units == unit_inchi){
         return true;
-    }else if(units == unit_mm){
+    }else{
         return false;
     }
 }
