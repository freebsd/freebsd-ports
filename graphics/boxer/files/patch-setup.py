--- setup.py.orig	2013-09-07 13:33:14.000000000 +0200
+++ setup.py	2013-09-09 17:07:54.000000000 +0200
@@ -31,15 +31,7 @@
 packages = ['boxer', 'boxer.lib', 'boxer.lib.dox', 'boxer.lib.comparse']
 package_dir = {'boxer': 'src'}
 
-examples = \
-  ['fractal.box', 'fractree.box', 'wheatstone.box', 'planes.box',
-   'tutorial*.box', 'curve.png']
-
-examples_fullpaths = list(os.path.join('examples', bn)
-                          for bn in examples)
-
-package_data = {'boxer': (examples_fullpaths +
-                          ['icons/24x24/*.png',
+package_data = {'boxer': (['icons/24x24/*.png',
                            'icons/32x32/*.png',
                            'icons/fonts/*.png',
                            'hl/*.lang'])}
