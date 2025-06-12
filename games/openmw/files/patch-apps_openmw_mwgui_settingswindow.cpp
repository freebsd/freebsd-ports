--- apps/openmw/mwgui/settingswindow.cpp.orig	2023-08-08 09:23:20 UTC
+++ apps/openmw/mwgui/settingswindow.cpp
@@ -107,22 +107,22 @@ namespace
 
     std::string getSettingType(MyGUI::Widget* widget)
     {
-        return widget->getUserString("SettingType");
+        return std::string{widget->getUserString("SettingType")};
     }
 
     std::string getSettingName(MyGUI::Widget* widget)
     {
-        return widget->getUserString("SettingName");
+        return std::string{widget->getUserString("SettingName")};
     }
 
     std::string getSettingCategory(MyGUI::Widget* widget)
     {
-        return widget->getUserString("SettingCategory");
+        return std::string{widget->getUserString("SettingCategory")};
     }
 
     std::string getSettingValueType(MyGUI::Widget* widget)
     {
-        return widget->getUserString("SettingValueType");
+        return std::string{widget->getUserString("SettingValueType")};
     }
 
     void getSettingMinMax(MyGUI::Widget* widget, float& min, float& max)
@@ -220,12 +220,12 @@ namespace MWGui
 
     void SettingsWindow::updateSliderLabel(MyGUI::ScrollBar *scroller, const std::string& value)
     {
-        std::string labelWidgetName = scroller->getUserString("SettingLabelWidget");
+        auto labelWidgetName = scroller->getUserString("SettingLabelWidget");
         if (!labelWidgetName.empty())
         {
             MyGUI::TextBox* textBox;
             getWidget(textBox, labelWidgetName);
-            std::string labelCaption = scroller->getUserString("SettingLabelCaption");
+            std::string labelCaption{scroller->getUserString("SettingLabelCaption")};
             labelCaption = Misc::StringUtils::format(labelCaption, value);
             textBox->setCaptionWithReplacing(labelCaption);
         }
