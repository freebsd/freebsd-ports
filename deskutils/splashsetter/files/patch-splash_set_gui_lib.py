--- splash_set_gui_lib.py.orig	Thu Jan 22 11:46:50 2004
+++ splash_set_gui_lib.py	Thu Jan 22 11:42:38 2004
@@ -182,6 +182,7 @@
 
 		self.__def_thumb_size = 120
 
+
 	def run_gui(self):
 		self.set_icon(gtk.gdk.pixbuf_new_from_file(SPLASH_SET_ICON))
 		self.connect('destroy', gtk.mainquit)
@@ -260,8 +261,8 @@
 	def __toolbar_workaround(self, x1 = None, x2 = None):
 
 		if self.__toolbar.get_style() == 2:				# 2 is text below icons but is also set if "both-horiz" == 3 should be.
-			self.config = gconf.client_get_default()
-			tc_or = self.config.get_string("/desktop/gnome/interface/toolbar_style")
+			config = gconf_lib()
+			tc_or = config.get_string("/desktop/gnome/interface/toolbar_style")
 			if (tc_or == "both-horiz"):
 				self.__toolbar.set_style(gtk.TOOLBAR_BOTH_HORIZ)
 
