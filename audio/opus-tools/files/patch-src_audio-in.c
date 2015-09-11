--- src/audio-in.c.orig	2014-02-26 00:55:47 UTC
+++ src/audio-in.c
@@ -42,6 +42,7 @@
 # define _FILE_OFFSET_BITS 64
 #endif
 
+#include <limits.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
@@ -287,13 +288,14 @@ static int aiff_permute_matrix[6][6] =
 int aiff_open(FILE *in, oe_enc_opt *opt, unsigned char *buf, int buflen)
 {
     int aifc; /* AIFC or AIFF? */
-    unsigned int len;
-    unsigned char *buffer;
+    unsigned int len, readlen;
+    unsigned char buffer[22];
     unsigned char buf2[8];
     int bigendian = 1;
     aiff_fmt format;
     aifffile *aiff;
     int i;
+    long channels;
     (void)buflen;/*unused*/
 
     if(buf[11]=='C')
@@ -313,19 +315,25 @@ int aiff_open(FILE *in, oe_enc_opt *opt,
         return 0; /* Weird common chunk */
     }
 
-    buffer = alloca(len);
-
-    if(fread(buffer,1,len,in) < len)
+    readlen = len < sizeof(buffer) ? len : sizeof(buffer);
+    if(fread(buffer,1,readlen,in) < readlen ||
+        (len > readlen && !seek_forward(in, len-readlen)))
     {
         fprintf(stderr, _("Warning: Unexpected EOF reading AIFF header\n"));
         return 0;
     }
 
-    format.channels = READ_U16_BE(buffer);
+    format.channels = channels = READ_U16_BE(buffer);
     format.totalframes = READ_U32_BE(buffer+2);
     format.samplesize = READ_U16_BE(buffer+6);
     format.rate = (int)read_IEEE80(buffer+8);
 
+    if(channels <= 0L || SHRT_MAX < channels)
+    {
+        fprintf(stderr, _("Warning: Unsupported count of channels in AIFF header\n"));
+        return 0;
+    }
+
     if(aifc)
     {
         if(len < 22)
@@ -442,6 +450,7 @@ int wav_open(FILE *in, oe_enc_opt *opt, 
     wav_fmt format;
     wavfile *wav;
     int i;
+    long channels;
     (void)buflen;/*unused*/
     (void)oldbuf;/*unused*/
 
@@ -481,12 +490,18 @@ int wav_open(FILE *in, oe_enc_opt *opt, 
     }
 
     format.format =      READ_U16_LE(buf);
-    format.channels =    READ_U16_LE(buf+2);
+    format.channels = channels = READ_U16_LE(buf+2);
     format.samplerate =  READ_U32_LE(buf+4);
     format.bytespersec = READ_U32_LE(buf+8);
     format.align =       READ_U16_LE(buf+12);
     format.samplesize =  READ_U16_LE(buf+14);
 
+    if(channels <= 0L || SHRT_MAX < channels)
+    {
+        fprintf(stderr, _("Warning: Unsupported count of channels in WAV header\n"));
+        return 0;
+    }
+
     if(format.format == -2) /* WAVE_FORMAT_EXTENSIBLE */
     {
       if(len<40)
