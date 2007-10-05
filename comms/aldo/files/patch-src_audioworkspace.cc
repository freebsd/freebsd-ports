--- src/audioworkspace.cc.orig	Wed Oct  3 12:19:50 2007
+++ src/audioworkspace.cc	Wed Oct  3 12:21:41 2007
@@ -56,15 +56,14 @@
 Wave AudioWorkSpace::gen_pause(size_type millisecond)
 {
     size_type sample_number = millisecond * m_sample_rate/1000;
-
-    size_type len = millisecond * m_bits/8 * m_channels * m_sample_rate/1000;
+    size_type len =  m_bits/8 * m_channels * sample_number;
 
     char* buffer = new char[len];
     
     for(unsigned int i = 0; i<sample_number; i++)
     {
-	buffer[4*i] = buffer[4*i+2] = 0 & 0xff;
-	buffer[4*i+1] = buffer[4*i+3] = (0 >> 8) & 0xff;
+        buffer[4*i] = buffer[4*i+2] = 0;
+        buffer[4*i+1] = buffer[4*i+3] = 0;
     }
 
     Wave w(len, buffer);
