--- src/Standalone/imageformatsettingscombobox.cpp.orig	2024-09-12 07:10:40 UTC
+++ src/Standalone/imageformatsettingscombobox.cpp
@@ -68,7 +68,7 @@ void ImageFormatSettingsCombobox::add_item(ImageFormat
         }else if(img_format_list[i] == ImageFormatOFD){
             this->insertItem(i, "OFD", ImageFormatOFD);
             i++;
-        }else if(img_format_list[i] == OPTIONS){
+        }else if(img_format_list[i] == (ImageFormat)OPTIONS){
             break;
         }
     }
