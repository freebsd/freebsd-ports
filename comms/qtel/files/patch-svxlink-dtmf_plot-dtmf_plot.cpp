--- ../svxlink-11.05.orig/svxlink/dtmf_plot/dtmf_plot.cpp	2008-08-26 12:35:08.000000000 -0700
+++ svxlink/dtmf_plot/dtmf_plot.cpp	2012-05-28 10:27:56.000000000 -0700
@@ -230,10 +230,10 @@
   overtone_plot = new BarPlot(plot_win->overtone_plot, end_ko-start_ko+1);
   overtone_plot->setHighlight(dtmf_ko);
   
-  AudioIO audio_io("/dev/dsp", 0);
+  AudioIO audio_io("oss:/dev/dsp", 0);
   if (!audio_io.open(AudioIO::MODE_RD))
   {
-    printf("*** ERROR: Could not open audio device /dev/dsp\n");
+    printf("*** ERROR: Could not open audio device oss:/dev/dsp\n");
     exit(1);
   }
   
