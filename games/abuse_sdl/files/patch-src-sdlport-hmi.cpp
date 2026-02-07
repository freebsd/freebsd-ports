hmi.cpp:302:97: error: non-constant-expression cannot be narrowed from type 'int' to 'uint8_t'
      (aka 'unsigned char') in initializer list [-Wc++11-narrowing]
  ...0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x01, 0x00, (num_tracks + 1), 0x00, 0xC0 };
                                                                 ^~~~~~~~~~~~~~~~
hmi.cpp:302:97: note: insert an explicit cast to silence this issue
  ...0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x01, 0x00, (num_tracks + 1), 0x00, 0xC0 };
                                                                 ^~~~~~~~~~~~~~~~
                                                                 static_cast<uint8_t>( )

--- src/sdlport/hmi.cpp.orig	2011-05-09 07:58:30 UTC
+++ src/sdlport/hmi.cpp
@@ -299,7 +299,7 @@ uint8_t* load_hmi(char const *filename, uint32_t &data
     uint8_t num_tracks = (next_offset - offset_tracks) / sizeof(uint32_t);
 
     // Write Midi file header
-    uint8_t midi_header[] = { 0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x01, 0x00, (num_tracks + 1), 0x00, 0xC0 };
+    uint8_t midi_header[] = { 0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x01, 0x00, (uint8_t)(num_tracks + 1), 0x00, 0xC0 };
     memcpy(output_buffer_ptr, midi_header, 14);
     output_buffer_ptr += 14;
 
