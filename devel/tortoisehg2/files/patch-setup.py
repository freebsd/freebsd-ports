--- setup.py_	2011-05-02 07:06:56.000000000 +0400
+++ setup.py	2011-05-25 15:54:34.833312978 +0400
@@ -283,7 +283,7 @@
 class build(_build_orig):
     sub_commands = [
         ('build_qt', None),
-        ('build_mo', None),
+%%NLS%%        ('build_mo', None),
         ] + _build_orig.sub_commands
 
 class clean(_clean_orig):
@@ -299,10 +299,10 @@
 cmdclass = {
         'build': build,
         'build_qt': build_qt ,
-        'build_mo': build_mo ,
+%%NLS%%        'build_mo': build_mo ,
         'clean': clean,
         'clean_local': clean_local,
-        'update_pot': update_pot ,
+%%NLS%%        'update_pot': update_pot ,
     }
 
 def setup_windows(version):
@@ -407,11 +407,11 @@
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
