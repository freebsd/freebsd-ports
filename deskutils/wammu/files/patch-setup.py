--- setup.py.orig	2010-09-07 13:28:17.000000000 +0400
+++ setup.py	2010-09-08 15:00:34.203678636 +0400
@@ -346,13 +346,13 @@ data_files.append((os.path.join('share',
     'icon/wammu.ico',
     'icon/wammu.svg',
     ]))
-data_files.append((os.path.join('share','man','man1'), ['wammu.1', 'wammu-configure.1']))
-data_files.append((os.path.join('share','man','cs','man1'), ['man/cs/wammu.1', 'man/cs/wammu-configure.1']))
-data_files.append((os.path.join('share','man','de','man1'), ['man/de/wammu.1', 'man/de/wammu-configure.1']))
-data_files.append((os.path.join('share','man','nl','man1'), ['man/nl/wammu.1', 'man/nl/wammu-configure.1']))
-data_files.append((os.path.join('share','man','it','man1'), ['man/it/wammu.1', 'man/it/wammu-configure.1']))
-data_files.append((os.path.join('share','man','sk','man1'), ['man/sk/wammu.1', 'man/sk/wammu-configure.1']))
-data_files.append((os.path.join('share','man','ru','man1'), ['man/ru/wammu.1', 'man/ru/wammu-configure.1']))
+data_files.append((os.path.join('man','man1'), ['wammu.1', 'wammu-configure.1']))
+data_files.append((os.path.join('man','cs','man1'), ['man/cs/wammu.1', 'man/cs/wammu-configure.1']))
+data_files.append((os.path.join('man','de','man1'), ['man/de/wammu.1', 'man/de/wammu-configure.1']))
+data_files.append((os.path.join('man','nl','man1'), ['man/nl/wammu.1', 'man/nl/wammu-configure.1']))
+data_files.append((os.path.join('man','it','man1'), ['man/it/wammu.1', 'man/it/wammu-configure.1']))
+data_files.append((os.path.join('man','sk','man1'), ['man/sk/wammu.1', 'man/sk/wammu-configure.1']))
+data_files.append((os.path.join('man','ru','man1'), ['man/ru/wammu.1', 'man/ru/wammu-configure.1']))
 
 distutils.core.setup(name="wammu",
     version = Wammu.__version__,
