--- datasclass.py	Wed Feb 15 17:23:27 2006
+++ datasclass.py	Sun Feb 26 23:20:53 2006
@@ -43,7 +43,7 @@
 	"""This class is for the menus buttons"""
 	def __init__(self, left, top, filename, id, btnlarg, btnhaut):
 		pygame.sprite.Sprite.__init__(self) 				#call Sprite intializer
-		self.image, self.rect = datas.load_png('images', filename)
+		self.image, self.rect = datas.load_png('%%DATADIR%%/images', filename)
 		(shortname, extension) = os.path.splitext(filename) 
 		self.imagename = shortname
 		self.rect.left = left
@@ -53,27 +53,27 @@
 		self.hauteur = btnhaut
 
 	def showhelp(self, imgdest):
-		myfont = os.path.join(const.GRepPysycache, 'fonts', 'FreeSansBold.ttf' )
+		myfont = os.path.join(const.GRepPysycache, '%%DATADIR%%/fonts', 'FreeSansBold.ttf' )
 		font = pygame.font.Font(myfont, 20)
 		textcolor = 46, 113, 169
 		screen = pygame.display.get_surface()
 
-		myrep = os.path.join(const.GRepPysycache, 'help', const.GMyLocale )
+		myrep = os.path.join(const.GRepPysycache, '%%DATADIR%%/help', const.GMyLocale )
 
 		#joue le fichier d'aide
 		if const.GWithSound == 1:
 			if const.GWithHelp == 1 :
-				dirname = os.path.join('help', const.GMyLocale)
+				dirname = os.path.join('%%DATADIR%%/help', const.GMyLocale)
 				filename = str(self.id) + '.ogg'
 				datas.load_sound(dirname, filename)
 		
 		#affiche l'aide
 		if os.path.isdir(myrep):
-			filename = os.path.join(const.GRepPysycache, 'help', const.GMyLocale , str(self.id) + '.txt')
+			filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/help', const.GMyLocale , str(self.id) + '.txt')
 		else :
-			filename = os.path.join(const.GRepPysycache, 'help', 'en_EN' , str(self.id) + '.txt')
+			filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/help', 'en_EN' , str(self.id) + '.txt')
 			
-		filename = os.path.join(const.GRepPysycache, 'help', const.GMyLocale , str(self.id) + '.txt')
+		filename = os.path.join(const.GRepPysycache, '%%DATADIR%%/help', const.GMyLocale , str(self.id) + '.txt')
 		if os.path.isfile(filename):
 			f = open(filename, 'r')
 			lignes  = f.readlines()
