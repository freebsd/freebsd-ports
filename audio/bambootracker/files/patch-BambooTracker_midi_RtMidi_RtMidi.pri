--- BambooTracker/midi/RtMidi/RtMidi.pri.orig	2020-06-28 12:11:07 UTC
+++ BambooTracker/midi/RtMidi/RtMidi.pri
@@ -30,5 +30,3 @@ macx {
     DEFINES += __MACOSX_CORE__
     LIBS += -framework CoreMIDI -framework CoreAudio -framework CoreFoundation
 }
-
-DEFINES += __RTMIDI_DUMMY__
