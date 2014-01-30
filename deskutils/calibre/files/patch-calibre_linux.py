--- src/calibre/linux.py.orig	2014-01-24 05:56:21.000000000 +0100
+++ src/calibre/linux.py	2014-01-29 00:30:43.102775394 +0100
@@ -712,9 +712,12 @@
                 f.close()
                 des = ('calibre-gui.desktop', 'calibre-lrfviewer.desktop',
                         'calibre-ebook-viewer.desktop', 'calibre-ebook-edit.desktop')
+                dtpdirs = ('gnome/apps', 'applications')
                 for x in des:
-                    cmd = ['xdg-desktop-menu', 'install', '--noupdate', './'+x]
-                    cc(' '.join(cmd), shell=True)
+                    for z in dtpdirs:
+                        dest = os.path.join(self.opts.staging_root, 'share', z)
+                        cmd = ['cp', './'+x, dest]
+                        cc(' '.join(cmd), shell=True)
                     self.menu_resources.append(x)
                 cc(['xdg-desktop-menu', 'forceupdate'])
                 f = open('calibre-mimetypes.xml', 'wb')
