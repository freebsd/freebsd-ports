--- components/myguiplatform/myguidatamanager.hpp.orig	2023-08-08 09:23:20 UTC
+++ components/myguiplatform/myguidatamanager.hpp
@@ -44,7 +44,7 @@ class DataManager : public MyGUI::DataManager (public)
         @param _name Resource name.
         @return Return full path to specified data.
     */
-    const std::string& getDataPath(const std::string& _name) const override;
+    std::string getDataPath(const std::string& _name) const override;
 
 private:
     std::string mResourcePath;
