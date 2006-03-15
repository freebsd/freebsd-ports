--- /home/acardenas/pysycache/datas.py	Wed Feb 15 17:23:27 2006
+++ datas.py	Sun Feb 26 23:20:02 2006
@@ -34,7 +34,7 @@
 from pygame.locals import *
 import const
 
-
+sys.path.append("%%DATADIR%%")
 
 #*******************************************************************************
 #                                                                              #
@@ -135,11 +135,11 @@
 def PlayWinnerSound():
 	idxsnd = random.randint(0, 2)
 	if idxsnd == 0 :
-		load_sound('sounds', 'youpee.ogg')
+		load_sound('%%DATADIR%%/sounds', 'youpee.ogg')
 	elif idxsnd == 1 :
-		load_sound('sounds', 'yahoo.ogg')
+		load_sound('%%DATADIR%%/sounds', 'yahoo.ogg')
 	else :
-		load_sound('sounds', 'rire.ogg')
+		load_sound('%%DATADIR%%/sounds', 'rire.ogg')
 
 
 
@@ -150,7 +150,7 @@
 def ShowTransitionOfTheme(duree, fileimage):
 	screen = pygame.display.get_surface()
 	
-	background_image2, background_rect = load_image('images', fileimage)
+	background_image2, background_rect = load_image('%%DATADIR%%/images', fileimage)
 	for i in range(267):
 		screen.blit(background_image2, (0, i), (0, i, 710, 1))
 		screen.blit(background_image2, (0, 534 - i), (0, 534 - i, 710, 1))
