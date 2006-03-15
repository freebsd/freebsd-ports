--- pysyclick.py	Wed Feb 15 17:23:28 2006
+++ pysyclick.py	Sun Feb 26 23:52:12 2006
@@ -66,7 +66,7 @@
 		if os.path.isfile(filetmp) == True:
 			self.image, self.rect = datas.load_png(dirname, filename)
 		else :
-			self.image, self.rect = datas.load_png('images', 'vide-off.png')
+			self.image, self.rect = datas.load_png('%%DATADIR%%/images', 'vide-off.png')
 		self.imagename = filename
 		self.rect.left = 712
 		self.rect.top = 50 + 51 * id 
@@ -99,7 +99,7 @@
 
 	#chargement du dessin servant de cache
 	filename = os.path.join(directory, GImgBackground) 
-	ImgFond, background_rect = datas.load_image('themes-click', filename )
+	ImgFond, background_rect = datas.load_image('%%DATADIR%%/themes-click', filename )
 
 	#on copie ce cache sur l'image de fond
 	screen = pygame.display.get_surface()  
@@ -127,15 +127,15 @@
 	""" Change logo of a theme """
 	if const.GIdxThemes == 999999:
 		#tous les themes
-		filename = os.path.join(const.GRepPysycache, 'images', 'logo.png')
+		filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'logo.png')
 	else:
 		#un theme particulier
-		filename = os.path.join(const.GRepPysycache, 'themes-click', GLstThemesClick[const.GIdxThemes], 'logo.png')
+		filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-click', GLstThemesClick[const.GIdxThemes], 'logo.png')
 
 	if os.path.isfile(filename) == True:
 		imgtmp = pygame.image.load(filename)
 	else:
-		filename = os.path.join(const.GRepPysycache, 'images', 'logo.png')
+		filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'logo.png')
 	imgtmp = pygame.image.load(filename)
 
 	#mise a jour de l'image du theme
@@ -181,7 +181,7 @@
 			pho = Photo()
 			lig = lig.split('-')
 			(shortname, extension) = os.path.splitext(lig[0]) 
-			pho.chemin = os.path.join(const.GRepPysycache, 'themes-click', themename, lig[0])
+			pho.chemin = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-click', themename, lig[0])
 			pho.miniature = shortname			#nom (sans extension de la miniature)
 			pho.id = cpt - 1
 			pho.left = int(lig[1]) + const.MARGELEFT
@@ -207,7 +207,7 @@
 	for pho in const.GTabPhotos:
 		for img in GLstImgPhotos.sprites() :
 			if img.id == pho.id :
-				filename = os.path.join(const.GRepPysycache, 'themes-click', GLstThemesClick[const.GIdxThemes], pho.miniature + '-off.png') 
+				filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-click', GLstThemesClick[const.GIdxThemes], pho.miniature + '-off.png') 
 				imgtmp = pygame.image.load(filename)
 				screen.blit(Gbackground_image, (img.rect.left, img.rect.top), (0, 0, 96, 50))
 				img.image.blit(imgtmp, (0, 0), (0, 0, 96, 50))
@@ -226,7 +226,7 @@
 	""" Find all definition files of a theme directoy """
 
 	#-------------------------- definition files -------------------------------
-	filtre = os.path.join(const.GRepPysycache, 'themes-click', themename, '*.dfg')
+	filtre = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-click', themename, '*.dfg')
 
 	#vider
 	cptliste = 0
@@ -307,9 +307,9 @@
 				if const.GTypeSouris == 0:
 					#on est actuellement en appareil photo normal et on passe en mode couleur
 					if const.GWithSound == 1:
-						datas.load_sound('sounds', 'photo-beep0.ogg')
+						datas.load_sound('%%DATADIR%%/sounds', 'photo-beep0.ogg')
 
-					filename = os.path.join(const.GRepPysycache, 'images', 'souris0.png')	   
+					filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'souris0.png')	   
 					souristmp = pygame.image.load(filename)
 					colsvg = GMaSouris.get_at((0,0))
 					GMaSouris.fill(colsvg)
@@ -327,7 +327,7 @@
 					pass
 				else:
 					#on est en appareil photo en couleur : on passe a normal
-					filename = os.path.join(const.GRepPysycache, 'images', 'souris1.png')	   
+					filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'souris1.png')	   
 					souristmp = pygame.image.load(filename)
 					colsvg = GMaSouris.get_at((0,0))
 					GMaSouris.fill(colsvg)
@@ -420,14 +420,14 @@
 					#mise a jour du dessin representant la photo prise
 					for img in GLstImgPhotos.sprites() :
 						if img.id == car.id :
-							filename = os.path.join(const.GRepPysycache, 'themes-click', GLstThemesClick[const.GIdxThemes], car.miniature + '-on.png') 
+							filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-click', GLstThemesClick[const.GIdxThemes], car.miniature + '-on.png') 
 							imgtmp = pygame.image.load(filename)
 							screen.blit(Gbackground_image, (img.rect.left, img.rect.top), (0, 0, 96, 50))
 							img.image.blit(imgtmp, (img.rect.left, img.rect.top), (0, 0, 96, 50))
 							img.image = imgtmp
 							break
 
-					datas.load_sound('sounds', 'photo-click.ogg');
+					datas.load_sound('%%DATADIR%%/sounds', 'photo-click.ogg');
 
 					#on affiche la photo
 					screen.blit(Gbackground_image, (0,0))
@@ -493,7 +493,7 @@
 #	cursor = cursor[0], (cursor[0][0] / 2, cursor[0][1] / 2), cursor[2], cursor[3]
 #	pygame.mouse.set_cursor(cursor[0], (0, 0), cursor[2], cursor[3])
 
-	filename = os.path.join(const.GRepPysycache, 'images', 'souris1.png')	   
+	filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'souris1.png')	   
 	GMaSouris = pygame.image.load(filename)
 	GMaSouris_position = GMaSouris.get_rect()
 	GMaSouris_position.left = const.GPosDepX   
@@ -501,7 +501,7 @@
 	const.Gtypsouris = 0
 
 	#------------------ transition vers le jeu ------------------------
-	Gbackground_image, background_rect = datas.load_image('images', 'fond-click.bmp')
+	Gbackground_image, background_rect = datas.load_image('%%DATADIR%%/images', 'fond-click.bmp')
 	for i in range(300):
 		screen.blit(Gbackground_image, (0, i), (0, i, 800, 1))
 		screen.blit(Gbackground_image, (0, 600 - i), (0, 600 - i, 800, 1))
@@ -527,11 +527,11 @@
 	GLstFicConfig = []
 
 	#----------------- rechercher les themes disponibles -----------------------
-	repertoire = os.path.join(const.GRepPysycache, 'themes-click')
+	repertoire = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-click')
 	GLstThemesClick = []
 	for nom in os.listdir(repertoire):
 		#ne prendre que les repertoires
-		isrep = os.path.join(const.GRepPysycache, 'themes-click', nom)
+		isrep = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-click', nom)
 		if os.path.isdir(isrep):
 			GLstThemesClick.append(nom)
 
@@ -576,7 +576,7 @@
 
 			#on affiche l'image de gagne
 			screen = pygame.display.get_surface()
-			imggagne, imgfin_rect = datas.load_png('images', 'gagne.png')
+			imggagne, imgfin_rect = datas.load_png('%%DATADIR%%/images', 'gagne.png')
 			screen.blit(imggagne, (100, 40))
 			LstBtn.draw(screen)
 			GLstImgPhotos.draw(screen)
@@ -602,7 +602,7 @@
 			RAZMiniatures()
 
 			#on remet la souris en normal
-			filename = os.path.join(const.GRepPysycache, 'images', 'souris1.png')
+			filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'souris1.png')
 			souristmp = pygame.image.load(filename)
 			colsvg = GMaSouris.get_at((0,0))
 			GMaSouris.fill(colsvg)
