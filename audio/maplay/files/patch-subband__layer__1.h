--- subband_layer_1.h.orig	1994-06-23 12:14:40 UTC
+++ subband_layer_1.h
@@ -42,8 +42,8 @@ public:
        SubbandLayer1 (uint32 subbandnumber);
   void read_allocation (Ibitstream *, Header *, Crc16 *);
   void read_scalefactor (Ibitstream *, Header *);
-  bool read_sampledata (Ibitstream *);
-  bool put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
+  boolean read_sampledata (Ibitstream *);
+  boolean put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
 };
 
 
@@ -60,11 +60,11 @@ public:
     SubbandLayer1::read_allocation (stream, header, crc);
   }
   void read_scalefactor (Ibitstream *, Header *);
-  bool read_sampledata (Ibitstream *stream)
+  boolean read_sampledata (Ibitstream *stream)
   {
     return SubbandLayer1::read_sampledata (stream);
   }
-  bool put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
+  boolean put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
 };
 
 
@@ -82,8 +82,8 @@ public:
        SubbandLayer1Stereo (uint32 subbandnumber);
   void read_allocation (Ibitstream *, Header *, Crc16 *);
   void read_scalefactor (Ibitstream *, Header *);
-  bool read_sampledata (Ibitstream *);
-  bool put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
+  boolean read_sampledata (Ibitstream *);
+  boolean put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
 };
 
 #endif
