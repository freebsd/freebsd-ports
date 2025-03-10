--- src/Controller/Src/Finder/Finder.cpp.orig	2024-09-12 07:10:37 UTC
+++ src/Controller/Src/Finder/Finder.cpp
@@ -52,6 +52,9 @@ namespace epsonscan {
   }
   SDIDeviceInfo* Finder::GetDevicesPointer()
   {
+   if (devices_.size() == 0) {
+    return nullptr;
+   }
    return &devices_[0];
   }
   int32_t Finder::GetDevicesCount() const
