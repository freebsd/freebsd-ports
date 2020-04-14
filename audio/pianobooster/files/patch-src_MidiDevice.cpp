--- src/MidiDevice.cpp.orig	2020-02-25 07:45:06 UTC
+++ src/MidiDevice.cpp
@@ -32,9 +32,9 @@
     #include "MidiDeviceFluidSynth.h"
 #endif
 
+#include <QDebug>
 
 
-
 CMidiDevice::CMidiDevice()
 {
     m_rtMidiDevice = new CMidiDeviceRt();
@@ -65,6 +65,8 @@ QStringList CMidiDevice::getMidiPortList(midiType_t ty
     QStringList list;
 #if EXPERIMENTAL_USE_FLUIDSYNTH
     list <<  m_fluidSynthMidiDevice->getMidiPortList(type);
+    if (list.empty())
+      qWarning() << "FluidSynth midi device didn't return any midi ports of midi type=" << type;
 #endif
     list <<  m_rtMidiDevice->getMidiPortList(type);
 
