--- /tmp/pydance/share/games/pydance/dance.py	Sat Oct 25 18:50:56 2003
+++ dance.py	Sun Oct 26 18:44:40 2003
@@ -11,6 +11,9 @@
 
 import random, sys, os, copy
 
+import time
+# see comment about FreeBSD below. A better solution would be appreciated.
+
 class BGmovie(pygame.sprite.Sprite):
   def __init__ (self, filename):
     pygame.sprite.Sprite.__init__(self)
@@ -314,6 +317,10 @@
           break
       if songFailed:
         song.kill()
+
+    time.sleep(0.0001)
+    # needed for FreeBSD, otherwise music hangs (it does in non-sleeping loops)
+    # and yes, I do know this is an ugly hack
 
     for plr in players: plr.get_next_events(song)
 
