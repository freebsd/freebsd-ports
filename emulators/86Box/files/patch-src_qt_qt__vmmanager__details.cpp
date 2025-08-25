--- src/qt/qt_vmmanager_details.cpp.orig	2025-08-24 19:07:21 UTC
+++ src/qt/qt_vmmanager_details.cpp
@@ -248,52 +248,52 @@ VMManagerDetails::updateConfig(VMManagerSystem *passed
 
     // System
     systemSection->clear();
-    systemSection->addSection("Machine", passed_sysconfig->getDisplayValue(Display::Name::Machine));
-    systemSection->addSection("CPU", passed_sysconfig->getDisplayValue(Display::Name::CPU));
-    systemSection->addSection("Memory", passed_sysconfig->getDisplayValue(Display::Name::Memory));
+    systemSection->addSection("Machine", passed_sysconfig->getDisplayValue(VMManager::Display::Name::Machine));
+    systemSection->addSection("CPU", passed_sysconfig->getDisplayValue(VMManager::Display::Name::CPU));
+    systemSection->addSection("Memory", passed_sysconfig->getDisplayValue(VMManager::Display::Name::Memory));
 
     // Video
     videoSection->clear();
-    videoSection->addSection("Video", passed_sysconfig->getDisplayValue(Display::Name::Video));
-    if(!passed_sysconfig->getDisplayValue(Display::Name::Voodoo).isEmpty()) {
-        videoSection->addSection("Voodoo", passed_sysconfig->getDisplayValue(Display::Name::Voodoo));
+    videoSection->addSection("Video", passed_sysconfig->getDisplayValue(VMManager::Display::Name::Video));
+    if(!passed_sysconfig->getDisplayValue(VMManager::Display::Name::Voodoo).isEmpty()) {
+        videoSection->addSection("Voodoo", passed_sysconfig->getDisplayValue(VMManager::Display::Name::Voodoo));
     }
 
     // Disks
     storageSection->clear();
-    storageSection->addSection("Disks", passed_sysconfig->getDisplayValue(Display::Name::Disks));
-    storageSection->addSection("Floppy", passed_sysconfig->getDisplayValue(Display::Name::Floppy));
-    storageSection->addSection("CD-ROM", passed_sysconfig->getDisplayValue(Display::Name::CD));
-    storageSection->addSection("Removable disks", passed_sysconfig->getDisplayValue(Display::Name::RDisk));
-    storageSection->addSection("MO", passed_sysconfig->getDisplayValue(Display::Name::MO));
-    storageSection->addSection("SCSI", passed_sysconfig->getDisplayValue(Display::Name::SCSIController));
-    storageSection->addSection("Controllers", passed_sysconfig->getDisplayValue(Display::Name::StorageController));
+    storageSection->addSection("Disks", passed_sysconfig->getDisplayValue(VMManager::Display::Name::Disks));
+    storageSection->addSection("Floppy", passed_sysconfig->getDisplayValue(VMManager::Display::Name::Floppy));
+    storageSection->addSection("CD-ROM", passed_sysconfig->getDisplayValue(VMManager::Display::Name::CD));
+    storageSection->addSection("Removable disks", passed_sysconfig->getDisplayValue(VMManager::Display::Name::RDisk));
+    storageSection->addSection("MO", passed_sysconfig->getDisplayValue(VMManager::Display::Name::MO));
+    storageSection->addSection("SCSI", passed_sysconfig->getDisplayValue(VMManager::Display::Name::SCSIController));
+    storageSection->addSection("Controllers", passed_sysconfig->getDisplayValue(VMManager::Display::Name::StorageController));
 
     // Audio
     audioSection->clear();
-    audioSection->addSection("Audio", passed_sysconfig->getDisplayValue(Display::Name::Audio));
-    audioSection->addSection("MIDI Out", passed_sysconfig->getDisplayValue(Display::Name::MidiOut));
+    audioSection->addSection("Audio", passed_sysconfig->getDisplayValue(VMManager::Display::Name::Audio));
+    audioSection->addSection("MIDI Out", passed_sysconfig->getDisplayValue(VMManager::Display::Name::MidiOut));
 
     // Network
     networkSection->clear();
-    networkSection->addSection("NIC", passed_sysconfig->getDisplayValue(Display::Name::NIC));
+    networkSection->addSection("NIC", passed_sysconfig->getDisplayValue(VMManager::Display::Name::NIC));
 
     // Input
     inputSection->clear();
-    inputSection->addSection("Keyboard", passed_sysconfig->getDisplayValue(Display::Name::Keyboard));
-    inputSection->addSection("Mouse", passed_sysconfig->getDisplayValue(Display::Name::Mouse));
-    inputSection->addSection("Joystick", passed_sysconfig->getDisplayValue(Display::Name::Joystick));
+    inputSection->addSection("Keyboard", passed_sysconfig->getDisplayValue(VMManager::Display::Name::Keyboard));
+    inputSection->addSection("Mouse", passed_sysconfig->getDisplayValue(VMManager::Display::Name::Mouse));
+    inputSection->addSection("Joystick", passed_sysconfig->getDisplayValue(VMManager::Display::Name::Joystick));
 
     // Ports
     portsSection->clear();
-    portsSection->addSection("Serial ports", passed_sysconfig->getDisplayValue(Display::Name::Serial));
-    portsSection->addSection("Parallel ports", passed_sysconfig->getDisplayValue(Display::Name::Parallel));
+    portsSection->addSection("Serial ports", passed_sysconfig->getDisplayValue(VMManager::Display::Name::Serial));
+    portsSection->addSection("Parallel ports", passed_sysconfig->getDisplayValue(VMManager::Display::Name::Parallel));
 
     // Other devices
     otherSection->clear();
-    otherSection->addSection("ISA RTC", passed_sysconfig->getDisplayValue(Display::Name::IsaRtc));
-    otherSection->addSection("ISA RAM", passed_sysconfig->getDisplayValue(Display::Name::IsaMem));
-    otherSection->addSection("ISA ROM", passed_sysconfig->getDisplayValue(Display::Name::IsaRom));
+    otherSection->addSection("ISA RTC", passed_sysconfig->getDisplayValue(VMManager::Display::Name::IsaRtc));
+    otherSection->addSection("ISA RAM", passed_sysconfig->getDisplayValue(VMManager::Display::Name::IsaMem));
+    otherSection->addSection("ISA ROM", passed_sysconfig->getDisplayValue(VMManager::Display::Name::IsaRom));
 
     systemSection->setSections();
     videoSection->setSections();
