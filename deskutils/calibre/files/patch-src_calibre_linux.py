--- src/calibre/linux.py.orig	2020-11-13 01:58:49 UTC
+++ src/calibre/linux.py
@@ -1103,7 +1103,7 @@ Name=E-book viewer
 GenericName=Viewer for E-books
 Comment=Viewer for E-books in all the major formats
 TryExec=ebook-viewer
-Exec=ebook-viewer --detach %f
+Exec=ebook-viewer %f
 Icon=calibre-viewer
 Categories=Graphics;Viewer;
 '''
@@ -1116,7 +1116,7 @@ Name=E-book editor
 GenericName=Editor for E-books
 Comment=Edit E-books in various formats
 TryExec=ebook-edit
-Exec=ebook-edit --detach %f
+Exec=ebook-edit %f
 Icon=calibre-ebook-edit
 Categories=Office;
 '''
@@ -1129,7 +1129,7 @@ Name=calibre
 GenericName=E-book library management
 Comment=E-book library management: Convert, view, share, catalogue all your e-books
 TryExec=calibre
-Exec=calibre --detach %U
+Exec=calibre %U
 Icon=calibre-gui
 Categories=Office;
 X-GNOME-UsesNotifications=true
