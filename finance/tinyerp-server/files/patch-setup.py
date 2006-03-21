--- setup.py.orig	Mon Jan 23 09:43:47 2006
+++ setup.py	Mon Mar 20 17:47:25 2006
@@ -59,12 +59,8 @@
 
 def data_files():
     '''Build list of data files to be installed'''
-    files = [(opj('share', 'man', 'man1'),
+    files = [(opj('man', 'man1'),
               ['man/tinyerp-server.1']),
-             (opj('share','doc', 'tinyerp-server-%s' % version), 
-              [f for f in glob.glob('doc/*') if os.path.isfile(f)]),
-             (opj('share','doc','tinyerp-server-%s' % version, 'i18n'), 
-              glob.glob('doc/i18n/*')),
              (opj('lib', 'python%s' % py_short_version, 'site-packages', 'tinyerp-server', 'addons', 'custom'),
               glob.glob('bin/addons/custom/*xml') + 
               glob.glob('bin/addons/custom/*xsl'))]
