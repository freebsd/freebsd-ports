--- StarterBar/Icon.py.orig	Wed Sep 24 14:26:55 2003
+++ StarterBar/Icon.py	Wed Sep 24 14:28:22 2003
@@ -11,7 +11,7 @@
     __GNOME_PIXMAP_DIR = \
       os.path.join(
         commands.getoutput("dirname `which gnome-desktop-item-edit`"),
-        "..", "share", "pixmaps")
+        "..", "share", "gnome", "pixmaps")
 
     # the unknown icon
     __UNKNOWN_ICON = "gnome-unknown.png"
@@ -61,7 +61,10 @@
                 return os.path.join(self.__GNOME_PIXMAP_DIR, f)
         #end for
 
-        return os.path.join(self.__GNOME_PIXMAP_DIR, self.__UNKNOWN_ICON)
+        return os.path.join(
+                 commands.getoutput("dirname `which gnome-desktop-item-edit`"),
+                 "..", "share", "icons", "gnome", "48x48", "apps",
+                 self.__UNKNOWN_ICON)
 
 
 
