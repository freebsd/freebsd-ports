--- dsp_mixxer.c.orig	Mon Jun 22 12:39:39 1998
+++ dsp_mixxer.c	Sat Jul 14 21:55:28 2007
@@ -15,15 +15,11 @@
 ***************************************************************************/
 #include <stdio.h>
 #include <math.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
-#ifdef Linux
- #include <sys/soundcard.h>
-#elif FreeBSD
- #include <machine/soundcard.h>
-#endif
+#include <sys/soundcard.h>
 #include "funktracker_defs.h"
 #include "funktracker.h"
 #include "funkload.h"
@@ -301,12 +297,12 @@
 
   for(sample_no = 0;sample_no < mix_buffer_size;sample_no++)
   {
-    if(chmix[chan_no].funkctrl & 0x2)
+    if(chmix[chan_no].funkctrl & 0x2) {
 #pragma pack(1)
       sam = *((sDB *)chmix[chan_no].sample_addr +
             (unsigned long)chmix[chan_no].sample_ptr);
 #pragma pack()
-    else
+    } else
       sam = 0;
 
 #ifdef DIGITAL_ECHOING
@@ -363,12 +359,12 @@
   shift_t = 8 + shift_table[funk_info.no_active_channels];
   for(sample_no = 0;sample_no < mix_buffer_size;sample_no++)
   {
-    if(chmix[chan_no].funkctrl & 0x2)
+    if(chmix[chan_no].funkctrl & 0x2) {
 #pragma pack(1)
       sam = *((sDW *)chmix[chan_no].sample_addr +
             (unsigned long)chmix[chan_no].sample_ptr);
 #pragma pack()
-    else
+    } else
       sam = 0;
 #ifdef DIGITAL_ECHOING
     sam_reverb = *(chmix[chan_no].echo_buffer +
