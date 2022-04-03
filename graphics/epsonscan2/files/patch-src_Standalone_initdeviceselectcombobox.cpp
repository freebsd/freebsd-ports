--- src/Standalone/initdeviceselectcombobox.cpp.orig	2022-01-21 22:27:00 UTC
+++ src/Standalone/initdeviceselectcombobox.cpp
@@ -80,7 +80,7 @@ void InitDeviceSelectCombobox::add_manu_ip()
         int i = this->count();
         int dev_index = DeviceList::device_list.size();
         while(i <= list_size){
-            this->CreateDisplayName("Network Scanner", device->ipAddress, i, dev_index);
+            this->CreateDisplayName((char *)"Network Scanner", device->ipAddress, i, dev_index);
             ++device;
             i++;
             dev_index++;
