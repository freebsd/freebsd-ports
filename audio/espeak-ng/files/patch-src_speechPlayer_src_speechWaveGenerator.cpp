--- src/speechPlayer/src/speechWaveGenerator.cpp.orig	2022-06-21 14:53:53 UTC
+++ src/speechPlayer/src/speechWaveGenerator.cpp
@@ -194,7 +194,7 @@ class SpeechWaveGeneratorImpl: public SpeechWaveGenera
 	SpeechWaveGeneratorImpl(int sr): sampleRate(sr), voiceGenerator(sr), fricGenerator(), cascade(sr), parallel(sr), frameManager(NULL) {
 	}
 
-	unsigned int generate(const unsigned int sampleCount, sample* sampleBuf) {
+	unsigned int generate(const unsigned int sampleCount, ::sample* sampleBuf) {
 		if(!frameManager) return 0; 
 		double val=0;
 		for(unsigned int i=0;i<sampleCount;++i) {
