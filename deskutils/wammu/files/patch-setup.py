--- ./setup.py.orig	2010-05-14 16:52:21.000000000 +0400
+++ ./setup.py	2010-05-14 16:52:51.000000000 +0400
@@ -346,11 +346,11 @@
     'icon/wammu.ico',
     'icon/wammu.svg',
     ]))
-data_files.append((os.path.join('share','man','man1'), ['wammu.1', 'wammu-configure.1']))
-data_files.append((os.path.join('share','man','cs','man1'), ['man/cs/wammu.1', 'man/cs/wammu-configure.1']))
-data_files.append((os.path.join('share','man','de','man1'), ['man/de/wammu.1', 'man/de/wammu-configure.1']))
-data_files.append((os.path.join('share','man','nl','man1'), ['man/nl/wammu.1', 'man/nl/wammu-configure.1']))
-data_files.append((os.path.join('share','man','it','man1'), ['man/it/wammu.1', 'man/it/wammu-configure.1']))
+data_files.append((os.path.join('man','man1'), ['wammu.1', 'wammu-configure.1']))
+data_files.append((os.path.join('man','cs','man1'), ['man/cs/wammu.1', 'man/cs/wammu-configure.1']))
+data_files.append((os.path.join('man','de','man1'), ['man/de/wammu.1', 'man/de/wammu-configure.1']))
+data_files.append((os.path.join('man','nl','man1'), ['man/nl/wammu.1', 'man/nl/wammu-configure.1']))
+data_files.append((os.path.join('man','it','man1'), ['man/it/wammu.1', 'man/it/wammu-configure.1']))
 
 distutils.core.setup(name="wammu",
     version = Wammu.__version__,
