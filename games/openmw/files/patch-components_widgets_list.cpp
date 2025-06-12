--- components/widgets/list.cpp.orig	2023-08-08 09:23:20 UTC
+++ components/widgets/list.cpp
@@ -105,7 +105,7 @@ namespace Gui
         mScrollView->setViewOffset(MyGUI::IntPoint(0, -viewPosition));
     }
 
-    void MWList::setPropertyOverride(const std::string &_key, const std::string &_value)
+    void MWList::setPropertyOverride(std::string_view _key, std::string_view _value)
     {
         if (_key == "ListItemSkin")
             mListItemSkin = _value;
