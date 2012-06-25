--- ../svxlink-11.05.orig/async/demo/AsyncAudioIO_demo.cpp	2010-02-21 12:21:23.000000000 -0800
+++ async/demo/AsyncAudioIO_demo.cpp	2012-05-28 10:27:56.000000000 -0700
@@ -106,7 +106,7 @@
     MyClass(void)
     {
       	// Create a new audio IO object
-      audio_io = new AudioIO("alsa:default", 0);
+      audio_io = new AudioIO("oss:/dev/dsp", 0);
       
       	// Open it for both reading and writing
       audio_io->open(AudioIO::MODE_RDWR);
@@ -117,7 +117,7 @@
       	// Register the audio device as the audio source for this object
       registerSource(audio_io);
       
-      SineGenerator *sine_gen = new SineGenerator("alsa:default", 1);
+      SineGenerator *sine_gen = new SineGenerator("oss:/dev/dsp", 1);
       sine_gen->setFq(1000);
       sine_gen->setLevel(2);
       sine_gen->enable(true);
