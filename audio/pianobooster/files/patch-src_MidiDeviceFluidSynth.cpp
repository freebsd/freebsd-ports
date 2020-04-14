--- src/MidiDeviceFluidSynth.cpp.orig	2019-07-09 08:30:16 UTC
+++ src/MidiDeviceFluidSynth.cpp
@@ -30,6 +30,7 @@
 
 #include <QString>
 #include <QDir>
+#include <QDebug>
 #include <string>
 
 CMidiDeviceFluidSynth::CMidiDeviceFluidSynth()
@@ -54,7 +55,7 @@ void CMidiDeviceFluidSynth::init()
 
 QStringList CMidiDeviceFluidSynth::getMidiPortList(midiType_t type)
 {
-
+    qInfo() << "YURI CMidiDeviceFluidSynth::getMidiPortList type=" << type << " MIDI_OUTPUT=" << MIDI_OUTPUT;
     if (type != MIDI_OUTPUT) // Only has an output
         return QStringList();
 
@@ -62,11 +63,13 @@ QStringList CMidiDeviceFluidSynth::getMidiPortList(mid
     QDir dirSoundFont("soundfont");
     dirSoundFont.setFilter(QDir::Files);
     QStringList fileNames = dirSoundFont.entryList();
+    qInfo() << "YURI CMidiDeviceFluidSynth::getMidiPortList numFileNames=" << fileNames.size() << " in dir=" << dirSoundFont;
 
     QStringList portNames;
 
     for (int i = 0; i < fileNames.size(); i++)
     {
+    qInfo() << "YURI CMidiDeviceFluidSynth::getMidiPortList file[" << i << "]=" << fileNames.at(i);
         if ( fileNames.at(i).endsWith(".sf2", Qt::CaseInsensitive ) )
         {
             portNames  +=  fileNames.at(i);
