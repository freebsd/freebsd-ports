--- ./source/jaudiolib/_multivc.h.orig	Tue Jul 18 16:14:46 2006
+++ ./source/jaudiolib/_multivc.h	Wed Aug  2 00:35:30 2006
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
