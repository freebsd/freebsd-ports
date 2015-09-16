--- apricots/sampleio.cpp.orig	2015-08-19 14:00:09 UTC
+++ apricots/sampleio.cpp
@@ -74,28 +74,21 @@ void sampleio :: init(int nsamples, char
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
@@ -107,8 +100,6 @@ void sampleio :: init(int nsamples, char
     alSourcefv(sources[j], AL_ORIENTATION, back );
   }
   
-  free(data);
-  
 }
 
 // Clearup routine
