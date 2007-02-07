--- gimmie/gimmie_util.py.orig	Tue Feb  6 19:54:52 2007
+++ gimmie/gimmie_util.py	Tue Feb  6 19:55:07 2007
@@ -625,7 +625,6 @@
     DEFAULT_BOOKMARKS = [
         ("firefox.desktop", "application/x-desktop", "gimmie.gimmie_applications.DesktopFileItem"),
         ("nautilus.desktop", "application/x-desktop", "gimmie.gimmie_applications.DesktopFileItem"),
-        (os.path.abspath("README"), "text/plain", "gimmie.gimmie_file.FileItem"),
         ("aim:goim?screenname=\"orphennui\"", "gaim/buddy", "gimmie.gimmie_gaim.GaimBuddy"),
         ]
     
