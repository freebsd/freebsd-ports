--- src/qt/qt_vmmanager_system.cpp.orig	2025-08-24 19:09:53 UTC
+++ src/qt/qt_vmmanager_system.cpp
@@ -557,7 +557,7 @@ VMManagerSystem::setupVars() {
                 }
         }
     }
-    display_table[Display::Name::Machine] = machine_name;
+    display_table[VMManager::Display::Name::Machine] = machine_name;
 
     // CPU: Combine name with speed and FPU
     QString cpu_name = "Unknown";
@@ -592,34 +592,34 @@ VMManagerSystem::setupVars() {
 //    int speed_display = machine_config["cpu_speed"].toInt() / 1000000;
 //    cpu_name.append(QString::number(speed_display).prepend(" / "));
 //    cpu_name.append(QCoreApplication::translate("", "MHz").prepend(' '));
-    display_table[Display::Name::CPU] = cpu_name;
+    display_table[VMManager::Display::Name::CPU] = cpu_name;
 
     // Memory
     int divisor = (ram_granularity < 1024) ? 1 : 1024;
     QString display_unit = (divisor == 1) ? "KB" : "MB";
     auto mem_display = QString::number(machine_config["mem_size"].toInt() / divisor);
     mem_display.append(QCoreApplication::translate("", display_unit.toUtf8().constData()).prepend(' '));
-    display_table[Display::Name::Memory] = mem_display;
+    display_table[VMManager::Display::Name::Memory] = mem_display;
 
     // Video card
     int video_int = video_get_video_from_internal_name(video_config["gfxcard"].toUtf8().data());
     const device_t* video_dev = video_card_getdevice(video_int);
-    display_table[Display::Name::Video] = DeviceConfig::DeviceName(video_dev, video_get_internal_name(video_int), 1);
+    display_table[VMManager::Display::Name::Video] = DeviceConfig::DeviceName(video_dev, video_get_internal_name(video_int), 1);
 
     // Secondary video
     if (video_config.contains("gfxcard_2")) {
         int video2_int = video_get_video_from_internal_name(video_config["gfxcard_2"].toUtf8().data());
         const device_t* video2_dev = video_card_getdevice(video2_int);
-        display_table[Display::Name::Video].append(DeviceConfig::DeviceName(video2_dev, video_get_internal_name(video2_int), 1).prepend(VMManagerDetailSection::sectionSeparator));
+        display_table[VMManager::Display::Name::Video].append(DeviceConfig::DeviceName(video2_dev, video_get_internal_name(video2_int), 1).prepend(VMManagerDetailSection::sectionSeparator));
     }
 
     // Add-on video that's not Voodoo
     if (video_config.contains("8514a") && (video_config["8514a"].toInt() != 0))
-        display_table[Display::Name::Video].append(tr("IBM 8514/A Graphics").prepend(VMManagerDetailSection::sectionSeparator));
+        display_table[VMManager::Display::Name::Video].append(tr("IBM 8514/A Graphics").prepend(VMManagerDetailSection::sectionSeparator));
     if (video_config.contains("xga") && (video_config["xga"].toInt() != 0))
-        display_table[Display::Name::Video].append(tr("XGA Graphics").prepend(VMManagerDetailSection::sectionSeparator));
+        display_table[VMManager::Display::Name::Video].append(tr("XGA Graphics").prepend(VMManagerDetailSection::sectionSeparator));
     if (video_config.contains("da2") && (video_config["da2"].toInt() != 0))
-        display_table[Display::Name::Video].append(tr("IBM PS/55 Display Adapter Graphics").prepend(VMManagerDetailSection::sectionSeparator));
+        display_table[VMManager::Display::Name::Video].append(tr("IBM PS/55 Display Adapter Graphics").prepend(VMManagerDetailSection::sectionSeparator));
 
     // Voodoo
     QString voodoo_name = "";
@@ -641,7 +641,7 @@ VMManagerSystem::setupVars() {
                 break;
         }
     }
-    display_table[Display::Name::Voodoo] = voodoo_name;
+    display_table[VMManager::Display::Name::Voodoo] = voodoo_name;
 
     // Drives
     // First the number of disks
@@ -666,7 +666,7 @@ VMManagerSystem::setupVars() {
     if (disks.count()) {
         disks_display.append(" / ").append(bus_types.keys().join(", ").toUpper());
     }
-//    display_table[Display::Name::Disks] = disks_display;
+//    display_table[VMManager::Display::Name::Disks] = disks_display;
 
     // Drives
     QString new_disk_display;
@@ -699,7 +699,7 @@ VMManagerSystem::setupVars() {
     if(new_disk_display.isEmpty()) {
         new_disk_display = tr("No disks");
     }
-    display_table[Display::Name::Disks] = new_disk_display;
+    display_table[VMManager::Display::Name::Disks] = new_disk_display;
 
     // Floppy & CD-ROM
     QStringList floppyDevices;
@@ -748,8 +748,8 @@ VMManagerSystem::setupVars() {
         }
     }
 
-    display_table[Display::Name::Floppy] = floppyDevices.join(VMManagerDetailSection::sectionSeparator);
-    display_table[Display::Name::CD]     = cdromDevices.join(VMManagerDetailSection::sectionSeparator);
+    display_table[VMManager::Display::Name::Floppy] = floppyDevices.join(VMManagerDetailSection::sectionSeparator);
+    display_table[VMManager::Display::Name::CD]     = cdromDevices.join(VMManagerDetailSection::sectionSeparator);
 
     // Removable disks & MO
     QStringList rdiskDevices;
@@ -786,8 +786,8 @@ VMManagerSystem::setupVars() {
         }
     }
 
-    display_table[Display::Name::RDisk] = rdiskDevices.join(VMManagerDetailSection::sectionSeparator);
-    display_table[Display::Name::MO]    = moDevices.join(VMManagerDetailSection::sectionSeparator);
+    display_table[VMManager::Display::Name::RDisk] = rdiskDevices.join(VMManagerDetailSection::sectionSeparator);
+    display_table[VMManager::Display::Name::MO]    = moDevices.join(VMManagerDetailSection::sectionSeparator);
 
 
     // SCSI controllers
@@ -805,7 +805,7 @@ VMManagerSystem::setupVars() {
             }
         }
     }
-    display_table[Display::Name::SCSIController] = scsiControllers.join(VMManagerDetailSection::sectionSeparator);
+    display_table[VMManager::Display::Name::SCSIController] = scsiControllers.join(VMManagerDetailSection::sectionSeparator);
 
     // Hard and floppy disk controllers
     QStringList storageControllers;
@@ -864,7 +864,7 @@ VMManagerSystem::setupVars() {
     if (storage_config.contains(ide_qua_internal_name) && (storage_config[ide_qua_internal_name].toInt() != 0))
         storageControllers.append(DeviceConfig::DeviceName(hdc_get_device(hdc_get_from_internal_name(ide_qua_internal_name.toUtf8().data())), ide_qua_internal_name.toUtf8().constData(), 1));
 
-    display_table[Display::Name::StorageController] = storageControllers.join(VMManagerDetailSection::sectionSeparator);
+    display_table[VMManager::Display::Name::StorageController] = storageControllers.join(VMManagerDetailSection::sectionSeparator);
 
     // Audio
     QStringList sndCards;
@@ -889,7 +889,7 @@ VMManagerSystem::setupVars() {
     if(sndCards.isEmpty()) {
         sndCards.append(tr("None"));
     }
-    display_table[Display::Name::Audio] = sndCards.join(VMManagerDetailSection::sectionSeparator);
+    display_table[VMManager::Display::Name::Audio] = sndCards.join(VMManagerDetailSection::sectionSeparator);
 
     // MIDI
     QString midiOutDev;
@@ -901,7 +901,7 @@ VMManagerSystem::setupVars() {
             midiOutDev = midiDevName;
         }
     }
-    display_table[Display::Name::MidiOut] = midiOutDev;
+    display_table[VMManager::Display::Name::MidiOut] = midiOutDev;
 
     // midi_device = mt32 (output)
     // mpu401_standalone = 1
@@ -940,21 +940,21 @@ VMManagerSystem::setupVars() {
     if(nicList.isEmpty()) {
         nicList.append(tr("None"));
     }
-    display_table[Display::Name::NIC] = nicList.join(VMManagerDetailSection::sectionSeparator);
+    display_table[VMManager::Display::Name::NIC] = nicList.join(VMManagerDetailSection::sectionSeparator);
 
     // Input (Keyboard)
     if (input_config.contains("keyboard_type")) {
         auto keyboard_internal_name = input_config["keyboard_type"];
         auto keyboard_dev = keyboard_get_from_internal_name(keyboard_internal_name.toUtf8().data());
         auto keyboard_dev_name = DeviceConfig::DeviceName(keyboard_get_device(keyboard_dev), keyboard_get_internal_name(keyboard_dev), 0);
-        display_table[Display::Name::Keyboard] = keyboard_dev_name;
+        display_table[VMManager::Display::Name::Keyboard] = keyboard_dev_name;
     }
 
     // Input (Mouse)
     auto mouse_internal_name = input_config["mouse_type"];
     auto mouse_dev = mouse_get_from_internal_name(mouse_internal_name.toUtf8().data());
     auto mouse_dev_name = DeviceConfig::DeviceName(mouse_get_device(mouse_dev), mouse_get_internal_name(mouse_dev), 0);
-    display_table[Display::Name::Mouse] = mouse_dev_name;
+    display_table[VMManager::Display::Name::Mouse] = mouse_dev_name;
 
     // Input (joystick)
     QString joystickDevice;
@@ -965,7 +965,7 @@ VMManagerSystem::setupVars() {
             joystickDevice = joystickName;
         }
     }
-    display_table[Display::Name::Joystick] = joystickDevice;
+    display_table[VMManager::Display::Name::Joystick] = joystickDevice;
 
     // # Ports
     // Serial
@@ -1026,8 +1026,8 @@ VMManagerSystem::setupVars() {
         if (portIndex == PARALLEL_MAX)
             break;
     }
-    display_table[Display::Name::Serial]   = (serialFinal.empty() ?  tr("None") : serialFinal.join(", "));
-    display_table[Display::Name::Parallel] = (lptFinal.empty()    ?  tr("None") : lptFinal.join((hasLptDevices ? VMManagerDetailSection::sectionSeparator : ", ")));
+    display_table[VMManager::Display::Name::Serial]   = (serialFinal.empty() ?  tr("None") : serialFinal.join(", "));
+    display_table[VMManager::Display::Name::Parallel] = (lptFinal.empty()    ?  tr("None") : lptFinal.join((hasLptDevices ? VMManagerDetailSection::sectionSeparator : ", ")));
 
     // ISA RTC
     QString isartc_dev_name = "";
@@ -1036,7 +1036,7 @@ VMManagerSystem::setupVars() {
         auto isartc_dev = isartc_get_from_internal_name(isartc_internal_name.toUtf8().data());
         isartc_dev_name = DeviceConfig::DeviceName(isartc_get_device(isartc_dev), isartc_get_internal_name(isartc_dev), 0);
     }
-    display_table[Display::Name::IsaRtc] = isartc_dev_name;
+    display_table[VMManager::Display::Name::IsaRtc] = isartc_dev_name;
 
     // ISA RAM
     QStringList IsaMemCards;
@@ -1053,7 +1053,7 @@ VMManagerSystem::setupVars() {
             }
         }
     }
-    display_table[Display::Name::IsaMem] = IsaMemCards.join(VMManagerDetailSection::sectionSeparator);
+    display_table[VMManager::Display::Name::IsaMem] = IsaMemCards.join(VMManagerDetailSection::sectionSeparator);
 
     // ISA ROM
     QStringList IsaRomCards;
@@ -1070,7 +1070,7 @@ VMManagerSystem::setupVars() {
             }
         }
     }
-    display_table[Display::Name::IsaRom] = IsaRomCards.join(VMManagerDetailSection::sectionSeparator);
+    display_table[VMManager::Display::Name::IsaRom] = IsaRomCards.join(VMManagerDetailSection::sectionSeparator);
 }
 
 bool
@@ -1119,7 +1119,7 @@ QString
     processStatusChanged();
 }
 QString
-VMManagerSystem::getDisplayValue(Display::Name key)
+VMManagerSystem::getDisplayValue(VMManager::Display::Name key)
 {
     return (display_table.contains(key)) ? display_table[key] : "";
 }
