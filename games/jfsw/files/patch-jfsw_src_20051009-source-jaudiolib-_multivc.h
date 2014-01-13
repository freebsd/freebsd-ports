--- jfsw_src_20051009/source/jaudiolib/_multivc.h.orig	2005-10-09 15:28:24.000000000 +0200
+++ jfsw_src_20051009/source/jaudiolib/_multivc.h	2005-10-10 15:02:08.000000000 +0200
@@ -67,8 +67,11 @@
 #define SILENCE_8BIT      0x80808080
 //#define SILENCE_16BIT_PAS 0
 
-//#define MixBufferSize     256
+#ifdef WINDOWS
 #define MixBufferSize     (MV_GetBufferSize(MV_RequestedMixRate))
+#else
+#define MixBufferSize     256
+#endif
 
 #define NumberOfBuffers   16
 #define TotalBufferSize   ( MixBufferSize * NumberOfBuffers )
