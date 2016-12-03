--- setup.py.orig	2016-11-03 15:31:44 UTC
+++ setup.py
@@ -452,7 +452,7 @@ class build(_build_orig):
          lambda self: 'py2app' in self.distribution.commands),
         ('build_ui', None),
         ('build_qrc', lambda self: 'py2exe' in self.distribution.commands),
-        ('build_mo', None),
+%%NLS%%        ('build_mo', None),
         ] + _build_orig.sub_commands
 
 class clean(_clean_orig):
@@ -666,10 +666,10 @@ def setup_posix():
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
 
