--- StarterBar/Icon.py.orig	Sun Nov  9 16:13:33 2003
+++ StarterBar/Icon.py	Sun Nov  9 16:14:28 2003
@@ -11,7 +11,7 @@
     __GNOME_PIXMAP_DIR = \
       os.path.join(
         commands.getoutput("dirname `which gnome-desktop-item-edit`"),
-        "..", "share", "pixmaps")
+        "..", "share", "gnome", "pixmaps")
 
     # the unknown icon
     __UNKNOWN_ICON = "gnome-unknown.png"
@@ -34,9 +34,10 @@
     def __load_icon(self, desktopfile):
         
         reader = DesktopReader(desktopfile)
-        iconname = reader.get_icon()
-        self.__pixmap = self.__icon_theme.lookup_icon(iconname)
-        if (not self.__pixmap):
+        try:
+            iconname = reader.get_icon()
+            self.__pixmap = self.__icon_theme.lookup_icon(iconname)
+        except:
             self.__pixmap = self.__icon_theme.lookup_icon(self.__UNKNOWN_ICON)
 
         try:
