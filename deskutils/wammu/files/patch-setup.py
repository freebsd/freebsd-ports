--- setup.py.orig	2011-09-15 09:09:48 UTC
+++ setup.py
@@ -346,16 +346,16 @@ data_files.append((os.path.join('share',
     'icon/wammu.ico',
     'icon/wammu.svg',
     ]))
-data_files.append((os.path.join('share','man','man1'), ['wammu.1', 'wammu-configure.1']))
-data_files.append((os.path.join('share','man','cs','man1'), ['man/cs/wammu.1', 'man/cs/wammu-configure.1']))
-data_files.append((os.path.join('share','man','de','man1'), ['man/de/wammu.1', 'man/de/wammu-configure.1']))
-data_files.append((os.path.join('share','man','fr','man1'), ['man/fr/wammu.1', 'man/fr/wammu-configure.1']))
-data_files.append((os.path.join('share','man','nl','man1'), ['man/nl/wammu.1', 'man/nl/wammu-configure.1']))
-data_files.append((os.path.join('share','man','it','man1'), ['man/it/wammu.1', 'man/it/wammu-configure.1']))
-data_files.append((os.path.join('share','man','sk','man1'), ['man/sk/wammu.1', 'man/sk/wammu-configure.1']))
-data_files.append((os.path.join('share','man','ru','man1'), ['man/ru/wammu.1', 'man/ru/wammu-configure.1']))
-data_files.append((os.path.join('share','man','es','man1'), ['man/es/wammu.1', 'man/es/wammu-configure.1']))
-data_files.append((os.path.join('share','man','pt_BR','man1'), ['man/pt_BR/wammu.1', 'man/pt_BR/wammu-configure.1']))
+data_files.append((os.path.join('man','man1'), ['wammu.1', 'wammu-configure.1']))
+data_files.append((os.path.join('man','cs','man1'), ['man/cs/wammu.1', 'man/cs/wammu-configure.1']))
+data_files.append((os.path.join('man','de','man1'), ['man/de/wammu.1', 'man/de/wammu-configure.1']))
+data_files.append((os.path.join('man','fr','man1'), ['man/fr/wammu.1', 'man/fr/wammu-configure.1']))
+data_files.append((os.path.join('man','nl','man1'), ['man/nl/wammu.1', 'man/nl/wammu-configure.1']))
+data_files.append((os.path.join('man','it','man1'), ['man/it/wammu.1', 'man/it/wammu-configure.1']))
+data_files.append((os.path.join('man','sk','man1'), ['man/sk/wammu.1', 'man/sk/wammu-configure.1']))
+data_files.append((os.path.join('man','ru','man1'), ['man/ru/wammu.1', 'man/ru/wammu-configure.1']))
+data_files.append((os.path.join('man','es','man1'), ['man/es/wammu.1', 'man/es/wammu-configure.1']))
+data_files.append((os.path.join('man','pt_BR','man1'), ['man/pt_BR/wammu.1', 'man/pt_BR/wammu-configure.1']))
 
 distutils.core.setup(name="wammu",
     version = Wammu.__version__,
