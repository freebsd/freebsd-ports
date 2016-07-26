--- src/controllers/controllermanager.cpp.orig	2013-05-08 23:20:26 UTC
+++ src/controllers/controllermanager.cpp
@@ -12,7 +12,10 @@
 #include "controllers/defs_controllers.h"
 #include "controllers/controllerlearningeventfilter.h"
 
+#ifdef __PORTMIDI__
 #include "controllers/midi/portmidienumerator.h"
+#endif
+
 #ifdef __HSS1394__
     #include "controllers/midi/hss1394enumerator.h"
 #endif
@@ -78,7 +81,9 @@ ControllerManager::ControllerManager(Con
     m_pPresetInfoManager = new PresetInfoEnumerator(m_pConfig);
 
     // Instantiate all enumerators
+#ifdef __PORTMIDI__
     m_enumerators.append(new PortMidiEnumerator());
+#endif
 #ifdef __HSS1394__
     m_enumerators.append(new Hss1394Enumerator());
 #endif
