--- StarterBar/Icon.py.orig	Fri Jun 25 00:28:42 2004
+++ StarterBar/Icon.py	Fri Jun 25 00:29:44 2004
@@ -11,7 +11,7 @@
     "..", "share", "icons"))
 IconTheme.icondirs.append(os.path.join(
     commands.getoutput("dirname `which gnome-desktop-item-edit`"),
-    "..", "share", "pixmaps"))
+    "..", "share", "gnome", "pixmaps"))
 
 
 class Icon:
