--- setup.py.orig	2007-03-05 16:06:37 UTC
+++ setup.py
@@ -8,8 +8,6 @@ from gazpacho import __version__
 
 templates = []
 data_files = [
-    ('share/doc/gazpacho', ('AUTHORS', 'ChangeLog', 'CONTRIBUTORS',
-                            'COPYING', 'README', 'NEWS')),
     ('share/doc/gazpacho/examples', listfiles('examples', '*')),
     ('$datadir/catalogs', listfiles('catalogs', 'base.xml')),
     ('$datadir/pixmaps', listfiles('pixmaps', '*.png')),
@@ -34,7 +32,6 @@ data_files.extend(list_plugins())
 
 resources = dict(locale='$prefix/share/locale')
 global_resources = dict(
-    doc='$prefix/share/doc/gazpacho',
     pixmap='$datadir/pixmaps',
     glade='$datadir/glade',
     resource='$datadir/resources',
