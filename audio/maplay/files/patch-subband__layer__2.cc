--- subband_layer_2.cc.orig	1994-06-23 12:14:36 UTC
+++ subband_layer_2.cc
@@ -591,7 +591,7 @@ void SubbandLayer2::read_scalefactor (Ib
 }
 
 
-bool SubbandLayer2::read_sampledata (Ibitstream *stream)
+boolean SubbandLayer2::read_sampledata (Ibitstream *stream)
 {
   if (allocation)
     if (groupingtable)
@@ -633,7 +633,7 @@ bool SubbandLayer2::read_sampledata (Ibi
 }
 
 
-bool SubbandLayer2::put_next_sample (e_channels channels,
+boolean SubbandLayer2::put_next_sample (e_channels channels,
 				     SynthesisFilter *filter1, SynthesisFilter *)
 {
 #ifdef DEBUG
@@ -726,7 +726,7 @@ void SubbandLayer2IntensityStereo::read_
 }
 
 
-bool SubbandLayer2IntensityStereo::put_next_sample (e_channels channels,
+boolean SubbandLayer2IntensityStereo::put_next_sample (e_channels channels,
 	SynthesisFilter *filter1, SynthesisFilter *filter2)
 {
 #ifdef DEBUG
@@ -880,9 +880,9 @@ void SubbandLayer2Stereo::read_scalefact
 }
 
 
-bool SubbandLayer2Stereo::read_sampledata (Ibitstream *stream)
+boolean SubbandLayer2Stereo::read_sampledata (Ibitstream *stream)
 {
-  bool returnvalue = SubbandLayer2::read_sampledata (stream);
+  boolean returnvalue = SubbandLayer2::read_sampledata (stream);
 
   if (channel2_allocation)
     if (channel2_groupingtable)
@@ -919,10 +919,10 @@ bool SubbandLayer2Stereo::read_sampledat
 }
 
 
-bool SubbandLayer2Stereo::put_next_sample (e_channels channels,
+boolean SubbandLayer2Stereo::put_next_sample (e_channels channels,
 					   SynthesisFilter *filter1, SynthesisFilter *filter2)
 {
-  bool returnvalue = SubbandLayer2::put_next_sample (channels, filter1, filter2);
+  boolean returnvalue = SubbandLayer2::put_next_sample (channels, filter1, filter2);
   if (channel2_allocation && channels != left)
   {
     register real sample = channel2_samples[samplenumber - 1];
