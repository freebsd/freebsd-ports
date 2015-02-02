--- src/calibre/linux.py.orig	2014-08-08 03:21:35 UTC
+++ src/calibre/linux.py
@@ -831,6 +831,7 @@ class PostInstall:
                 f.close()
                 des = ('calibre-gui.desktop', 'calibre-lrfviewer.desktop',
                         'calibre-ebook-viewer.desktop', 'calibre-ebook-edit.desktop')
+		dtpdirs = ('gnome/apps', 'applications')
                 appdata = os.path.join(os.path.dirname(self.opts.staging_sharedir), 'appdata')
                 if not os.path.exists(appdata):
                     try:
@@ -845,8 +846,10 @@ class PostInstall:
 
                 APPDATA = get_appdata()
                 for x in des:
-                    cmd = ['xdg-desktop-menu', 'install', '--noupdate', './'+x]
-                    cc(' '.join(cmd), shell=True)
+                    for z in dtpdirs:
+                        dest = os.path.join(self.opts.staging_root, 'share', z)
+                        cmd = ['cp', './'+x, dest]
+                        cc(' '.join(cmd), shell=True)
                     self.menu_resources.append(x)
                     ak = x.partition('.')[0]
                     if ak in APPDATA and os.access(appdata, os.W_OK):
@@ -992,7 +995,7 @@ Name=E-book Viewer
 GenericName=Viewer for E-books
 Comment=Viewer for E-books in all the major formats
 TryExec=ebook-viewer
-Exec=ebook-viewer --detach %f
+Exec=ebook-viewer %f
 Icon=calibre-viewer
 Categories=Graphics;Viewer;
 '''
@@ -1005,7 +1008,7 @@ Name=Edit E-book
 GenericName=Edit E-books
 Comment=Edit e-books in various formats
 TryExec=ebook-edit
-Exec=ebook-edit --detach %f
+Exec=ebook-edit %f
 Icon=calibre-ebook-edit
 Categories=Office;
 '''
@@ -1018,7 +1021,7 @@ Name=calibre
 GenericName=E-book library management
 Comment=E-book library management: Convert, view, share, catalogue all your e-books
 TryExec=calibre
-Exec=calibre --detach %F
+Exec=calibre %F
 Icon=calibre-gui
 Categories=Office;
 '''
