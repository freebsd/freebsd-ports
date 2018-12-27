--- src/controllers/controllermanager.cpp	2018-04-15 13:30:27.000000000 -0500
+++ src/controllers/controllermanager.cpp	2018-04-21 22:34:32.638474000 -0500
@@ -127,7 +127,9 @@
 
     // Instantiate all enumerators. Enumerators can take a long time to
     // construct since they interact with host MIDI APIs.
+#ifdef __PORTMIDI__
     m_enumerators.append(new PortMidiEnumerator());
+#endif
 #ifdef __HSS1394__
     m_enumerators.append(new Hss1394Enumerator());
 #endif
