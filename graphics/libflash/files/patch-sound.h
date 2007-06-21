--- lib/sound.h	Fri May 25 15:04:22 2007
+++ lib2/sound.h	Fri May 25 15:05:20 2007
@@ -103,9 +103,9 @@
 	long		 playSounds();		// Actually play sounds of all instances
 	long		 fillSoundBuffer(SoundList *, char *buffer, long bufferSize); // Fill sound buffer
 private:
-	int SoundMixer::Mp3Scale(mad_fixed_t sample);
-	void SoundMixer::Mp3Decompress(SoundList *sl);
-	void SoundMixer::uninitMp3Sounds(SoundList *sl);
+	int Mp3Scale(mad_fixed_t sample);
+	void Mp3Decompress(SoundList *sl);
+	void uninitMp3Sounds(SoundList *sl);
 };
 
 #endif /* _SOUND_H_ */
