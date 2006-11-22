--- SpiralSound/RiffWav.C.orig	Wed Nov 22 13:07:57 2006
+++ SpiralSound/RiffWav.C	Wed Nov 22 13:08:07 2006
@@ -55,7 +55,7 @@
 #endif
 }
 
-int WavFile::Open(string FileName, Mode mode, Channels channels=MONO)
+int WavFile::Open(string FileName, Mode mode, Channels channels)
 {
 	if (m_Stream!=NULL) 
 	{
