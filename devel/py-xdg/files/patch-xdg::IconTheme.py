--- xdg/IconTheme.py.orig	Sun Jun  5 14:20:19 2005
+++ xdg/IconTheme.py	Sun Jun  5 14:21:07 2005
@@ -215,7 +215,11 @@
 icondirs = []
 for basedir in xdg_data_dirs:
 	icondirs.append(os.path.join(basedir, "icons"))
-icondirs.append("/usr/share/pixmaps")
+icondirs.append("%%X11BASE%%/share/pixmaps")
+icondirs.append("%%LOCALBASE%%/share/pixmaps")
+icondirs.append("%%X11BASE%%/share/gnome/pixmaps")
+icondirs.append("%%X11BASE%%/share/icons")
+icondirs.append("%%LOCALBASE%%/share/icons")
 icondirs.append(os.path.expanduser("~/.icons"))
 
 # just cache variables, they give a 10x speed improvement
