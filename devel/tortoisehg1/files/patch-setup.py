--- setup.py.orig	2011-05-14 11:28:04.810695095 +0100
+++ setup.py	2011-05-14 11:29:33.105770244 +0100
@@ -147,11 +147,11 @@
     _data_files = [(os.path.join('share/pixmaps/tortoisehg', root),
         [os.path.join(root, file_) for file_ in files])
         for root, dirs, files in os.walk('icons')]
-    _data_files += [(os.path.join('share', root),
-        [os.path.join(root, file_) for file_ in files])
-        for root, dirs, files in os.walk('locale')]
-    _data_files += [('lib/nautilus/extensions-2.0/python',
-                     ['contrib/nautilus-thg.py'])]
+%%NLS%%    _data_files += [(os.path.join('share', root),
+%%NLS%%        [os.path.join(root, file_) for file_ in files])
+%%NLS%%        for root, dirs, files in os.walk('locale')]
+%%NAUTILUS%%    _data_files += [('lib/nautilus/extensions-2.0/python',
+%%NAUTILUS%%                     ['contrib/nautilus-thg.py'])]
 
     # Create a config.py.  Distributions will need to supply their own
     cfgfile = os.path.join('tortoisehg', 'util', 'config.py')
