--- src/network/nPriorizing.h.orig	2007-10-02 18:17:42.000000000 +0200
+++ src/network/nPriorizing.h	2007-10-02 18:18:00.000000000 +0200
@@ -36,6 +36,7 @@
 class nSendBuffer;
 class nBandwidthControl;
 class nBandwidthTask;
+class nBandwidthTaskPriorizer;
 
 tDECLARE_REFOBJ( nBandwidthTask );
 tDECLARE_REFOBJ( nBandwidthArbitrator );
