--- src/cdrom/CDAFReader_Vorbis.cpp.orig	2024-04-05 02:27:32 UTC
+++ src/cdrom/CDAFReader_Vorbis.cpp
@@ -24,7 +24,7 @@
 #include "CDAFReader_Vorbis.h"
 
 #ifdef HAVE_EXTERNAL_TREMOR
- #include <tremor/ivorbisfile.h>
+ #include <vorbis/vorbisfile.h>
 #else
  #include <mednafen/tremor/ivorbisfile.h>
 #endif
@@ -143,7 +143,7 @@ uint64 CDAFReader_Vorbis::Read_(int16 *buffer, uint64 
 
  while(toread > 0)
  {
-  long didread = ov_read(&ovfile, (char*)tw_buf, toread, &cursection);
+  long didread = ov_read(&ovfile, (char*)tw_buf, toread, 0, 2, 1, &cursection);
 
   if(didread == 0)
    break;
