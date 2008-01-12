--- apricots/sampleio.cpp.orig	2003-08-06 03:21:22.000000000 +0400
+++ apricots/sampleio.cpp	2008-01-08 02:12:27.000000000 +0300
@@ -81,16 +81,10 @@
     ALsizei freq;
     ALboolean fileok;
     // Evil OpenAL portability fix done here
-#ifdef _WIN32
     ALenum format;
     ALboolean trash;
     alutLoadWAVFile(filenames[i],&format,&data,&filelen,&freq,&trash);
     fileok = (alGetError() == AL_NO_ERROR);
-#else
-    ALsizei format;
-    ALsizei trash;
-    fileok = alutLoadWAV(filenames[i],&data,&format,&filelen,&trash,&freq);
-#endif
     if (!fileok){
       cerr << "sampleio: could not open " << filenames[i] << endl;
       exit(1);
