--- pysybuttons.py	Wed Feb 15 17:23:28 2006
+++ pysybuttons.py	Sun Feb 26 23:48:29 2006
@@ -58,7 +58,7 @@
 	"""This class is for the elements that move"""
 	def __init__(self, left, top, filename, id, categ):
 		pygame.sprite.Sprite.__init__(self) 				#call Sprite intializer
-		dirname = os.path.join(const.GRepPysycache, 'themes-buttons', GLstThemesButtons[const.GIdxThemes])
+		dirname = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-buttons', GLstThemesButtons[const.GIdxThemes])
 		self.image, self.rect = datas.load_png(dirname, filename)
 		self.id = id
 		self.largeur = 96
@@ -188,7 +188,7 @@
 			#chargement du dessin servant de cache
 			filename = os.path.join(themename, lig)
 			imgfilename = lig
-			ImgFond, background_rect = datas.load_image('themes-buttons', filename )
+			ImgFond, background_rect = datas.load_image('%%DATADIR%%/themes-buttons', filename )
 
 			#on copie ce cache sur l'image de fond
 			screen = pygame.display.get_surface()  
@@ -268,7 +268,7 @@
 def LoadListConfigFile(themename):
 	""" Find all available pictures of a theme directory """
 
-	filtre = os.path.join(const.GRepPysycache, 'themes-buttons', themename, '*.dfg')
+	filtre = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-buttons', themename, '*.dfg')
 
 	#vider
 #	GLstImage[:] = []
@@ -301,15 +301,15 @@
 	""" Change logo of a theme """
 	if const.GIdxThemes == 999999:
 		#tous les themes
-		filename = os.path.join(const.GRepPysycache, 'images', 'logo.png')
+		filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'logo.png')
 	else:
 		#un theme particulier
-		filename = os.path.join(const.GRepPysycache, 'themes-buttons', GLstThemesButtons[const.GIdxThemes], 'logo.png')
+		filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-buttons', GLstThemesButtons[const.GIdxThemes], 'logo.png')
 	
 	if os.path.isfile(filename) == True:
 		imgtmp = pygame.image.load(filename)
 	else:
-		filename = os.path.join(const.GRepPysycache, 'images', 'logo.png')
+		filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'logo.png')
 	imgtmp = pygame.image.load(filename)
 
 	#mise a jour de l'image du theme
@@ -393,7 +393,7 @@
 								if objtrouve.rect.left <= GLimFinG:
 									objtrouve.visible = 0
 						
-									filename = os.path.join(const.GRepPysycache, 'images', 'button-vide.png')
+									filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'button-vide.png')
 									imgtmp = pygame.image.load(filename)
 									screen = pygame.display.get_surface() 
 									objtrouve.image.blit(imgtmp, (0, 0), (0, 0, objtrouve.largeur, objtrouve.hauteur))
@@ -409,11 +409,11 @@
 	
 				elif str[1] == 1:
 					#-------- on change le mvt : haut <--> bas -----------------
-					datas.load_sound('sounds', 'center.ogg')
+					datas.load_sound('%%DATADIR%%/sounds', 'center.ogg')
 					objtrouve.sens = -1 * objtrouve.sens
 				elif str[2] == 1:
 					#-------------------- a droite -----------------------------
-					datas.load_sound('sounds', 'right.wav')
+					datas.load_sound('%%DATADIR%%/sounds', 'right.wav')
 					ok = 1
 
 					if GLimDroite <= objtrouve.rect.left + 50 + objtrouve.largeur :
@@ -427,7 +427,7 @@
 								if objtrouve.rect.left + objtrouve.largeur >= GLimFinD:
 									objtrouve.visible = 0
 
-									filename = os.path.join(const.GRepPysycache, 'images', 'button-vide.png')
+									filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'button-vide.png')
 									imgtmp = pygame.image.load(filename)
 
 									screen = pygame.display.get_surface() 
@@ -464,13 +464,13 @@
 						#change la vitesse du jeu (normal/moyenne/rapide)
 						if const.GSpeed == 3:
 							const.GSpeed = 2
-							filename = os.path.join(const.GRepPysycache, 'images', 'btn-vitesse2.png')
+							filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'btn-vitesse2.png')
 						elif const.GSpeed == 2:
 							const.GSpeed = 1
-							filename = os.path.join(const.GRepPysycache, 'images', 'btn-vitesse1.png')
+							filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'btn-vitesse1.png')
 						elif const.GSpeed == 1:
 							const.GSpeed = 3
-							filename = os.path.join(const.GRepPysycache, 'images', 'btn-vitesse3.png')
+							filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'btn-vitesse3.png')
 						imgtmp = pygame.image.load(filename)
 
 						#mise a jour image 
@@ -568,7 +568,7 @@
 #	cursor = cursor[0], (cursor[0][0] / 2, cursor[0][1] / 2), cursor[2], cursor[3]
 #	pygame.mouse.set_cursor(cursor[0], (0, 0), cursor[2], cursor[3])
 
-	filename = dirname = os.path.join(const.GRepPysycache, 'images', 'souris.png')
+	filename = dirname = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'souris.png')
 	GMaSouris = pygame.image.load(filename)
 	GMaSouris_position = GMaSouris.get_rect()
 	GMaSouris_position.left = const.GPosDepX   
@@ -576,7 +576,7 @@
 	pygame.mouse.set_pos((GMaSouris_position.left, GMaSouris_position.top))
 
 	#------------------ transition vers le jeu ------------------------
-	Gbackground_image, background_rect = datas.load_image('images', 'fond-buttons.bmp')
+	Gbackground_image, background_rect = datas.load_image('%%DATADIR%%/images', 'fond-buttons.bmp')
 	for i in range(300):
 		screen.blit(Gbackground_image, (0, i), (0, i, 800, 1))
 		screen.blit(Gbackground_image, (0, 600 - i), (0, 600 - i, 800, 1))
@@ -604,11 +604,11 @@
 	GLstFicConfig = []
 
 	#----------------- rechercher les themes disponibles -----------------------
-	repertoire = os.path.join(const.GRepPysycache, 'themes-buttons')
+	repertoire = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-buttons')
 	GLstThemesButtons = []
 	for nom in os.listdir(repertoire):
 		#ne prendre que les repertoires
-		isrep = os.path.join(const.GRepPysycache, 'themes-buttons', nom)
+		isrep = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-buttons', nom)
 		if os.path.isdir(isrep):
 			GLstThemesButtons.append(nom)
 	if len(GLstThemesButtons) == 1:
@@ -658,7 +658,7 @@
 			datas.PlayWinnerSound()
 
 			#on affiche l'image de gagne
-			imggagne, imgfin_rect = datas.load_png('images', 'gagne.png')
+			imggagne, imgfin_rect = datas.load_png('%%DATADIR%%/images', 'gagne.png')
 			screen.blit(imggagne, (100, 40))
 			pygame.display.flip()
 
