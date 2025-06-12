--- apps/openmw/mwgui/cursor.cpp.orig	2023-08-08 09:23:20 UTC
+++ apps/openmw/mwgui/cursor.cpp
@@ -26,8 +26,8 @@ namespace MWGui
         MyGUI::xml::ElementEnumerator info = _node->getElementEnumerator();
         while (info.next("Property"))
         {
-            const std::string& key = info->findAttribute("key");
-            const std::string& value = info->findAttribute("value");
+            const auto key = info->findAttribute("key");
+            const auto value = info->findAttribute("value");
 
             if (key == "Point")
                 mPoint = MyGUI::IntPoint::parse(value);
