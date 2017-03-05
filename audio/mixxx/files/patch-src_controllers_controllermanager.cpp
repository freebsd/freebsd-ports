--- src/controllers/controllermanager.cpp.orig	2015-12-29 16:10:41 UTC
+++ src/controllers/controllermanager.cpp
@@ -83,7 +83,9 @@ ControllerManager::ControllerManager(Con
     m_pMainThreadPresetEnumerator = new PresetInfoEnumerator(presetSearchPaths);
 
     // Instantiate all enumerators
+#ifdef __PORTMIDI__
     m_enumerators.append(new PortMidiEnumerator());
+#endif
 #ifdef __HSS1394__
     m_enumerators.append(new Hss1394Enumerator());
 #endif
