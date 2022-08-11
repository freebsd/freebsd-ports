--- imidi.h.orig	2022-05-05 04:24:13 UTC
+++ imidi.h
@@ -25,7 +25,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <clthreads.h>
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <alsa/asoundlib.h>
 #endif
 #ifdef __APPLE__
@@ -61,7 +61,7 @@ class Imidi : public A_thread (private)
     Lfq_u8         *_qmidi; 
     uint16_t       *_midimap;
     const char     *_appname;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     snd_seq_t      *_handle;
 #endif
 #ifdef __APPLE__
