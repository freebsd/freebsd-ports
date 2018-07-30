src/soundengine/vorbisdecoder.cpp:352:20: error: cannot initialize return object of type 'unsigned char *' with an rvalue of type 'bool'
            return false;
                   ^~~~~

--- src/soundengine/vorbisdecoder.cpp.orig	2018-07-30 08:05:34 UTC
+++ src/soundengine/vorbisdecoder.cpp
@@ -349,7 +349,7 @@ unsigned char *VorbisDecoder::decodeAll(unsigned int *
         if (!vorbisDecode(m_readData, rlen, &leftover, false) ||
             !m_decSamplesLen) {
             DEBUG_INFO("vorbisDecode failed");
-            return false;
+            return NULL;
         }
         m_readPos += rlen - leftover;
 
