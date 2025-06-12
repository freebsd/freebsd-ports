--- components/widgets/imagebutton.cpp.orig	2023-08-08 09:23:20 UTC
+++ components/widgets/imagebutton.cpp
@@ -34,7 +34,7 @@ namespace Gui
         updateImage();
     }
 
-    void ImageButton::setPropertyOverride(const std::string &_key, const std::string &_value)
+    void ImageButton::setPropertyOverride(std::string_view _key, std::string_view _value)
     {
         if (_key == "ImageHighlighted")
             mImageHighlighted = _value;
