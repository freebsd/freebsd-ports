--- subband_layer_2.h.orig	1994-06-23 12:14:40 UTC
+++ subband_layer_2.h
@@ -55,8 +55,8 @@ public:
   void		read_allocation (Ibitstream *, Header *, Crc16 *);
   virtual void	read_scalefactor_selection (Ibitstream *, Crc16 *);
   void		read_scalefactor (Ibitstream *, Header *);
-  bool		read_sampledata (Ibitstream *);
-  bool		put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter * = NULL);
+  boolean		read_sampledata (Ibitstream *);
+  boolean		put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter * = NULL);
 };
 
 
@@ -75,11 +75,11 @@ public:
   }
   void read_scalefactor_selection (Ibitstream *, Crc16 *);
   void read_scalefactor (Ibitstream *, Header *);
-  bool read_sampledata (Ibitstream *stream)
+  boolean read_sampledata (Ibitstream *stream)
   {
     return SubbandLayer2::read_sampledata (stream);
   }
-  bool put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
+  boolean put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
 };
 
 
@@ -90,7 +90,7 @@ protected:
   uint32 channel2_allocation;
   uint32 channel2_scfsi;
   real	 channel2_scalefactor1, channel2_scalefactor2, channel2_scalefactor3;
-  bool	 channel2_grouping;
+  boolean	 channel2_grouping;
   uint32 channel2_codelength;
   const real *channel2_groupingtable;
   real	 channel2_factor;
@@ -102,8 +102,8 @@ public:
   void read_allocation (Ibitstream *, Header *, Crc16 *);
   void read_scalefactor_selection (Ibitstream *, Crc16 *);
   void read_scalefactor (Ibitstream *, Header *);
-  bool read_sampledata (Ibitstream *);
-  bool put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
+  boolean read_sampledata (Ibitstream *);
+  boolean put_next_sample (e_channels, SynthesisFilter *, SynthesisFilter *);
 };
 
 #endif
