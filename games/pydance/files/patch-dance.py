--- dance.py.orig	Sat Jan 31 23:12:01 2004
+++ dance.py	Sun Feb  8 16:35:46 2004
@@ -22,6 +22,7 @@
 import records
 
 import os
+import time
 
 # A simple movie-playing sprite. It can only do MPEG1 though.
 class BGMovie(pygame.sprite.Sprite):
@@ -331,6 +332,10 @@
           break
       if songFailed:
         song.kill()
+
+    time.sleep(0.0001)
+    # needed for FreeBSD, otherwise music hangs (it does in non-sleeping loops)
+    # and yes, I do know this is an ugly hack
 
     for plr in players: plr.get_next_events(song)
 
