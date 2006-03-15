--- pysycache.py	Wed Feb 15 17:23:28 2006
+++ pysycache.py	Mon Feb 27 00:15:58 2006
@@ -37,6 +37,8 @@
 from pygame.locals import *
 import glob
 
+sys.path.append("%%DATADIR%%")
+
 import datas
 from datasclass import BtnMenu
 import const
@@ -51,7 +53,7 @@
 
 
 def ReadCreditOfDirectory(dirname):
-	myfont = os.path.join(const.GRepPysycache, 'fonts', 'FreeSansBold.ttf' )
+	myfont = os.path.join(const.GRepPysycache, '%%DATADIR%%/fonts', 'FreeSansBold.ttf' )
 	font = pygame.font.Font(myfont, 20)	
 	textcolor = 46, 113, 169
 
@@ -129,9 +131,9 @@
 						#on est actuellement en image normale et on passe en image floue
 						const.GBtnMenu = btn.id
 
-						datas.load_sound('sounds', 'btnmenu.wav')
+						datas.load_sound('%%DATADIR%%/sounds', 'btnmenu.wav')
 
-						filename = os.path.join(const.GRepPysycache, 'images', btn.imagename + '1.png')
+						filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', btn.imagename + '1.png')
 						imgtmp = pygame.image.load(filename)
 						btn.image.blit(imgtmp, (btn.rect.left, btn.rect.top), (0, 0, btn.largeur, btn.hauteur))
 						btn.image = imgtmp
@@ -154,13 +156,13 @@
 					for btn in LstBtn.sprites():
 						if btn.id == const.GBtnMenu:
 							#mise a jour de l'image
-							filename = os.path.join(const.GRepPysycache, 'images', btn.imagename + '.png')
+							filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', btn.imagename + '.png')
 							imgtmp = pygame.image.load(filename)
 							btn.image.blit(imgtmp, (btn.rect.left, btn.rect.top), (0, 0, btn.largeur, btn.hauteur))
 							btn.image = imgtmp
 
 							#mise a jour de la zone d'aide (effacement)
-							imgnuage, background_rect = datas.load_image('images', 'fond-menu.bmp')
+							imgnuage, background_rect = datas.load_image('%%DATADIR%%/images', 'fond-menu.bmp')
 							Gbackground_image.blit(imgnuage, (300, 300), (300, 300, 400, 220))
 
 							break
@@ -176,7 +178,7 @@
 				if ( event.pos[0] >= obj.rect.left ) & ( event.pos[0] <= obj.rect.left + obj.largeur ) & ( event.pos[1] >= obj.rect.top  ) & ( event.pos[1] <= obj.rect.top + obj.hauteur ) :
 					#----------- show the correct window -----------------
 					#mise a jour de la zone d'aide
-					imgnuage, background_rect = datas.load_image('images', 'fond-menu.bmp')
+					imgnuage, background_rect = datas.load_image('%%DATADIR%%/images', 'fond-menu.bmp')
 					Gbackground_image.blit(imgnuage, (300, 300), (300, 300, 370, 200))
 
 					if pygame.mixer.music.get_busy :
@@ -261,14 +263,14 @@
 	#recuperation de la valeur de la langue
 	locale.setlocale(locale.LC_ALL,"")
 	const.GMyLocale, myencoding = locale.getlocale()
-	myrep = os.path.join(const.GRepPysycache, 'help', const.GMyLocale )
+	myrep = os.path.join(const.GRepPysycache, '%%DATADIR%%/help', const.GMyLocale )
 	
 	if os.path.isdir(myrep):
 		#le repertoire de la locale existe : rien a faire
 		pass
 	else :
 		#on essaie sur les deux premiers caracteres
-		myrep = os.path.join(const.GRepPysycache, 'help', const.GMyLocale[0:2])
+		myrep = os.path.join(const.GRepPysycache, '%%DATADIR%%/help', const.GMyLocale[0:2])
 		if os.path.isdir(myrep):
 			#le repertoire de la (nouvelle) locale existe : rien a faire
 			const.GMyLocale = const.GMyLocale[0:2]
@@ -283,7 +285,7 @@
 	pygame.display.set_caption('PySyCache')
 
 	#-------------------------- image vide de fond -----------------------------
-	background_image, background_rect = datas.load_image('images', 'fond1.bmp')
+	background_image, background_rect = datas.load_image('%%DATADIR%%/images', 'fond1.bmp')
 	screen.blit(background_image, (0,0))
 	pygame.display.flip()
 
@@ -291,7 +293,7 @@
 	pygame.time.delay(500)
 
 	#------------------ transition vers le titre du jeu ------------------------
-	background_image2, background_rect = datas.load_image('images', 'fond2.bmp')
+	background_image2, background_rect = datas.load_image('%%DATADIR%%/images', 'fond2.bmp')
 	for i in range(300):
 		screen.blit(background_image2, (0, i), (0, i, 800, 1))
 		screen.blit(background_image2, (0, 600 - i), (0, 600 - i, 800, 1))
@@ -304,7 +306,7 @@
 	pygame.time.delay(2000)
 	
 	#----------------------- transition vers le menu ---------------------------
-	Gbackground_image, background_rect = datas.load_image('images', 'fond-menu.bmp')
+	Gbackground_image, background_rect = datas.load_image('%%DATADIR%%/images', 'fond-menu.bmp')
 	for i in range(300):
 		screen.blit(Gbackground_image, (0, i), (0, i, 800, 1))
 		screen.blit(Gbackground_image, (0, 600 - i), (0, 600 - i, 800, 1))
@@ -336,7 +338,7 @@
 #	cursor = pygame.cursors.load_xbm(filename, maskname)
 #	cursor = cursor[0], (cursor[0][0] / 2, cursor[0][1] / 2), cursor[2], cursor[3]
 #	pygame.mouse.set_cursor(cursor[0], (0, 0), cursor[2], cursor[3])
-	filename = dirname = os.path.join(const.GRepPysycache, 'images', 'souris.png')
+	filename = dirname = os.path.join(const.GRepPysycache, '%%DATADIR%%/images', 'souris.png')
 	GMaSouris = pygame.image.load(filename)
 	GMaSouris_position = GMaSouris.get_rect()
 	GMaSouris_position.left = 400  # const.GPosDepX 
@@ -357,7 +359,7 @@
 		pygame.display.flip()
 
 	#-------------------------------- fin du jeu -------------------------------
-	Gbackground_image, background_rect = datas.load_image('images', 'fond4.bmp')
+	Gbackground_image, background_rect = datas.load_image('%%DATADIR%%/images', 'fond4.bmp')
 	for i in range(300):
 		screen.blit(Gbackground_image, (0, i), (0, i, 800, 1))
 		screen.blit(Gbackground_image, (0, 600 - i), (0, 600 - i, 800, 1))
@@ -371,12 +373,12 @@
 
 	#------------------ affichage des credits ------------------------
 	if const.GWithCredits :
-		myfont = os.path.join(const.GRepPysycache, 'fonts', 'FreeSansBold.ttf' )
+		myfont = os.path.join(const.GRepPysycache, '%%DATADIR%%/fonts', 'FreeSansBold.ttf' )
 		font = pygame.font.Font(myfont, 30)
 		textcolor = 46, 113, 169
 
 		#credits auteur
-		fichier = os.path.join(const.GRepPysycache, 'credits.txt')
+		fichier = os.path.join(const.GRepPysycache, '%%DATADIR%%/credits.txt')
 		if os.path.isfile(fichier):
 			#afficher le contenu 
 			f = open(fichier, 'r')
@@ -393,9 +395,9 @@
 		pygame.time.wait(3000) 
 
 		#credit images for themes
-		ReadCreditOfDirectory('themes-buttons')
-		ReadCreditOfDirectory('themes-click')
-		ReadCreditOfDirectory('themes-move')
+		ReadCreditOfDirectory('%%DATADIR%%/themes-buttons')
+		ReadCreditOfDirectory('%%DATADIR%%/themes-click')
+		ReadCreditOfDirectory('%%DATADIR%%/themes-move')
 	
 
 
