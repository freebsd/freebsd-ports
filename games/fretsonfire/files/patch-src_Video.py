--- src/Video.py	Mon Aug 28 16:36:04 2006
+++ src/Video.py	Mon Oct  2 16:23:07 2006
@@ -48,10 +48,10 @@
       
     pygame.display.init()
     
-    pygame.display.gl_set_attribute(pygame.GL_RED_SIZE,   8)
-    pygame.display.gl_set_attribute(pygame.GL_GREEN_SIZE, 8)
-    pygame.display.gl_set_attribute(pygame.GL_BLUE_SIZE,  8)
-    pygame.display.gl_set_attribute(pygame.GL_ALPHA_SIZE, 8)
+    pygame.display.gl_set_attribute(pygame.GL_RED_SIZE,   5)
+    pygame.display.gl_set_attribute(pygame.GL_GREEN_SIZE, 6)
+    pygame.display.gl_set_attribute(pygame.GL_BLUE_SIZE,  5)
+    pygame.display.gl_set_attribute(pygame.GL_ALPHA_SIZE, 0)
       
     if multisamples:
       pygame.display.gl_set_attribute(pygame.GL_MULTISAMPLEBUFFERS, 1);
@@ -59,13 +59,14 @@
 
     try:
       self.screen = pygame.display.set_mode(resolution, flags)
-    except pygame.error:
+    except pygame.error,e:
       if multisamples:
         Log.warn("Video setup failed. Trying without antialiasing.")
         pygame.display.gl_set_attribute(pygame.GL_MULTISAMPLEBUFFERS, 0);
         pygame.display.gl_set_attribute(pygame.GL_MULTISAMPLESAMPLES, 0);
         multisamples = 0
         self.screen = pygame.display.set_mode(resolution, flags)
+      else: raise e
         
     pygame.display.set_caption(self.caption)
     pygame.mouse.set_visible(False)
