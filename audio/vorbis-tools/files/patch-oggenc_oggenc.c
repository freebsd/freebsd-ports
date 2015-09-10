--- oggenc/oggenc.c.orig	2010-03-26 07:07:07 UTC
+++ oggenc/oggenc.c
@@ -97,6 +97,8 @@ int main(int argc, char **argv)
               .3,-1,
               0,0,0.f,
               0, 0, 0, 0, 0};
+    input_format raw_format = {NULL, 0, raw_open, wav_close, "raw",
+      N_("RAW file reader")};
 
     int i;
 
@@ -239,9 +241,6 @@ int main(int argc, char **argv)
 
         if(opt.rawmode)
         {
-            input_format raw_format = {NULL, 0, raw_open, wav_close, "raw", 
-                N_("RAW file reader")};
-
             enc_opts.rate=opt.raw_samplerate;
             enc_opts.channels=opt.raw_channels;
             enc_opts.samplesize=opt.raw_samplesize;
