--- subband_layer_1.cc.orig	1994-06-23 12:14:36 UTC
+++ subband_layer_1.cc
@@ -67,7 +67,7 @@ SubbandLayer1::SubbandLayer1 (uint32 sub
 void SubbandLayer1::read_allocation (Ibitstream *stream, Header *, Crc16 *crc)
 {
   if ((allocation = stream->get_bits (4)) == 15)
-    cerr << "WARNING: stream contains an illegal allocation!\n";	// MPEG-stream is corrupted!
+    std::cerr << "WARNING: stream contains an illegal allocation!\n";	// MPEG-stream is corrupted!
   if (crc)
     crc->add_bits (allocation, 4);
   if (allocation)
@@ -86,14 +86,14 @@ void SubbandLayer1::read_scalefactor (Ib
 }
 
 
-bool SubbandLayer1::read_sampledata (Ibitstream *stream)
+boolean SubbandLayer1::read_sampledata (Ibitstream *stream)
 {
   if (allocation)
   {
     sample = real (stream->get_bits (samplelength));
 #ifdef DEBUG
     if (sample == (1 << samplelength) - 1)
-	cerr << "WARNING: stream contains an illegal subband sample!\n";  // MPEG-stream is corrupted!
+	std::cerr << "WARNING: stream contains an illegal subband sample!\n";  // MPEG-stream is corrupted!
 #endif
   }
   if (++samplenumber == 12)
@@ -105,7 +105,7 @@ bool SubbandLayer1::read_sampledata (Ibi
 }
 
 
-bool SubbandLayer1::put_next_sample (e_channels channels,
+boolean SubbandLayer1::put_next_sample (e_channels channels,
 				     SynthesisFilter *filter1, SynthesisFilter *)
 {
   if (allocation && channels != right)
@@ -113,7 +113,7 @@ bool SubbandLayer1::put_next_sample (e_c
     register real scaled_sample = (sample * factor + offset) * scalefactor;
 #ifdef DEBUG
     if (scaled_sample < -1.0 || scaled_sample > 1.0)
-      cerr << "WARNING: rescaled subband sample is not in [-1.0, 1.0]\n";
+      std::cerr << "WARNING: rescaled subband sample is not in [-1.0, 1.0]\n";
       // this should never occur
 #endif
     filter1->input_sample (scaled_sample, subbandnumber);
@@ -142,7 +142,7 @@ void SubbandLayer1IntensityStereo::read_
 }
 
 
-bool SubbandLayer1IntensityStereo::put_next_sample (e_channels channels,
+boolean SubbandLayer1IntensityStereo::put_next_sample (e_channels channels,
 	SynthesisFilter *filter1, SynthesisFilter *filter2)
 {
   if (allocation)
@@ -154,7 +154,7 @@ bool SubbandLayer1IntensityStereo::put_n
 		    sample2 = sample * channel2_scalefactor;
 #ifdef DEBUG
       if (sample1 < -1.0 || sample1 > 1.0 || sample2 < -1.0 || sample2 > 1.0)
-	cerr << "WARNING: rescaled subband sample is not in [-1.0, 1.0]\n";
+	std::cerr << "WARNING: rescaled subband sample is not in [-1.0, 1.0]\n";
 	// this should never occur
 #endif
       filter1->input_sample (sample1, subbandnumber);
@@ -165,7 +165,7 @@ bool SubbandLayer1IntensityStereo::put_n
       register real sample1 = sample * scalefactor;
 #ifdef DEBUG
       if (sample1 < -1.0 || sample1 > 1.0)
-	cerr << "WARNING: rescaled subband sample is not in [-1.0, 1.0]\n";
+	std::cerr << "WARNING: rescaled subband sample is not in [-1.0, 1.0]\n";
 	// this should never occur
 #endif
       filter1->input_sample (sample1, subbandnumber);
@@ -175,7 +175,7 @@ bool SubbandLayer1IntensityStereo::put_n
       register real sample2 = sample * channel2_scalefactor;
 #ifdef DEBUG
       if (sample2 < -1.0 || sample2 > 1.0)
-	cerr << "WARNING: rescaled subband sample is not in [-1.0, 1.0]\n";
+	std::cerr << "WARNING: rescaled subband sample is not in [-1.0, 1.0]\n";
 	// this should never occur
 #endif
       filter1->input_sample (sample2, subbandnumber);
@@ -206,7 +206,7 @@ void SubbandLayer1Stereo::read_allocatio
     crc->add_bits (channel2_allocation, 4);
   }
   if (allocation == 15 || channel2_allocation == 15)
-    cerr << "WARNING: stream contains an illegal allocation!\n";	// MPEG-stream is corrupted!
+    std::cerr << "WARNING: stream contains an illegal allocation!\n";	// MPEG-stream is corrupted!
   if (allocation)
   {
     samplelength = allocation + 1;
@@ -231,22 +231,22 @@ void SubbandLayer1Stereo::read_scalefact
 }
 
 
-bool SubbandLayer1Stereo::read_sampledata (Ibitstream *stream)
+boolean SubbandLayer1Stereo::read_sampledata (Ibitstream *stream)
 {
-  bool returnvalue = SubbandLayer1::read_sampledata (stream);
+  boolean returnvalue = SubbandLayer1::read_sampledata (stream);
   if (channel2_allocation)
   {
     channel2_sample = real (stream->get_bits (channel2_samplelength));
 #ifdef DEBUG
     if (channel2_sample == (1 << channel2_samplelength) - 1)
-	cerr << "WARNING: stream contains an illegal subband sample!\n";  // MPEG-stream is corrupted!
+	std::cerr << "WARNING: stream contains an illegal subband sample!\n";  // MPEG-stream is corrupted!
 #endif
   }
   return returnvalue;
 }
 
 
-bool SubbandLayer1Stereo::put_next_sample (e_channels channels,
+boolean SubbandLayer1Stereo::put_next_sample (e_channels channels,
 					   SynthesisFilter *filter1, SynthesisFilter *filter2)
 {
   SubbandLayer1::put_next_sample (channels, filter1, filter2);
@@ -256,7 +256,7 @@ bool SubbandLayer1Stereo::put_next_sampl
 			     channel2_scalefactor;
 #ifdef DEBUG
     if (sample2 < -1.0 || sample2 > 1.0)
-      cerr << "WARNING: rescaled subband sample is not in [-1.0, 1.0]\n";
+      std::cerr << "WARNING: rescaled subband sample is not in [-1.0, 1.0]\n";
       // this should never occur
 #endif
     if (channels == both)
