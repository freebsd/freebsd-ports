--- src/midi/mididevicemanager.cpp.orig	2011-12-24 11:53:19.000000000 +0900
+++ src/midi/mididevicemanager.cpp	2012-01-16 06:08:07.000000000 +0900
@@ -28,7 +28,9 @@
 {
     m_pConfig = pConfig;
 
+#ifdef __PORTMIDI__
     m_pPMEnumerator = new PortMidiEnumerator();
+#endif
 #ifdef __HSS1394__
     m_pHSSEnumerator = new Hss1394Enumerator();
 #endif
@@ -37,7 +39,9 @@
 MidiDeviceManager::~MidiDeviceManager()
 {
     //Delete enumerators and they'll delete their Devices
+#ifdef __PORTMIDI__
     delete m_pPMEnumerator;
+#endif
 #ifdef __HSS1394__
     delete m_pHSSEnumerator;
 #endif
@@ -78,7 +82,9 @@
     bool bMatchedCriteria = false;   //Whether or not the current device matched the filtering criteria
 
     if (m_devices.empty()) {
+#ifdef __PORTMIDI__
         m_devices = m_pPMEnumerator->queryDevices();
+#endif
 #ifdef __HSS1394__
         m_devices.append(m_pHSSEnumerator->queryDevices());
 #endif
