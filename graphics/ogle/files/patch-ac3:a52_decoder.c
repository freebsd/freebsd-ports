--- ac3/a52_decoder.c.orig	Sun Dec  2 19:37:37 2001
+++ ac3/a52_decoder.c	Fri Apr 12 18:25:07 2002
@@ -46,6 +46,7 @@
 
 /* A/52 */
 static ao_instance_t * output = NULL;
+static a52_state_t *state;
 static sample_t * samples;
 static int disable_dynrng = 0;
 static clocktime_t a52_decode_data(uint8_t *start, uint8_t *end);
@@ -216,15 +217,20 @@
 
   {
     uint32_t accel;
-    accel = MM_ACCEL_MLIB;
+    accel = MM_ACCEL_DJBFFT;
 
     open_output(get_speaker_flags());
 
-    samples = a52_init(accel);
-    if(samples == NULL) {
+    state = a52_init(accel);
+    if(state == NULL) {
         FATAL("A/52 init failed\n");
         exit(1);
     }
+    samples = a52_samples(state);
+    if(samples == NULL) {
+        FATAL("A/52 samples failed\n");
+        exit(1);
+    }
   }
 
   if(msgqid != -1) {
@@ -675,7 +681,6 @@
 }
 
 static clocktime_t a52_decode_data(uint8_t *start, uint8_t *end) {
-  static a52_state_t state;
   
   static uint8_t buf[3840];
   static uint8_t *bufptr = buf;
@@ -736,17 +741,16 @@
 	
 	flags = speaker_flags;
 	flags |= A52_ADJUST_LEVEL;
-	memset(&state, 0, sizeof(a52_state_t));
 	/* flags (speaker) [in/out] level [in/out] bias [in] */
-	if(a52_frame(&state, buf, &flags, &level, bias)) {
+	if(a52_frame(state, buf, &flags, &level, bias)) {
 	  DNOTE("a52_frame() error\n");
 	  goto error;
 	}
 
 	if(disable_dynrng)
-	  a52_dynrng(&state, NULL, NULL);
+	  a52_dynrng(state, NULL, NULL);
 	for(i = 0; i < 6; i++) {
-	  if(a52_block(&state, samples)) {
+	  if(a52_block(state)) {
 	    DNOTE("a52_block() error\n");
 	    goto error;
 	  }
