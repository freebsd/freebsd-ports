--- src/Standalone/widthdoublespinbox.cpp.orig	2021-11-25 00:56:56 UTC
+++ src/Standalone/widthdoublespinbox.cpp
@@ -116,7 +116,7 @@ bool WidthDoubleSpinBox::isUnit_inchi(void)
     Units units = config.config_para.units;
     if(units == unit_inchi){
         return true;
-    }else if(units == unit_mm){
+    }else{
         return false;
     }
 }
