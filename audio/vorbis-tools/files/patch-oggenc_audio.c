--- oggenc/audio.c.orig	2010-03-24 08:27:14 UTC
+++ oggenc/audio.c
@@ -13,6 +13,7 @@
 #include <config.h>
 #endif
 
+#include <limits.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
@@ -245,12 +246,13 @@ static int aiff_permute_matrix[6][6] = 
 int aiff_open(FILE *in, oe_enc_opt *opt, unsigned char *buf, int buflen)
 {
     int aifc; /* AIFC or AIFF? */
-    unsigned int len;
-    unsigned char *buffer;
+    unsigned int len, readlen;
+    unsigned char buffer[22];
     unsigned char buf2[8];
     aiff_fmt format;
     aifffile *aiff = malloc(sizeof(aifffile));
     int i;
+    long channels;
 
     if(buf[11]=='C')
         aifc=1;
@@ -269,19 +271,25 @@ int aiff_open(FILE *in, oe_enc_opt *opt,
         return 0; /* Weird common chunk */
     }
 
-    buffer = alloca(len);
-
-    if(fread(buffer,1,len,in) < len)
+    readlen = len < sizeof(buffer) ? len : sizeof(buffer);
+    if(fread(buffer,1,readlen,in) < readlen ||
+       (len > readlen && !seek_forward(in, len-readlen)))
     {
         fprintf(stderr, _("Warning: Unexpected EOF in reading AIFF header\n"));
         return 0;
     }
 
-    format.channels = READ_U16_BE(buffer);
+    format.channels = channels = READ_U16_BE(buffer);
     format.totalframes = READ_U32_BE(buffer+2);
     format.samplesize = READ_U16_BE(buffer+6);
     format.rate = (int)read_IEEE80(buffer+8);
 
+    if(channels <= 0L || SHRT_MAX < channels)
+    {
+         fprintf(stderr, _("Warning: Unsupported count of channels in AIFF header\n"));
+         return 0;
+    }
+
     aiff->bigendian = 1;
 
     if(aifc)
@@ -412,6 +420,7 @@ int wav_open(FILE *in, oe_enc_opt *opt, 
     wav_fmt format;
     wavfile *wav = malloc(sizeof(wavfile));
     int i;
+    long channels;
 
     /* Ok. At this point, we know we have a WAV file. Now we have to detect
      * whether we support the subtype, and we have to find the actual data
@@ -449,12 +458,18 @@ int wav_open(FILE *in, oe_enc_opt *opt, 
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
