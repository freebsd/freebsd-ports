--- splash_set_lib.py.orig	Thu Jan 22 11:46:44 2004
+++ splash_set_lib.py	Thu Jan 22 11:44:48 2004
@@ -105,7 +105,7 @@
 		self.__splash_home_dir = "~/.splash/"
 		self.splash_screen_list = []
 		self.allow_set_splash_now = False
-		self.config = gconf_lib()
+		self.__config = gconf_lib()
 
 
 	def set_random_splash(self):
@@ -135,14 +135,14 @@
 
 	def load_config(self):
 
-		self.__search_in_system_dir = self.config.get_cb_sysdir_state()
-		self.__splash_search_dir = self.config.get_splash_dir()
+		self.__search_in_system_dir = self.__config.get_cb_sysdir_state()
+		self.__splash_search_dir = self.__config.get_splash_dir()
 
 		if self.__splash_search_dir[-1:] != "/":
 			self.__splash_search_dir += "/"
 
 		if not self.__original_splash:
-			self.__original_splash = self.config.get_current_splash_screen()
+			self.__original_splash = self.__config.get_current_splash_screen()
 			self.active_splash = self.__original_splash
 
 
@@ -168,7 +168,7 @@
 
 	def set_splash(self):
 		print "new splash:",self.active_splash
-		self.config.set_splash_image(self.active_splash)
+		self.__config.set_splash_image(self.active_splash)
 
 
 	def __load_splash_file_list(self, path, splashlist):
