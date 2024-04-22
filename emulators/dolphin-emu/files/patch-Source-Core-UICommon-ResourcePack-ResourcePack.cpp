Fix build with minizip-ng 4.0.4

Source/Core/UICommon/ResourcePack/ResourcePack.cpp:39:7: error: no matching function for call to 'unzLocateFile'
(no known conversion from 'std::nullptr_t' to 'unzFileNameCase' (aka 'int') for 3rd argument)

This partially reverts upstream commit a5d06fd.

--- Source/Core/UICommon/ResourcePack/ResourcePack.cpp.orig	2023-07-23 02:24:09 UTC
+++ Source/Core/UICommon/ResourcePack/ResourcePack.cpp
@@ -36,7 +36,7 @@ ResourcePack::ResourcePack(const std::string& path) : 
     return;
   }
 
-  if (unzLocateFile(file, "manifest.json", nullptr) == UNZ_END_OF_LIST_OF_FILE)
+  if (unzLocateFile(file, "manifest.json", 0) == UNZ_END_OF_LIST_OF_FILE)
   {
     m_valid = false;
     m_error = "Resource pack is missing a manifest.";
@@ -63,7 +63,7 @@ ResourcePack::ResourcePack(const std::string& path) : 
     return;
   }
 
-  if (unzLocateFile(file, "logo.png", nullptr) != UNZ_END_OF_LIST_OF_FILE)
+  if (unzLocateFile(file, "logo.png", 0) != UNZ_END_OF_LIST_OF_FILE)
   {
     unz_file_info64 logo_info{};
     unzGetCurrentFileInfo64(file, &logo_info, nullptr, 0, nullptr, 0, nullptr, 0);
