--- xdg/IconTheme.py.orig	Mon Mar 29 13:37:54 2004
+++ xdg/IconTheme.py	Fri Jun 25 17:04:04 2004
@@ -212,7 +212,9 @@
 icondirs = []
 for basedir in xdg_data_dirs:
 	icondirs.append(os.path.join(basedir, "icons"))
-icondirs.append("/usr/share/pixmaps")
+icondirs.append("%%X11BASE%%/share/gnome/pixmaps")
+icondirs.append("%%X11BASE%%/share/icons")
+icondirs.append("%%LOCALBASE%%/share/icons")
 icondirs.append(os.path.expanduser("~/.icons"))
 
 # just cache variables, they give a 10x speed improvement
