--- SpiralSound/RiffWav.C.orig	2000-11-26 18:52:41.000000000 +0300
+++ SpiralSound/RiffWav.C	2014-02-13 05:40:18.946204286 +0400
@@ -143,6 +143,7 @@
 			m_TotalLength/=2;
 			
 			// leave the filepointer on the first sample
+			return 1;
 		}
 		else
 		{
