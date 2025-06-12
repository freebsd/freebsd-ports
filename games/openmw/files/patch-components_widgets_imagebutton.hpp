--- components/widgets/imagebutton.hpp.orig	2023-08-08 09:23:20 UTC
+++ components/widgets/imagebutton.hpp
@@ -31,7 +31,7 @@ namespace Gui
         static bool sDefaultNeedKeyFocus;
 
     protected:
-        void setPropertyOverride(const std::string& _key, const std::string& _value) override;
+        void setPropertyOverride(std::string_view _key, std::string_view _value) override;
         void onMouseLostFocus(MyGUI::Widget* _new) override;
         void onMouseSetFocus(MyGUI::Widget* _old) override;
         void onMouseButtonPressed(int _left, int _top, MyGUI::MouseButton _id) override;
