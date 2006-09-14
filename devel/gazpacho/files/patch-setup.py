--- setup.py.orig	Tue Sep 12 13:54:16 2006
+++ setup.py	Tue Sep 12 13:55:22 2006
@@ -7,8 +7,6 @@
 from gazpacho import __version__
 
 data_files = [
-    ('share/doc/gazpacho', ('AUTHORS', 'ChangeLog', 'CONTRIBUTORS',
-                            'COPYING', 'README', 'NEWS')),
     ('share/doc/gazpacho/examples', listfiles('examples', '*')),
     ('$datadir/catalogs', listfiles('catalogs', 'base.xml')),
     ('$datadir/pixmaps', listfiles('pixmaps', '*.png')),
@@ -17,7 +15,6 @@
     ]
 resources = dict(locale='$prefix/share/locale')
 global_resources = dict(
-    doc='$prefix/share/doc/gazpacho',
     pixmap='$datadir/pixmaps',
     glade='$datadir/glade',
     resource='$datadir/resources',
