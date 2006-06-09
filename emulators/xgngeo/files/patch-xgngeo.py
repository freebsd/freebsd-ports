--- xgngeo.py	Thu Jul 14 13:48:58 2005
+++ /home/acardenas/xgngeo.py	Thu Mar  2 21:39:00 2006
@@ -28,14 +28,14 @@
 os.chdir(os.path.abspath(syspath[0]))
 
 #Add `data/py/' to PATH, then import internal modules.
-syspath.append("data/py/")
+syspath.append("%%DATADIR%%/py/")
 import command, configfile, history, rominfos, romrcfile
 
 VERSION = 15
 gngeoDir = os.path.expanduser("~/.gngeo")
 
 #Internationalization.
-gettext.install("xgngeo","data/lang")
+gettext.install("xgngeo","%%X11BASE%%/share/locale")
 
 class XGngeo:
 	def checkError(self):
@@ -591,7 +591,7 @@
 			frame.add(box)
 
 			logo = gtk.Image()
-			logo.set_from_file("data/img/chprod.png")
+			logo.set_from_file("%%DATADIR%%/img/chprod.png")
 			box.pack_start(logo,False)
 
 			box2 = gtk.VBox(spacing=4)
@@ -1087,7 +1087,7 @@
 
 					#Generate key's image
 					image = gtk.Image()
-					image.set_from_file("data/img/key_%s.png" % key_list[i])
+					image.set_from_file("%%DATADIR%%/img/key_%s.png" % key_list[i])
 
 					box2 = gtk.HBox() #A box...
 					box2.pack_start(p1keywidgets[i]) #with P1 key...
@@ -1131,21 +1131,21 @@
 				if temp_param["country"]=="japan": self.configwidgets['country_japan'].set_active(1)
 				table.attach(self.configwidgets['country_japan'],0,1,0,1)
 				image = gtk.Image()
-				image.set_from_file("data/img/japan.png")
+				image.set_from_file("%%DATADIR%%/img/japan.png")
 				table.attach(image,0,1,1,2)
 
 				self.configwidgets['country_usa'] = gtk.RadioButton(self.configwidgets['country_japan'],_("USA"))
 				if temp_param["country"]=="usa": self.configwidgets['country_usa'].set_active(1)
 				table.attach(self.configwidgets['country_usa'],1,2,0,1)
 				image = gtk.Image()
-				image.set_from_file("data/img/usa.png")
+				image.set_from_file("%%DATADIR%%/img/usa.png")
 				table.attach(image,1,2,1,2)
 
 				radio = gtk.RadioButton(self.configwidgets['country_japan'],_("Europe"))
 				if temp_param["country"]=="europe": radio.set_active(1)
 				table.attach(radio,2,3,0,1)
 				image = gtk.Image()
-				image.set_from_file("data/img/europe.png")
+				image.set_from_file("%%DATADIR%%/img/europe.png")
 				table.attach(image,2,3,1,2)
 				frame2.add(table)
 				box.pack_start(frame2)
@@ -1408,7 +1408,7 @@
 		self.context_id = self.statusbar.get_context_id("Info")
 
 		self.window = gtk.Window(gtk.WINDOW_TOPLEVEL)
-		gtk.window_set_default_icon_from_file("data/img/icon.png")
+		gtk.window_set_default_icon_from_file("%%DATADIR%%/img/icon.png")
 
 	def main(self):
 		#Window attributes.
@@ -1536,7 +1536,7 @@
 		container = gtk.EventBox()
 		container.modify_bg(gtk.STATE_NORMAL,gtk.gdk.color_parse("white"))
 		logo = gtk.Image()
-		logo.set_from_file("data/img/xgngeo.png")
+		logo.set_from_file("%%DATADIR%%/img/xgngeo.png")
 		logo.set_padding(25,2)
 		container.add(logo)
 		box.pack_start(container)
