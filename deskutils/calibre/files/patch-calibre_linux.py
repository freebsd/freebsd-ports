--- src/calibre/linux.py.orig	2013-11-22 04:20:51.000000000 +0100
+++ src/calibre/linux.py	2013-11-30 11:05:18.115881824 +0100
@@ -700,9 +700,12 @@
                 f.close()
                 des = ('calibre-gui.desktop', 'calibre-lrfviewer.desktop',
                         'calibre-ebook-viewer.desktop')
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
