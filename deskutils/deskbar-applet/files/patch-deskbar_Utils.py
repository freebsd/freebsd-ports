--- deskbar/Utils.py.orig	Tue Nov  1 20:32:51 2005
+++ deskbar/Utils.py	Tue Nov  1 20:33:08 2005
@@ -10,7 +10,7 @@
 	
 	sysdirs = os.getenv("XDG_DATA_DIRS")
 	if sysdirs == None:
-		sysdirs = "/usr/local/share:/usr/share"
+	    sysdirs = "%%X11BASE%%/share/gnome/:/usr/local/share/gnome/:%%X11BASE%%/share/:/usr/local/share/:/usr/share/"
 	
 	dirs = "%s:%s" % (dirs, sysdirs)
 	return [dir for dir in dirs.split(":") if dir.strip() != "" and exists(dir)]
