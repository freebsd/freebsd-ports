--- src/Standalone/documentsize.cpp.orig	2021-11-25 00:56:55 UTC
+++ src/Standalone/documentsize.cpp
@@ -333,9 +333,9 @@ void Document_Size::CreateComboBoxToolTip(DocumentSize
         message = "";
     }else if(current_item == Auto_Detect_long){
         message = "";
-    }else if(current_item == OPTIONS){
+    }else if(current_item == (DocumentSize)OPTIONS){
         message = "";
-    }else if(current_item == USER_DEFINE){
+    }else if(current_item == (DocumentSize)USER_DEFINE){
         create_custom_size(&message);
     }else if(current_item == Maximum_Size){
         create_maximum_size(&message, scan_area_para);
@@ -774,7 +774,7 @@ void Document_Size::StandardSizeToPixel()
         }else if(current_item == Maximum_Size){
             current_pixel_x = max_pixel_x / 100 * this->base_resolution;
             current_pixel_y = max_pixel_y / 100 * this->base_resolution;
-        }else if(current_item == USER_DEFINE){
+        }else if(current_item == (DocumentSize)USER_DEFINE){
             Configuration& config = Configuration::GetConfiguration();
             Units units = config.config_para.units;
             if(units == unit_inchi){
