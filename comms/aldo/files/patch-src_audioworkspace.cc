--- src/audioworkspace.cc.orig	2010-06-06 14:43:58.000000000 +0200
+++ src/audioworkspace.cc	2010-06-06 14:44:27.000000000 +0200
@@ -104,6 +104,7 @@ oastream AudioWorkSpace::create_output_s
 {
     ao_sample_format format;
     
+    memset(&format, 0, sizeof(format));
     format.bits = m_bits;
     format.channels = m_channels;
     format.rate = m_sample_rate;
