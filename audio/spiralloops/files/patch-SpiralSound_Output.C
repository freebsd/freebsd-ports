--- SpiralSound/Output.C.orig	Wed Nov 22 13:07:18 2006
+++ SpiralSound/Output.C	Wed Nov 22 13:07:30 2006
@@ -29,7 +29,7 @@
 	m_Buffer.Zero();
 }
 
-void Output::Send(Sample &data, float LeftVolume=1, float RightVolume=1) 
+void Output::Send(Sample &data, float LeftVolume, float RightVolume) 
 {
 	long temp;
 	int on=0;
