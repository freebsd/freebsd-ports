--- src/gnauralnet.h.orig	2011-02-21 22:28:39 UTC
+++ src/gnauralnet.h
@@ -230,7 +230,7 @@ void GN_Time_ProcessOutgoingData (GN_Friend * curFrien
 void GN_ShowInfo ();
 
 //Global variables:
-unsigned short GN_ScheduleFingerprint;
+extern unsigned short GN_ScheduleFingerprint;
 typedef struct GN_Globals_type
 {
  int State;                     //DO NOT MOVE THIS; it gets initialized in gnauralnet_main
