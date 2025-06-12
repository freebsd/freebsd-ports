--- components/widgets/fontwrapper.hpp.orig	2023-08-08 09:23:20 UTC
+++ components/widgets/fontwrapper.hpp
@@ -11,14 +11,14 @@ namespace Gui
     class FontWrapper : public T
     {
     public:
-        void setFontName(const std::string& name) override
+        void setFontName(std::string_view _value) override
         {
-            T::setFontName(name);
+            T::setFontName(_value);
             T::setPropertyOverride ("FontHeight", getFontSize());
         }
 
     protected:
-        void setPropertyOverride(const std::string& _key, const std::string& _value) override
+        void setPropertyOverride(std::string_view _key, std::string_view _value) override
         {
             T::setPropertyOverride (_key, _value);
 
