--- xdg/IconTheme.py.orig	2007-09-10 00:33:42.000000000 -0500
+++ xdg/IconTheme.py	2007-09-10 00:34:37.000000000 -0500
@@ -215,7 +215,8 @@
 icondirs = []
 for basedir in xdg_data_dirs:
 	icondirs.append(os.path.join(basedir, "icons"))
-icondirs.append("/usr/share/pixmaps")
+icondirs.append("%%LOCALBASE%%/share/pixmaps")
+icondirs.append("%%LOCALBASE%%/share/icons")
 icondirs.append(os.path.expanduser("~/.icons"))
 
 # just cache variables, they give a 10x speed improvement
