--- pyassetmlSDL.py.orig	Wed Apr 20 11:41:47 2005
+++ pyassetmlSDL.py	Wed Apr 20 11:42:32 2005
@@ -76,8 +76,10 @@
             pygame.mixer.music.load(self.s)
             pygame.mixer.music.play(loop)
         def stop(self):
             pygame.mixer.music.stop()
+	def queue(self):
+	    pygame.mixer.music.queue(self.s)
     
     class NoneSound:
             def play(self,loop=0):
                 pass
