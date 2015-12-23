--- src/calibre/linux.py.orig	2015-08-28 03:16:27 UTC
+++ src/calibre/linux.py
@@ -997,7 +997,7 @@ Name=E-book Viewer
 GenericName=Viewer for E-books
 Comment=Viewer for E-books in all the major formats
 TryExec=ebook-viewer
-Exec=ebook-viewer --detach %f
+Exec=ebook-viewer %f
 Icon=calibre-viewer
 Categories=Graphics;Viewer;
 '''
@@ -1010,7 +1010,7 @@ Name=Edit E-book
 GenericName=Edit E-books
 Comment=Edit e-books in various formats
 TryExec=ebook-edit
-Exec=ebook-edit --detach %f
+Exec=ebook-edit %f
 Icon=calibre-ebook-edit
 Categories=Office;
 '''
@@ -1023,7 +1023,7 @@ Name=calibre
 GenericName=E-book library management
 Comment=E-book library management: Convert, view, share, catalogue all your e-books
 TryExec=calibre
-Exec=calibre --detach %F
+Exec=calibre %F
 Icon=calibre-gui
 Categories=Office;
 '''
