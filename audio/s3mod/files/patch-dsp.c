--- dsp.c.orig	2016-07-26 15:51:01 UTC
+++ dsp.c
@@ -22,20 +22,20 @@
  *  linux_dsp.c - Support for the Linux DSP driver from the Voxware(C) Drivers.
  */
 
-#ifdef LINUX
+#ifdef __FreeBSD__
 #include "config.h"
 #include <unistd.h>
 #include <stdio.h>
 #include <fcntl.h>
 #include <sys/types.h>
-#include <linux/soundcard.h>
-#include <bytesex.h>
+#include <sys/soundcard.h>
+#include <machine/endian.h>
 #include "main.h"
 #include "dsp.h"
 
 static int audio;
 
-int get_dsp_device(void)
+void get_dsp_device(void)
 {
   uint32 j;
 
@@ -68,11 +68,6 @@ int get_dsp_device(void)
     printf("Unable to get audio blocksize\n");
     exit(1);
   }
-  if ((audio_buffer_size < 4096) || (audio_buffer_size > 131072))
-  {
-    printf("Invalid audio buffer size: %d\n",audio_buffer_size);
-    exit(1);
-  }
   if (!(audio_start_buffer = (uint8 *) malloc(audio_buffer_size)))
   {
     printf("Could not get audio buffer memory!\n");
@@ -80,7 +75,6 @@ int get_dsp_device(void)
   }
   audio_end_buffer = &audio_start_buffer[audio_buffer_size];
   audio_curptr = audio_start_buffer;  
-  return;
 }
 
 void write_dsp_device(void *buf, int size) {
@@ -93,5 +87,5 @@ void close_dsp_device() {
     return;
 }
 
-#endif /* ?LINUX */
+#endif /* ?__FreeBSD__ */
 
