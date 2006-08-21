--- sound.c	Mon Aug 21 11:20:53 2006
+++ sound.c	Mon Aug 21 11:25:49 2006
@@ -313,10 +313,11 @@
 ALuint get_loaded_buffer(int i)
 {
 	int error;
-	ALsizei size,freq;
+	ALsizei size;
 	ALenum  format;
-	ALvoid  *data;
 	ALboolean loop;
+	ALfloat freq;
+	ALvoid* data = 0;
 	FILE *fin;
 	
 	if(!alIsBuffer(sound_buffer[i]))
@@ -349,10 +350,10 @@
 		// OS X alutLoadWAVFile doesn't have a loop option... Oh well :-)
 		alutLoadWAVFile (sound_files[i], &format, &data, &size, &freq);
 #else
-		alutLoadWAVFile (sound_files[i], &format, &data, &size, &freq, &loop);
+		data = alutLoadMemoryFromFile (sound_files[i], &format, &size, &freq);
 #endif
-		alBufferData(sound_buffer[i],format,data,size,freq);
-		alutUnloadWAV(format,data,size,freq);
+		alBufferData(sound_buffer[i],format,data,size,(int)freq);
+		free(data);
 	}
 	return sound_buffer[i];
 }
@@ -377,14 +378,14 @@
 #ifndef OSX
 		alutLoadWAVFile(szPath,&pSample->format,&data,&pSample->size,&pSample->freq,&loop);
 #else
-		alutLoadWAVFile(szPath,&pSample->format,&data,&pSample->size,&pSample->freq);
+		data = alutLoadMemoryFromFile(szPath, &pSample->format, &pSample->size, &pSample->freq);
 #endif
 		if(!data)
 		{//couldn't load the file
 		#ifdef ELC
 			LOG_ERROR("%s: %s",snd_buff_error, "NO SOUND DATA");
 		#else
-			printf("ensure_sample_loaded : alutLoadWAVFile(%s) = %s\n",
+			printf("ensure_sample_loaded : alutLoadMemoryFromFile(%s) = %s\n",
 				szPath, "NO SOUND DATA");
 		#endif
 			return 1;
@@ -420,7 +421,7 @@
 		pSample->length = (pSample->size*1000) / ((pSample->bits >> 3)*pSample->channels*pSample->freq);
 
 		//get rid of the temporary data
-		alutUnloadWAV(pSample->format,data,pSample->size,pSample->freq);
+		free(data);
     }
 
 	pSample->loaded_status = 1;
