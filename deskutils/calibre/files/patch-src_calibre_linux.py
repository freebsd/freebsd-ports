--- src/calibre/linux.py.orig	2018-01-05 05:41:54 UTC
+++ src/calibre/linux.py
@@ -841,7 +841,7 @@ class PostInstall:
                 f.close()
                 des = ('calibre-gui.desktop', 'calibre-lrfviewer.desktop',
                         'calibre-ebook-viewer.desktop', 'calibre-ebook-edit.desktop')
-                appdata = os.path.join(os.path.dirname(self.opts.staging_sharedir), 'metainfo')
+                appdata = os.path.join(os.path.dirname(self.opts.staging_sharedir), 'appdata')
                 if not os.path.exists(appdata):
                     try:
                         os.mkdir(appdata)
@@ -1008,7 +1008,7 @@ Name=E-book Viewer
 GenericName=Viewer for E-books
 Comment=Viewer for E-books in all the major formats
 TryExec=ebook-viewer
-Exec=ebook-viewer --detach %f
+Exec=ebook-viewer %f
 Icon=calibre-viewer
 Categories=Graphics;Viewer;
 '''
@@ -1021,7 +1021,7 @@ Name=E-book Editor
 GenericName=Editor for E-books
 Comment=Edit E-books in various formats
 TryExec=ebook-edit
-Exec=ebook-edit --detach %f
+Exec=ebook-edit %f
 Icon=calibre-ebook-edit
 Categories=Office;
 '''
@@ -1034,7 +1034,7 @@ Name=calibre
 GenericName=E-book library management
 Comment=E-book library management: Convert, view, share, catalogue all your e-books
 TryExec=calibre
-Exec=calibre --detach %F
+Exec=calibre %F
 Icon=calibre-gui
 Categories=Office;
 '''
