--- audio/midiplayback.cpp.orig	2021-12-23 03:52:30 UTC
+++ audio/midiplayback.cpp
@@ -672,8 +672,9 @@
 
    case MIDI_META_TEMPO:
       existingBPM = MIDIHdr->currentState.BPM;
-      reverseOrder((char*) event->event.metaEvent.data, event->event.metaEvent.length);
-      memcpy(&MIDIHdr->currentState.BPM, event->event.metaEvent.data, event->event.metaEvent.length); //*bpmptr;
+      MIDIHdr->currentState.BPM = ((uint32_t)event->event.metaEvent.data[0] << 16)
+                                | (event->event.metaEvent.data[1] << 8)
+                                | event->event.metaEvent.data[2];
 
       MIDIHdr->currentState.BPM = BPM(MIDIHdr->currentState.BPM);
       MPB_SetTickRate(MIDIHdr->currentState.BPM, MIDIHdr->PPQ);
