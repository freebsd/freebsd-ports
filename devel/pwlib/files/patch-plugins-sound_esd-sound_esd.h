--- plugins/sound_esd/sound_esd.h.orig	Thu Apr  6 16:47:28 2006
+++ plugins/sound_esd/sound_esd.h	Thu Apr  6 16:48:06 2006
@@ -43,15 +43,15 @@
               unsigned _bitsPerSample);
     BOOL Setup();
     BOOL Close();
-    BOOL IsOpen() const;
+//    BOOL IsOpen() const;
     BOOL Write(const void * buf, PINDEX len);
     BOOL Read(void * buf, PINDEX len);
     BOOL SetFormat(unsigned numChannels,
                    unsigned sampleRate,
                    unsigned bitsPerSample);
-    unsigned GetChannels() const;
-    unsigned GetSampleRate() const;
-    unsigned GetSampleSize() const;
+//    unsigned GetChannels() const;
+//    unsigned GetSampleRate() const;
+//    unsigned GetSampleSize() const;
     BOOL SetBuffers(PINDEX size, PINDEX count);
     BOOL GetBuffers(PINDEX & size, PINDEX & count);
     BOOL PlaySound(const PSound & sound, BOOL wait);
