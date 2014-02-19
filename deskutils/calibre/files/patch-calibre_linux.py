--- src/calibre/linux.py.orig	2014-02-09 13:42:40.000000000 -0600
+++ src/calibre/linux.py	2014-02-09 13:43:59.000000000 -0600
@@ -712,6 +712,7 @@
                 f.close()
                 des = ('calibre-gui.desktop', 'calibre-lrfviewer.desktop',
                         'calibre-ebook-viewer.desktop', 'calibre-ebook-edit.desktop')
+		dtpdirs = ('gnome/apps', 'applications')
                 appdata = os.path.join(os.path.dirname(self.opts.staging_sharedir), 'appdata')
                 if not os.path.exists(appdata):
                     try:
@@ -726,8 +727,10 @@
 
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
