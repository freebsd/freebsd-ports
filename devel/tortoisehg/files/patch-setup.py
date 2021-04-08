--- setup.py.orig	2021-02-03 05:58:06 UTC
+++ setup.py
@@ -218,8 +218,7 @@ class build_config(Command):
             'license_path': os.path.join(sharedir, 'doc', 'tortoisehg',
                                          'Copying.txt.gz'),
             'locale_path': os.path.join(sharedir, 'locale'),
-            'icon_path': os.path.join(sharedir, 'pixmaps', 'tortoisehg',
-                                      'icons'),
+            'icon_path': os.path.join(sharedir, 'pixmaps', 'tortoisehg'),
             'nofork': True,
             'qt_api': qtcore._detectapi(),
             }
@@ -488,7 +487,7 @@ class build(_build_orig):
          lambda self: 'py2app' in self.distribution.commands),
         ('build_ui', None),
         ('build_qrc', lambda self: 'py2exe' in self.distribution.commands),
-        ('build_mo', None),
+%%NLS%%        ('build_mo', None),
         ] + _build_orig.sub_commands
 
 class clean(_clean_orig):
@@ -723,12 +722,14 @@ def setup_posix():
     for root, dirs, files in os.walk('icons'):
         if root == 'icons':
             dirs.remove('svg')  # drop source of .ico files
-        _data_files.append((os.path.join('share/pixmaps/tortoisehg', root),
+        if not files:
+            continue
+        _data_files.append((os.path.normpath(os.path.join('share/pixmaps/tortoisehg', root.replace("icons", "."))),
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
 
