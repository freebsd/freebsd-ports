--- setup.py.orig	2021-05-07 23:55:00 UTC
+++ setup.py
@@ -730,10 +730,10 @@ def setup_posix():
     # install SVG icon for the desktop file
     _data_files.append(('share/pixmaps', ['icons/svg/thg_logo.svg']))
     _data_files.append(('share/doc/tortoisehg', ['COPYING.txt']))
-    _data_files.extend((os.path.join('share', modir), [mofile])
-                       for pofile, modir, mofile in _walklocales())
-    _data_files += [('share/nautilus-python/extensions',
-                     ['contrib/nautilus-thg.py'])]
+%%NLS%%    _data_files.extend((os.path.join('share', modir), [mofile])
+%%NLS%%                       for pofile, modir, mofile in _walklocales())
+%%NAUTILUS%%    _data_files += [('share/nautilus-python/extensions',
+%%NAUTILUS%%                     ['contrib/nautilus-thg.py'])]
 
     return _scripts, _packages, _data_files, _extra
 
