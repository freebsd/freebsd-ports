--- rnetgui.py.orig	Mon Feb 10 01:00:29 2003
+++ rnetgui.py	Mon Feb 10 01:03:25 2003
@@ -765,7 +765,7 @@
 
 	for fnam, tg, tool, help, id, sep in ziplist:
 
-	    path=os.path.join(homepath,"icons",fnam)+".png"
+	    path=os.path.join("%%DATADIR%%","icons",fnam)+".png"
 
 	    bitmap=wxBitmapFromImage(wxImage(path, wxBITMAP_TYPE_PNG))
 	    self.tb.AddTool(id,bitmap,wxNullBitmap, tg, -1, tool, help)
@@ -958,7 +958,7 @@
 
     def About(self, event) : 
 
-	path=os.path.join(homepath,"icons","ziarc.png")
+	path=os.path.join("%%DATADIR%%","icons","ziarc.png")
 	bitmap=wxBitmapFromImage(wxImage(path, wxBITMAP_TYPE_PNG))
  
         about=MyAbout(self, bitmap)
