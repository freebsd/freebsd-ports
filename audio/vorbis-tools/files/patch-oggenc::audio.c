
$FreeBSD$

--- oggenc/audio.c.orig	Sat Dec  8 03:23:01 2001
+++ oggenc/audio.c	Tue Mar 26 03:32:57 2002
@@ -570,6 +570,7 @@
 	wav->bigendian =     0;
 	wav->channels =      format.channels;
 	wav->samplesize =    opt->samplesize;
+	wav->totalsamples =  0;
 
 	opt->read_samples = wav_read;
 	opt->readdata = (void *)wav;
