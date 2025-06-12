--- components/widgets/box.cpp.orig	2023-08-08 09:23:20 UTC
+++ components/widgets/box.cpp
@@ -7,7 +7,7 @@ namespace Gui
 {
     // TODO: Since 3.4.2 MyGUI is supposed to automatically translate tags
     // If the 3.4.2 become a required minimum version, the ComboBox class may be removed.
-    void ComboBox::setPropertyOverride(const std::string& _key, const std::string& _value)
+    void ComboBox::setPropertyOverride(std::string_view _key, std::string_view _value)
     {
 #if MYGUI_VERSION >= MYGUI_DEFINE_VERSION(3,4,2)
         MyGUI::ComboBox::setPropertyOverride (_key, _value);
@@ -61,7 +61,7 @@ namespace Gui
         notifySizeChange (this);
     }
 
-    void AutoSizedTextBox::setPropertyOverride(const std::string& _key, const std::string& _value)
+    void AutoSizedTextBox::setPropertyOverride(std::string_view _key, std::string_view _value)
     {
         if (_key == "ExpandDirection")
         {
@@ -123,7 +123,7 @@ namespace Gui
         setEditStatic(true);
     }
 
-    void AutoSizedEditBox::setPropertyOverride(const std::string& _key, const std::string& _value)
+    void AutoSizedEditBox::setPropertyOverride(std::string_view _key, std::string_view _value)
     {
         if (_key == "ExpandDirection")
         {
@@ -156,7 +156,7 @@ namespace Gui
         notifySizeChange (this);
     }
 
-    void AutoSizedButton::setPropertyOverride(const std::string& _key, const std::string& _value)
+    void AutoSizedButton::setPropertyOverride(std::string_view _key, std::string_view _value)
     {
         if (_key == "ExpandDirection")
         {
@@ -179,7 +179,7 @@ namespace Gui
         align();
     }
 
-    bool Box::_setPropertyImpl(const std::string& _key, const std::string& _value)
+    bool Box::_setPropertyImpl(std::string_view _key, std::string_view _value)
     {
         if (_key == "Spacing")
             mSpacing = MyGUI::utility::parseValue<int>(_value);
@@ -278,7 +278,7 @@ namespace Gui
         }
     }
 
-    void HBox::setPropertyOverride(const std::string& _key, const std::string& _value)
+    void HBox::setPropertyOverride(std::string_view _key, std::string_view _value)
     {
         if (!Box::_setPropertyImpl (_key, _value))
             MyGUI::Widget::setPropertyOverride(_key, _value);
@@ -433,7 +433,7 @@ namespace Gui
         }
     }
 
-    void VBox::setPropertyOverride(const std::string& _key, const std::string& _value)
+    void VBox::setPropertyOverride(std::string_view _key, std::string_view _value)
     {
         if (!Box::_setPropertyImpl (_key, _value))
             MyGUI::Widget::setPropertyOverride(_key, _value);
