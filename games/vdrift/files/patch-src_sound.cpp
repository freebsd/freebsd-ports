--- src/sound.cpp.orig	Tue Sep 12 19:39:38 2006
+++ src/sound.cpp	Tue Sep 12 19:41:19 2006
@@ -282,9 +282,9 @@
 	alutLoadWAVFile((ALbyte*)(filename).c_str(), &format, &data, &size, &freq);
 #else
 #ifdef OLD_OPENAL
-	alutLoadWAVFile((ALbyte*)(filename).c_str(), &format, &data, &size, &freq, &loop);
+	alutLoadWAVFile(filename.c_str(), &format, &data, &size, &freq, &loop);
 #else
-	data = alutLoadMemoryFromFile((ALbyte*)(filename).c_str(), &format, &size, &freq);
+	data = alutLoadMemoryFromFile(filename.c_str(), &format, &size, &freq);
 #endif
 #endif
 	//bool err = LoadWave(filename, &format, &data, &size, &freq, &loop);
