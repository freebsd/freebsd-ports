--- audio/midiparser.cpp.orig	2021-12-23 03:52:30 UTC
+++ audio/midiparser.cpp
@@ -143,18 +143,9 @@
 
     if (ptr)
     {
-        uint16_t* tmp;
-        tmp = (uint16_t*)&ptr[MIDI_HEADER_FMT];
-        reverseOrder( (char*)tmp, 2);
-        header->format = *tmp;
-
-        tmp = (uint16_t*)&ptr[MIDI_HEADER_TRACK_COUNT];
-        reverseOrder((char*)tmp, 2);
-        header->trackCount = *tmp;
-
-        tmp = (uint16_t*)&ptr[MIDI_HEADER_PPQ];
-        reverseOrder((char*)tmp, 2);
-        header->PPQ = *tmp;
+        header->format = (ptr[MIDI_HEADER_FMT] << 8) | ptr[MIDI_HEADER_FMT + 1];
+        header->trackCount = (ptr[MIDI_HEADER_TRACK_COUNT] << 8) | ptr[MIDI_HEADER_TRACK_COUNT + 1];
+        header->PPQ = (ptr[MIDI_HEADER_PPQ] << 8) | ptr[MIDI_HEADER_PPQ + 1];
 
         uint8_t* diff = ptr;
         diff = (uint8_t*)((uint8_t*)diff - (uint8_t*)(data));
@@ -188,10 +179,8 @@
     char* ptr = (char*)findSubString( (char*)data, (char*)MIDI_TRACK_STRING, size);
     if (ptr)
     {
-        uint32_t* tmp;
-        tmp = (uint32_t*)&ptr[MIDI_TRACK_LENGTH];
-        reverseOrder( (char*)tmp, 4);
-        track->length = *tmp;
+        uint8_t* tmp = (uint8_t*)&ptr[MIDI_TRACK_LENGTH];
+        track->length = ((uint32_t)tmp[0] << 24) | ((uint32_t)tmp[1] << 16) | (tmp[2] << 8) | tmp[3];
         //MIDI_Printf("TRACKLENG: ", track->length);
         return &ptr[MIDI_TRACK_LENGTH+4];
     }
