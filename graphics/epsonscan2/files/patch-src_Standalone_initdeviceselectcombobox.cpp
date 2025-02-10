--- src/Standalone/initdeviceselectcombobox.cpp.orig	2024-09-12 07:10:43 UTC
+++ src/Standalone/initdeviceselectcombobox.cpp
@@ -77,7 +77,7 @@ void InitDeviceSelectCombobox::add_manu_ip()
         int i = this->count();
         int dev_index = DeviceList::device_list.size();
         while(i <= list_size){
-            this->CreateDisplayName("Network Scanner", device->ipAddress, i, dev_index);
+            this->CreateDisplayName((char *)"Network Scanner", device->ipAddress, i, dev_index);
             ++device;
             i++;
             dev_index++;
