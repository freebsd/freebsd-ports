--- src/hairtunes.c.orig	2011-09-23 19:55:48 UTC
+++ src/hairtunes.c
@@ -25,7 +25,7 @@
  */
 
 #define XBMC
-//#defined HAS_AO
+#define HAS_AO
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -45,7 +45,7 @@
 #include <sys/signal.h>
 #include <fcntl.h>
 #ifdef HAS_AO
-#include <ao/ao.h>
+#include "ao.h"
 #endif
 
 #ifdef FANCY_RESAMPLING
@@ -89,7 +89,6 @@ int pipe_handle = -1;
 // maximal resampling shift - conservative
 #define OUTFRAME_BYTES (4*(frame_size+3))
 
-
 alac_file *decoder_info;
 
 #ifdef FANCY_RESAMPLING
@@ -122,8 +121,8 @@ pthread_mutex_t ab_mutex;
 pthread_cond_t ab_buffer_ready;
 
 static void die(char *why) {
-    fprintf(stderr, "FATAL: %s\n", why);
-    exit(1);
+    xprintf("FATAL: %s\n", why);
+    //exit(1);
 }
 
 static int hex2bin(unsigned char *buf, char *hex) {
@@ -246,13 +245,13 @@ int hairtunes_init(char *pAeskey, char *
             continue;
         }
         if (!strcmp(line, "exit\n")) {
-            exit(0);
+            ;//exit(0);
         }
         if (!strcmp(line, "flush\n")) {
             hairtunes_flush();
         }
     }
-    fprintf(stderr, "bye!\n");
+    xprintf("bye!\n");
     fflush(stderr);
 #endif
 
@@ -263,18 +262,28 @@ void hairtunes_setvolume(float f)
 {
   assert(f<=0);
   if (debug)
-      fprintf(stderr, "VOL: %lf\n", f);
+      xprintf("VOL: %lf\n", f);
   volume = pow(10.0,0.05*f);
   fix_volume = 65536.0 * volume;
 }
 
+void hairtunes_set_metadata(const char *buffer, unsigned int size)
+{
+  g_ao.ao_set_metadata(buffer, size);
+}
+
+void hairtunes_set_metadata_coverart(const char *buffer, unsigned int size)
+{
+  g_ao.ao_set_metadata_coverart(buffer, size);
+}
+
 void hairtunes_flush(void)
 {
   pthread_mutex_lock(&ab_mutex);
   ab_resync();
   pthread_mutex_unlock(&ab_mutex);
   if (debug)
-      fprintf(stderr, "FLUSH\n");
+      xprintf("FLUSH\n");
 }
 
 #ifdef HAIRTUNES_STANDALONE
@@ -424,7 +433,7 @@ static void buffer_put_packet(seq_t seqn
     } else if (seq_order(ab_read, seqno)) {     // late but not yet played
         abuf = audio_buffer + BUFIDX(seqno);
     } else {    // too late.
-        fprintf(stderr, "\nlate packet %04X (%04X:%04X)\n", seqno, ab_read, ab_write);
+        xprintf("\nlate packet %04X (%04X:%04X)\n", seqno, ab_read, ab_write);
     }
     buf_fill = ab_write - ab_read;
     pthread_mutex_unlock(&ab_mutex);
@@ -521,7 +530,7 @@ static void rtp_request_resend(seq_t fir
     if (seq_order(last, first))
         return;
 
-    fprintf(stderr, "requesting resend on %d packets (port %d)\n", last-first+1, controlport);
+    xprintf("requesting resend on %d packets (port %d)\n", last-first+1, controlport);
 
     char req[8];    // *not* a standard RTCP NACK
     req[0] = 0x80;
@@ -605,8 +614,8 @@ static int init_rtp(void) {
         port += 3;
     }
 
-    printf("port: %d\n", port); // let our handler know where we end up listening
-    printf("cport: %d\n", port+1);
+    xprintf("port: %d\n", port); // let our handler know where we end up listening
+    xprintf("cport: %d\n", port+1);
 
     rtp_sockets[0] = sock;
     rtp_sockets[1] = csock;
@@ -709,7 +718,7 @@ void bf_est_update(short fill) {
     bf_est_drift = biquad_filt(&bf_drift_lpf, CONTROL_B*(bf_est_err*CONTROL_A + err_deriv) + bf_est_drift);
 
     if (debug)
-        fprintf(stderr, "bf %d err %f drift %f desiring %f ed %f estd %f\r", fill, bf_est_err, bf_est_drift, desired_fill, err_deriv, err_deriv + CONTROL_A*bf_est_err);
+        xprintf("bf %d err %f drift %f desiring %f ed %f estd %f\r", fill, bf_est_err, bf_est_drift, desired_fill, err_deriv, err_deriv + CONTROL_A*bf_est_err);
     bf_playback_rate = 1.0 + CONTROL_A*bf_est_err + bf_est_drift;
 
     bf_last_err = bf_est_err;
@@ -725,7 +734,7 @@ short *buffer_get_frame(void) {
     buf_fill = ab_write - ab_read;
     if (buf_fill < 1 || !ab_synced || ab_buffering) {    // init or underrun. stop and wait
         if (ab_synced)
-          fprintf(stderr, "\nunderrun\n");
+          xprintf("\nunderrun\n");
 
         ab_buffering = 1;
         pthread_cond_wait(&ab_buffer_ready, &ab_mutex);
@@ -737,7 +746,7 @@ short *buffer_get_frame(void) {
         return 0;
     }
     if (buf_fill >= BUFFER_FRAMES) {   // overrunning! uh-oh. restart at a sane distance
-        fprintf(stderr, "\noverrun.\n");
+        xprintf("\noverrun.\n");
         ab_read = ab_write - START_FILL;
     }
     read = ab_read;
@@ -749,7 +758,7 @@ short *buffer_get_frame(void) {
 
     volatile abuf_t *curframe = audio_buffer + BUFIDX(read);
     if (!curframe->ready) {
-        fprintf(stderr, "\nmissing frame.\n");
+        xprintf("\nmissing frame.\n");
         memset(curframe->data, 0, FRAME_BYTES);
     }
     curframe->ready = 0;
@@ -776,13 +785,13 @@ int stuff_buffer(double playback_rate, s
     if (stuff) {
         if (stuff==1) {
             if (debug)
-                fprintf(stderr, "+++++++++\n");
+                xprintf("+++++++++\n");
             // interpolate one sample
             *outptr++ = dithered_vol(((long)inptr[-2] + (long)inptr[0]) >> 1);
             *outptr++ = dithered_vol(((long)inptr[-1] + (long)inptr[1]) >> 1);
         } else if (stuff==-1) {
             if (debug)
-                fprintf(stderr, "---------\n");
+                xprintf("---------\n");
             inptr++;
             inptr++;
         }
@@ -849,6 +858,11 @@ void *audio_thread_func(void *arg) {
             inbuf = buffer_get_frame();
         } while (!inbuf && audio_running);
 
+        if(!audio_running)
+        {
+          return 0; //don't access inbuf if audio stopped
+        }
+
 #ifdef FANCY_RESAMPLING
         if (fancy_resampling) {
 	        int i;
@@ -881,7 +895,7 @@ void *audio_thread_func(void *arg) {
             }
 #ifdef HAS_AO
         } else {
-            ao_play(dev, (char *)outbuf, play_samples*4);
+            g_ao.ao_play(dev, (char *)outbuf, play_samples*4);
 #endif
         }
     }
@@ -906,7 +920,7 @@ void init_pipe(char* pipe) {
 ao_device *dev;
 
 void* init_ao() {
-    ao_initialize();
+    g_ao.ao_initialize();
 
     int driver;
 #ifndef XBMC
@@ -921,7 +935,7 @@ void* init_ao() {
 #endif
     {
         // otherwise choose the default
-        driver = ao_default_driver_id();
+        driver = g_ao.ao_default_driver_id();
     }
 
     ao_sample_format fmt;
@@ -944,9 +958,9 @@ void* init_ao() {
     }
 #endif
 
-    ao_append_option(&ao_opts, "name", "Streaming...");
+    g_ao.ao_append_option(&ao_opts, "name", "Streaming...");
 
-    dev = ao_open_live(driver, &fmt, ao_opts);
+    dev = g_ao.ao_open_live(driver, &fmt, ao_opts);
     if (dev == NULL) {
         die("Could not open ao device");
     }
@@ -985,12 +999,13 @@ void clean_output(void)
   audio_running = 0;
   pthread_join(audio_thread, NULL);
 #ifdef HAS_AO
-  ao_close(dev);
+  g_ao.ao_close(dev);
 #endif
 }
 
 void hairtunes_cleanup(void)
 {
+  pthread_cond_signal(&ab_buffer_ready);
   clean_output();
   clean_rtp();
   clean_buffer();
