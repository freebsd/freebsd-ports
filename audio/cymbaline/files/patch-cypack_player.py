--- cypack/player.py.bak	2011-02-12 21:11:21.000000000 +0100
+++ cypack/player.py	2011-02-12 21:12:19.000000000 +0100
@@ -370,7 +370,7 @@
         import mad, ao
         self.mf = mad.MadFile(self.path)
         self.total = self.mf.total_time()/1000
-        dev = ao.AudioDevice('alsa', rate=self.mf.samplerate())
+        dev = ao.AudioDevice('oss', rate=self.mf.samplerate())
         global player
         while 1:
             # manually halted, set mode to stop - to make sure poll won't
