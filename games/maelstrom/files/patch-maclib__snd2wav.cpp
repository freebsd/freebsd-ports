--- ./maclib/snd2wav.cpp.orig	2001-03-28 05:54:50.000000000 +0200
+++ ./maclib/snd2wav.cpp	2013-12-28 11:39:16.000000000 +0100
@@ -82,7 +82,7 @@
 			continue;
 		}
 		wave.Load(snd, rate);
-		sprintf(wavname, "snd_%d.wav", ids[i]);
+		snprintf(wavname, sizeof(wavname), "snd_%d.wav", ids[i]);
 		wave.Save(wavname);
 	}
 	delete macx;
