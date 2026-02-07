--- src/Video.py	Wed Nov  1 01:03:39 2006
+++ src/Video.py	Wed Nov  1 01:04:35 2006
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
