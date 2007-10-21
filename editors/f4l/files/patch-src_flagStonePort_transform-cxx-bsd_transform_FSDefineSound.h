Index: src/flagStonePort/transform-cxx-bsd/transform/FSDefineSound.h
@@ -137,7 +137,7 @@
             @param bytes the sound data.
             @param length the number of bytes in the sound data.
             */
-        FSDefineSound::FSDefineSound(int anIdentifier, int encoding, int rate, int channels, int sampleSize, int count, byte* bytes, size_t length);
+        FSDefineSound(int anIdentifier, int encoding, int rate, int channels, int sampleSize, int count, byte* bytes, size_t length);
 
         FSDefineSound(const FSDefineSound& rhs);
 
