--- setup.py.orig	2015-08-06 04:30:23.000000000 +0300
+++ setup.py	2015-09-05 21:24:08.309849781 +0300
@@ -413,7 +413,7 @@
         ('build_config', lambda self: os.name != 'nt'),
         ('build_ui', None),
         ('build_qrc', lambda self: 'py2exe' in self.distribution.commands),
-        ('build_mo', None),
+%%NLS%%        ('build_mo', None),
         ] + _build_orig.sub_commands
 
 class clean(_clean_orig):
@@ -567,10 +567,10 @@
             dirs.remove('svg')  # drop source of .ico files
         _data_files.append((os.path.join('share/pixmaps/tortoisehg', root),
                             [os.path.join(root, f) for f in files]))
-    _data_files.extend((os.path.join('share', modir), [mofile])
-                       for pofile, modir, mofile in _walklocales())
-    _data_files += [('share/nautilus-python/extensions',
-                     ['contrib/nautilus-thg.py'])]
+%%NLS%%    _data_files.extend((os.path.join('share', modir), [mofile])
+%%NLS%%                       for pofile, modir, mofile in _walklocales())
+%%NAUTILUS%%    _data_files += [('share/nautilus-python/extensions',
+%%NAUTILUS%%                     ['contrib/nautilus-thg.py'])]
 
     return _scripts, _packages, _data_files, _extra
 
