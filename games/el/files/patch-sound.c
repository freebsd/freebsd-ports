--- sound.c	Fri Aug 18 12:54:36 2006
+++ sound.c	Fri Aug 18 11:33:35 2006
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
+//		alutUnloadWAV(format,data,size,freq);
 	}
 	return sound_buffer[i];
 }
