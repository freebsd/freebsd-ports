--- src/calibre/linux.py.orig	2023-12-15 00:57:56 UTC
+++ src/calibre/linux.py
@@ -1108,7 +1108,7 @@ TryExec=ebook-viewer
 GenericName=Viewer for E-books
 Comment=Viewer for E-books in all the major formats
 TryExec=ebook-viewer
-Exec=ebook-viewer --detach %f
+Exec=ebook-viewer %f
 Icon=calibre-viewer
 Categories=Office;Viewer;
 '''
@@ -1121,7 +1121,7 @@ TryExec=ebook-edit
 GenericName=Editor for E-books
 Comment=Edit E-books in various formats
 TryExec=ebook-edit
-Exec=ebook-edit --detach %f
+Exec=ebook-edit %f
 Icon=calibre-ebook-edit
 Categories=Office;WordProcessor
 '''
@@ -1134,7 +1134,7 @@ TryExec=calibre
 GenericName=E-book library management
 Comment=E-book library management: Convert, view, share, catalogue all your e-books
 TryExec=calibre
-Exec=calibre --detach %U
+Exec=calibre %U
 Icon=calibre-gui
 Categories=Office;
 X-GNOME-UsesNotifications=true
