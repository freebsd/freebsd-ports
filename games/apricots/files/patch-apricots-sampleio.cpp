Patch to build with newer openal. Not sure whether it doesn't leak memory
--- apricots/sampleio.cpp.orig	2003-08-06 03:21:22.000000000 +0400
+++ apricots/sampleio.cpp	2010-04-07 18:32:05.000000000 +0400
@@ -74,28 +74,21 @@
   alListenerfv(AL_ORIENTATION, front );
 
   // Load in samples
-  ALvoid* data = malloc(5 * (512 * 3) * 1024);
+  ALvoid* data;
   alGenBuffers(numsamples, samples);
 
   for (int i = 0; i < numsamples; i++){
-    ALsizei freq;
+    ALfloat freq;
     ALboolean fileok;
     // Evil OpenAL portability fix done here
-#ifdef _WIN32
     ALenum format;
-    ALboolean trash;
-    alutLoadWAVFile(filenames[i],&format,&data,&filelen,&freq,&trash);
-    fileok = (alGetError() == AL_NO_ERROR);
-#else
-    ALsizei format;
-    ALsizei trash;
-    fileok = alutLoadWAV(filenames[i],&data,&format,&filelen,&trash,&freq);
-#endif
-    if (!fileok){
+    data = alutLoadMemoryFromFile(filenames[i], &format, &filelen, &freq);
+    if (!data){
       cerr << "sampleio: could not open " << filenames[i] << endl;
       exit(1);
     }         
     alBufferData(samples[i], format, data, filelen, freq);
+    free(data);
   }
 
   // Generate Sources
@@ -107,8 +100,6 @@
     alSourcefv(sources[j], AL_ORIENTATION, back );
   }
   
-  free(data);
-  
 }
 
 // Clearup routine
