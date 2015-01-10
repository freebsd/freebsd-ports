--- src/waveinput.cpp.orig	2015-01-07 06:36:15.000000000 -0800
+++ src/waveinput.cpp	2015-01-07 06:36:25.000000000 -0800
@@ -19,7 +19,7 @@
 
 extern Parameter settings;
 
-WaveInput::WaveInput(int ptt = -1): Input(ptt)
+WaveInput::WaveInput(int ptt): Input(ptt)
 {
  EightBits=false;
 }
