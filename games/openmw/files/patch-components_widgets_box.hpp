--- components/widgets/box.hpp.orig	2023-08-08 09:23:20 UTC
+++ components/widgets/box.hpp
@@ -16,7 +16,7 @@ namespace Gui
         MYGUI_RTTI_DERIVED( ComboBox )
 
     protected:
-        void setPropertyOverride(const std::string& _key, const std::string& _value) override;
+        void setPropertyOverride(std::string_view _key, std::string_view _value) override;
     };
 
     class Button : public FontWrapper<MyGUI::Button>
@@ -58,7 +58,7 @@ namespace Gui
         void setCaption(const MyGUI::UString& _value) override;
 
     protected:
-        void setPropertyOverride(const std::string& _key, const std::string& _value) override;
+        void setPropertyOverride(std::string_view _key, std::string_view _value) override;
         std::string mFontSize;
     };
 
@@ -74,7 +74,7 @@ namespace Gui
         void initialiseOverride() override;
 
     protected:
-        void setPropertyOverride(const std::string& _key, const std::string& _value) override;
+        void setPropertyOverride(std::string_view _key, std::string_view _value) override;
         int getWidth();
         std::string mFontSize;
         bool mShrink = false;
@@ -91,7 +91,7 @@ namespace Gui
         void setCaption(const MyGUI::UString& _value) override;
 
     protected:
-        void setPropertyOverride(const std::string& _key, const std::string& _value) override;
+        void setPropertyOverride(std::string_view _key, std::string_view _value) override;
         std::string mFontSize;
     };
 
@@ -111,7 +111,7 @@ namespace Gui
     protected:
         virtual void align() = 0;
 
-        virtual bool _setPropertyImpl(const std::string& _key, const std::string& _value);
+        virtual bool _setPropertyImpl(std::string_view _key, std::string_view _value);
 
         int mSpacing; // how much space to put between elements
 
@@ -143,7 +143,7 @@ namespace Gui
         void align() override;
         MyGUI::IntSize getRequestedSize() override;
 
-        void setPropertyOverride(const std::string& _key, const std::string& _value) override;
+        void setPropertyOverride(std::string_view _key, std::string_view _value) override;
 
         void onWidgetCreated(MyGUI::Widget* _widget) override;
     };
@@ -162,7 +162,7 @@ namespace Gui
         void align() override;
         MyGUI::IntSize getRequestedSize() override;
 
-        void setPropertyOverride(const std::string& _key, const std::string& _value) override;
+        void setPropertyOverride(std::string_view _key, std::string_view _value) override;
 
         void onWidgetCreated(MyGUI::Widget* _widget) override;
     };
