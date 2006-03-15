--- pysymove.py	Wed Feb 15 17:23:28 2006
+++ pysymove.py	Mon Feb 27 00:02:12 2006
@@ -134,7 +134,7 @@
 
 	#chargement du dessin servant de cache
 	filename = os.path.join(directory, 'cache', imgcache)
-	GCacheImage, background_rect = datas.load_image('themes-move', filename)
+	GCacheImage, background_rect = datas.load_image('%%DATADIR%%/themes-move', filename)
 
 	#on copie ce cache sur l'image de fond
 	screen = pygame.display.get_surface()  
@@ -150,7 +150,7 @@
 
 	#chargement du dessin a trouver
 	filename = os.path.join(directory, imgdessous)
-	GImageATrouver, background_rect = datas.load_image('themes-move', filename)
+	GImageATrouver, background_rect = datas.load_image('%%DATADIR%%/themes-move', filename)
 
 	#redessin de la souris a sa position 
 	GMaSouris_position.left = const.GPosDepX
@@ -193,15 +193,15 @@
 	""" Change logo of a theme """
 	if const.GIdxThemes == 999999:
 		#tous les themes
-		filename = os.path.join(const.GRepPysycache, 'images', 'logo.png')
+		filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'logo.png')
 	else:
 		#un theme particulier
-		filename = os.path.join(const.GRepPysycache, 'themes-move', GLstThemesMove[const.GIdxThemes], 'logo.png')
+		filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-move', GLstThemesMove[const.GIdxThemes], 'logo.png')
 	
 	if os.path.isfile(filename) == True:
 		imgtmp = pygame.image.load(filename)
 	else:
-		filename = os.path.join(const.GRepPysycache, 'images', 'logo.png')
+		filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'logo.png')
 	imgtmp = pygame.image.load(filename)
 
 	#mise a jour de l'image du theme
@@ -225,10 +225,10 @@
 def ChangeTypeJeu():
 	""" Change mode of a theme """
 	if const.GModeJeu == MODENORMAL:
-		filename = os.path.join(const.GRepPysycache, 'images', 'mode0.png')
+		filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'mode0.png')
 	elif const.GModeJeu == MODEFANTOM:
-		filename = os.path.join(const.GRepPysycache, 'images', 'mode1.png')
-	else:	filename = os.path.join(const.GRepPysycache, 'images', 'mode2.png')
+		filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'mode1.png')
+	else:	filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'mode2.png')
 
 	if os.path.isfile(filename) == True:
 		imgtmp = pygame.image.load(filename)
@@ -253,7 +253,7 @@
 def LoadListImage(themename):
 	""" Find all available pictures of a theme directory """
 
-	filtre = os.path.join(const.GRepPysycache, 'themes-move', themename, '*.dfg')
+	filtre = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-move', themename, '*.dfg')
 
 	#vider
 	GLstImage[:] = []
@@ -286,12 +286,12 @@
 				if len(lig) == 0:
 					continue
 				#fichier de cache
-				nomcache = os.path.join(const.GRepPysycache, 'themes-move', themename, 'cache', lig[0])
+				nomcache = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-move', themename, 'cache', lig[0])
 				if os.path.isfile(nomcache):
 					lstcache.append(lig[0])
 					
 					#fichier de son
-					nomcache = os.path.join('themes-move', themename, 'cache', lig[1])
+					nomcache = os.path.join('%%DATADIR%%/themes-move', themename, 'cache', lig[1])
 					lstsndcache.append(nomcache)
 				else:
 					print "error in definition file : cache file ", nomcache, " doesn't exist"
@@ -356,7 +356,7 @@
 							pygame.display.flip()
 
 							#on joue la musique
-							datas.load_sound('sounds', 'fantom.wav')
+							datas.load_sound('%%DATADIR%%/sounds', 'fantom.wav')
 						
 						break
 				return 1
@@ -401,7 +401,7 @@
 							const.GNbCarreau = const.GNbCarreau - 1
 
 							#on joue la musique
-							datas.load_sound('sounds', 'pop.ogg')
+							datas.load_sound('%%DATADIR%%/sounds', 'pop.ogg')
 
 						break
 
@@ -483,11 +483,11 @@
 						if const.GTailleCarreau == CARREAUSMALL + 1:
 							const.GTailleCarreau = CARREAUBIG
 						if const.GTailleCarreau == CARREAUBIG:
-							filename = os.path.join(const.GRepPysycache, 'images', 'btn-size1.png')
+							filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'btn-size1.png')
 						elif const.GTailleCarreau == CARREAUNORMAL:
-							filename = os.path.join(const.GRepPysycache, 'images', 'btn-size2.png')
+							filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'btn-size2.png')
 						else:
-							filename = os.path.join(const.GRepPysycache, 'images', 'btn-size3.png')
+							filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'btn-size3.png')
 						imgtmp = pygame.image.load(filename)
 
 						#mise a jour image taille carreau
@@ -553,12 +553,12 @@
 #	cursor = cursor[0], (cursor[0][0] / 2, cursor[0][1] / 2), cursor[2], cursor[3]
 #	pygame.mouse.set_cursor(cursor[0], (0, 0), cursor[2], cursor[3])
 
-	filename = dirname = os.path.join(const.GRepPysycache, 'images', 'souris.png')	 
+	filename = dirname = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'souris.png')	 
 	GMaSouris = pygame.image.load(filename)
 	GCarre_position = GMaSouris.get_rect()
 
 	#------------------ transition vers le jeu ------------------------
-	Gbackground_image, background_rect = datas.load_image('images', 'fond-move.bmp')
+	Gbackground_image, background_rect = datas.load_image('%%DATADIR%%/images', 'fond-move.bmp')
 	for i in range(300):
 		screen.blit(Gbackground_image, (0, i), (0, i, 800, 1))
 		screen.blit(Gbackground_image, (0, 600 - i), (0, 600 - i, 800, 1))
@@ -592,10 +592,10 @@
 	GLstSndCache = []
 
 	#---------------- rechercher les themes disponibles ----------------------
-	repertoire = os.path.join(const.GRepPysycache, 'themes-move')
+	repertoire = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-move')
 	for nom in os.listdir(repertoire):
 		#ne prendre que les repertoires
-		isrep = os.path.join(const.GRepPysycache, 'themes-move', nom)
+		isrep = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-move', nom)
 		if os.path.isdir(isrep):
 			GLstThemesMove.append(nom)
 	if len(GLstThemesMove) == 1 :
@@ -653,11 +653,11 @@
 			if const.GWithSound == 1:
 				#on joue la musique de l'image
 				(shortname, extension) = os.path.splitext(GLstImage[const.GIdxImage]) 
-				music = os.path.join(const.GRepPysycache, 'themes-move', GLstThemesMove[const.GIdxThemes], shortname + '.ogg')
+				music = os.path.join(const.GRepPysycache, '%%DATADIR%%/themes-move', GLstThemesMove[const.GIdxThemes], shortname + '.ogg')
 				if os.path.isfile(music) == True:
-					datas.load_sound(os.path.join('themes-move', GLstThemesMove[const.GIdxThemes]), shortname + '.ogg')
+					datas.load_sound(os.path.join('%%DATADIR%%/themes-move', GLstThemesMove[const.GIdxThemes]), shortname + '.ogg')
 				else:
-					datas.load_sound(os.path.join('themes-move', GLstThemesMove[const.GIdxThemes]), shortname + '.wav')
+					datas.load_sound(os.path.join('%%DATADIR%%/themes-move', GLstThemesMove[const.GIdxThemes]), shortname + '.wav')
 				pygame.time.wait(500)
 
 			#attende de 2 secondes (pour faire voir l'image)
@@ -666,7 +666,7 @@
 			#----------------- on affiche l'image de gagne ---------------------
 			datas.PlayWinnerSound()
 
-			imggagne, imgfin_rect = datas.load_png('images', 'gagne.png')
+			imggagne, imgfin_rect = datas.load_png('%%DATADIR%%/images', 'gagne.png')
 			screen.blit(imggagne, (100, 40))
 			pygame.display.flip()
 
