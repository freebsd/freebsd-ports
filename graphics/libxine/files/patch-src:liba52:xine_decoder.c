--- src/liba52/xine_decoder.c.orig	Sat Jan  5 21:43:16 2002
+++ src/liba52/xine_decoder.c	Fri Apr  5 17:52:50 2002
@@ -36,8 +36,8 @@
 #include <fcntl.h>
 
 #include "audio_out.h"
-#include "a52.h"
-#include "a52_internal.h"
+#include <a52dec/a52.h>
+#include <a52dec/a52_internal.h>
 #include "buffer.h"
 #include "xine_internal.h"
 #include "xineutils.h"
@@ -59,7 +59,7 @@
   int              frame_length, frame_todo;
   uint16_t         syncword;
 
-  a52_state_t      a52_state;
+  a52_state_t      *a52_state;
   int              a52_flags;
   int              a52_bit_rate;
   int              a52_sample_rate;
@@ -158,8 +158,11 @@
   this->pts           = 0;
   this->last_pts      = 0;
 
-  if( !this->samples )
-    this->samples = a52_init (xine_mm_accel());
+  this->a52_state = a52_init (xine_mm_accel());
+
+  if( (this->a52_state) != NULL )
+    if( !this->samples )
+      this->samples = a52_samples (this->a52_state);
 
   /*
    * find out if this driver supports a52 output
@@ -288,7 +291,7 @@
     
     a52_output_flags = this->a52_flags_map[this->a52_flags & A52_CHANNEL_MASK];
     
-    if (a52_frame (&this->a52_state, 
+    if (a52_frame (this->a52_state, 
 		   this->frame_buffer, 
 		   &a52_output_flags,
 		   &level, 384)) {
@@ -297,7 +300,7 @@
     }
     
     if (this->disable_dynrng)
-      a52_dynrng (&this->a52_state, NULL, NULL);
+      a52_dynrng (this->a52_state, NULL, NULL);
 
     this->have_lfe = a52_output_flags & A52_LFE;
     if (this->have_lfe)
@@ -337,7 +340,7 @@
     int_samples = buf->mem;
 
     for (i = 0; i < 6; i++) {
-      if (a52_block (&this->a52_state, this->samples)) {
+      if (a52_block (this->a52_state)) {
 	printf ("liba52: a52_block error\n");
 	return; 
       }
