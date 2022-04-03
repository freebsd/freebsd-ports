--- src/Standalone/imageformatsettingscombobox.cpp.orig	2021-11-25 00:56:56 UTC
+++ src/Standalone/imageformatsettingscombobox.cpp
@@ -68,7 +68,7 @@ void ImageFormatSettingsCombobox::add_item(ImageFormat
         }else if(img_format_list[i] == ImageFormatColorJpegMonoRaw){
             this->insertItem(i, TranslationString::GetString().translation_str.FILESAVESETTING_007, ImageFormatColorJpegMonoRaw);
             i++;
-        }else if(img_format_list[i] == OPTIONS){
+        }else if(img_format_list[i] == (ImageFormat)OPTIONS){
             break;
         }
     }
