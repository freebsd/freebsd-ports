--- source/timidity/readmidi.cpp.orig	2022-12-31 03:37:53 UTC
+++ source/timidity/readmidi.cpp
@@ -569,7 +569,7 @@ MidiEvent* read_midi_mem(MidiSong* song, void* mimage,
 	int32 len, divisions;
 	int16 format, tracks, divisions_tmp;
 	int i;
-	char tmp[4];
+	char tmp[12];
 
 	song->midi_image = (uint8*)mimage;
 	song->image_left = msize;
