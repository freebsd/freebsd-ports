--- ui.py.orig	Sat Jul  2 21:14:32 2005
+++ ui.py	Sat Jul  2 21:16:27 2005
@@ -1,6 +1,6 @@
 from pygame.locals import *
 from constants import mainconfig
-import pad, pygame
+import pad, pygame, time
 
 (PASS, CANCEL, UP, DOWN, LEFT, RIGHT, START, SELECT, CONFIRM,
  PGUP, PGDN, FULLSCREEN, SORT, CLEAR) = range(14)
@@ -63,6 +63,7 @@
       self.add_event(key, pid, event)
 
   def poll(self):
+    time.sleep(0.01)
     pid, ev = self.handler.poll()
 
     nev = self.events.get(abs(ev), PASS)
