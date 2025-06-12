--- components/widgets/list.hpp.orig	2023-08-08 09:23:20 UTC
+++ components/widgets/list.hpp
@@ -48,7 +48,7 @@ namespace Gui
 
         void scrollToTop();
 
-        void setPropertyOverride(const std::string& _key, const std::string& _value) override;
+        void setPropertyOverride(std::string_view _key, std::string_view _value) override;
 
     protected:
         void initialiseOverride() override;
