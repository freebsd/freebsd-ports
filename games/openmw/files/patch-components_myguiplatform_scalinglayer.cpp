--- components/myguiplatform/scalinglayer.cpp.orig	2023-08-08 09:23:20 UTC
+++ components/myguiplatform/scalinglayer.cpp
@@ -126,8 +126,8 @@ namespace osgMyGUI
         {
             if (info->getName() == "Property")
             {
-                const std::string& key = info->findAttribute("key");
-                const std::string& value = info->findAttribute("value");
+                const auto key = info->findAttribute("key");
+                const auto value = info->findAttribute("value");
 
                 if (key == "Size")
                 {
