--- header.cc.orig	Thu Jun 23 22:14:35 1994
+++ header.cc	Thu Nov 21 16:42:47 2002
@@ -20,15 +20,15 @@
 
 /*
  *  Changes from version 1.1 to 1.2:
- *    - iostreams manipulator calls like "cerr << setw (2) << ..." replaced by
- *      "cerr.width (2); ..." due to problems with older GNU C++ releases.
+ *    - iostreams manipulator calls like "std::cerr << setw (2) << ..." replaced by
+ *      "std::cerr.width (2); ..." due to problems with older GNU C++ releases.
  *    - syncword recognition slightly changed
  */
 
 #include <sys/types.h>
 #include <unistd.h>
-#include <iostream.h>
-#include <iomanip.h>
+#include <iostream>
+#include <iomanip>
 #include <stdlib.h>
 #include "header.h"
 
@@ -36,7 +36,7 @@
 const uint32 Header::frequencies[3] = { 44100, 48000, 32000 };
 
 
-bool Header::read_header (Ibitstream *stream, Crc16 **crcp)
+boolean Header::read_header (Ibitstream *stream, Crc16 **crcp)
 {
   uint32 headerstring;
 
@@ -45,41 +45,41 @@
 
   if ((headerstring & 0xFFF80000) != 0xFFF80000)
   {
-    cerr << "invalid syncword 0x";
-    cerr.width (8);
-    cerr.fill ('0');
-    cerr << hex << headerstring
-	 << " found at fileoffset " << dec
+    std::cerr << "invalid syncword 0x";
+    std::cerr.width (8);
+    std::cerr.fill ('0');
+    std::cerr << std::hex << headerstring
+	 << " found at fileoffset " << std::dec
 	 << lseek (stream->filedescriptor (), 0, SEEK_CUR) - 4 << '\n';
     return False;
   }
 
   if ((h_layer = (headerstring >> 17) & 3) == 0)
   {
-    cerr << "unknown layer identifier found!\n";
+    std::cerr << "unknown layer identifier found!\n";
     exit (1);
   }
   h_layer = 4 - h_layer;		// now 1 means Layer I and 3 means Layer III
   if (h_layer == 3)
   {
-    cerr << "Sorry, Layer III not implemented!\n";
+    std::cerr << "Sorry, Layer III not implemented!\n";
     exit (1);
   }
   h_protection_bit = (headerstring >> 16) & 1;
   if ((h_bitrate_index = (headerstring >> 12) & 0xF) == 15)
   {
-    cerr << "unknown bitrate index found!\n";
+    std::cerr << "unknown bitrate index found!\n";
     exit (1);
   }
   if (!h_bitrate_index)
   {
-    cerr << "free format not yet implemented!\n";
+    std::cerr << "free format not yet implemented!\n";
     exit (1);
   }
 
   if ((h_sample_frequency = (e_sample_frequency)((headerstring >> 10) & 3)) == 3)
   {
-    cerr << "unknown sample frequency!\n";
+    std::cerr << "unknown sample frequency!\n";
     exit (1);
   }
   h_padding_bit = (headerstring >> 9) & 1;
@@ -90,7 +90,7 @@
 	 h_mode != single_channel) ||
 	(h_bitrate_index >= 11 && h_mode == single_channel))
     {
-      cerr << "illegal combination of mode and bitrate in a layer II stream:\n"
+      std::cerr << "illegal combination of mode and bitrate in a layer II stream:\n"
 	      "  mode: " << mode_string ()
 	   << "\n  bitrate: " << bitrate_string () << '\n';
       exit (1);
@@ -161,7 +161,7 @@
   static const int32 bitrates_layer_2[15] = {
     0 /*free format*/, 32000, 48000, 56000, 64000, 80000, 96000,
     112000, 128000, 160000, 192000, 224000, 256000, 320000, 384000 };
-  static const samplefrequencies[3] = { 44100, 48000, 32000 };
+  static const int32 samplefrequencies[3] = { 44100, 48000, 32000 };
   uint32 framesize;
 
   if (h_layer == 1)
