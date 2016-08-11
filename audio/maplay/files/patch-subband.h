--- subband.h.orig	1994-06-23 12:14:40 UTC
+++ subband.h
@@ -35,8 +35,8 @@ class Subband
 public:
   virtual void read_allocation (Ibitstream *, Header *, Crc16 *) = 0;
   virtual void read_scalefactor (Ibitstream *, Header *) = 0;
-  virtual bool read_sampledata (Ibitstream *) = 0;
-  virtual bool put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *) = 0;
+  virtual boolean read_sampledata (Ibitstream *) = 0;
+  virtual boolean put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *) = 0;
 };
 
 #endif
