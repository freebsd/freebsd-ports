--- setup_.py	2013-09-06 04:45:26.000000000 +0400
+++ setup.py	2013-09-09 09:31:13.148575638 +0400
@@ -362,7 +362,7 @@
 class build(_build_orig):
     sub_commands = [
         ('build_qt', None),
-        ('build_mo', None),
+%%NLS%%        ('build_mo', None),
         ] + _build_orig.sub_commands
 
 class clean(_clean_orig):
@@ -381,7 +381,7 @@
         'build_mo': build_mo ,
         'clean': clean,
         'clean_local': clean_local,
-        'update_pot': update_pot ,
+%%NLS%%        'update_pot': update_pot ,
         'import_po': import_po
     }
 
@@ -501,11 +501,11 @@
     _data_files = [(os.path.join('share/pixmaps/tortoisehg', root),
         [os.path.join(root, file_) for file_ in files])
         for root, dirs, files in os.walk('icons')]
-    _data_files += [(os.path.join('share', root),
-        [os.path.join(root, file_) for file_ in files])
-        for root, dirs, files in os.walk('locale')]
-    _data_files += [('/usr/share/nautilus-python/extensions/',
-                     ['contrib/nautilus-thg.py'])]
+%%NLS%%    _data_files += [(os.path.join('share', root),
+%%NLS%%        [os.path.join(root, file_) for file_ in files])
+%%NLS%%        for root, dirs, files in os.walk('locale')]
+%%NAUTILUS%%    _data_files += [('%%PREFIX%%/lib/nautilus/extensions-2.0/python',
+%%NAUTILUS%%                     ['contrib/nautilus-thg.py'])]
 
     # Create a config.py.  Distributions will need to supply their own
     cfgfile = os.path.join('tortoisehg', 'util', 'config.py')
