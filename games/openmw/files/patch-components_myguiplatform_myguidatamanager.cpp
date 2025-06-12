--- components/myguiplatform/myguidatamanager.cpp.orig	2023-08-08 09:23:20 UTC
+++ components/myguiplatform/myguidatamanager.cpp
@@ -57,7 +57,7 @@ const MyGUI::VectorString &DataManager::getDataListNam
     throw std::runtime_error("DataManager::getDataListNames is not implemented - VFS is used");
 }
 
-const std::string &DataManager::getDataPath(const std::string &name) const
+std::string DataManager::getDataPath(const std::string &name) const
 {
     static std::string result;
     result.clear();
