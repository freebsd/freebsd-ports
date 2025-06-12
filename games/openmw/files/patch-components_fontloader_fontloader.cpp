--- components/fontloader/fontloader.cpp.orig	2023-08-08 09:23:20 UTC
+++ components/fontloader/fontloader.cpp
@@ -37,7 +37,7 @@ namespace
         MyGUI::xml::ElementEnumerator propertyIterator = resourceNode->getElementEnumerator();
         while (propertyIterator.next("Property"))
         {
-            std::string key = propertyIterator->findAttribute("key");
+            auto key = propertyIterator->findAttribute("key");
 
             if (key == propertyName)
             {
@@ -57,12 +57,12 @@ namespace
         MyGUI::xml::ElementEnumerator layersIterator = root->getElementEnumerator();
         while (layersIterator.next("Layer"))
         {
-            std::string name = layersIterator->findAttribute("name");
+            auto name = layersIterator->findAttribute("name");
 
             if (name == "JournalBooks")
             {
                 MyGUI::xml::ElementPtr sizeProperty = getProperty(layersIterator.current(), "Size");
-                const std::string& sizeValue = sizeProperty != nullptr ? sizeProperty->findAttribute("value") : std::string();
+                auto sizeValue = sizeProperty != nullptr ? sizeProperty->findAttribute("value") : std::string_view();
                 if (!sizeValue.empty())
                     return MyGUI::IntSize::parse(sizeValue);
             }
@@ -263,7 +263,7 @@ namespace Gui
         bool valid = false;
         if (resourceNode.next("Resource"))
         {
-            std::string type = resourceNode->findAttribute("type");
+            auto type = resourceNode->findAttribute("type");
             valid = (type == "ResourceTrueTypeFont");
         }
 
@@ -571,7 +571,7 @@ namespace Gui
         MyGUI::xml::ElementEnumerator resourceNode = _node->getElementEnumerator();
         while (resourceNode.next("Resource"))
         {
-            std::string type = resourceNode->findAttribute("type");
+            auto type = resourceNode->findAttribute("type");
 
             if (Misc::StringUtils::ciEqual(type, "ResourceSkin") ||
                      Misc::StringUtils::ciEqual(type, "AutoSizedResourceSkin"))
