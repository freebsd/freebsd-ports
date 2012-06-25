--- ../svxlink-11.05.orig/echolib/EchoLinkQsoTest.cpp	2011-05-14 00:27:24.000000000 -0700
+++ echolib/EchoLinkQsoTest.cpp	2012-05-28 10:27:55.000000000 -0700
@@ -159,7 +159,7 @@
   
   //sigc_src = new SigCAudioSource;
   
-  audio_io = new AudioIO("alsa:default", 0);
+  audio_io = new AudioIO("oss:/dev/dsp", 0);
   full_duplex = audio_io->isFullDuplexCapable();
   if (full_duplex)
   {
