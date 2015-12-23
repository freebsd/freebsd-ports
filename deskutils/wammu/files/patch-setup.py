--- setup.py.orig	2015-11-23 14:47:59 UTC
+++ setup.py
@@ -385,23 +385,23 @@ data_files.append((os.path.join('share',
     'icon/wammu.ico',
     'icon/wammu.svg',
     ]))
-data_files.append((os.path.join('share', 'man', 'man1'), ['wammu.1', 'wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'cs', 'man1'), ['man/cs/wammu.1', 'man/cs/wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'de', 'man1'), ['man/de/wammu.1', 'man/de/wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'en_GB', 'man1'), ['man/en_GB/wammu.1', 'man/en_GB/wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'es', 'man1'), ['man/es/wammu.1', 'man/es/wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'et', 'man1'), ['man/et/wammu.1', 'man/et/wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'da', 'man1'), ['man/da/wammu.1', 'man/da/wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'fr', 'man1'), ['man/fr/wammu.1', 'man/fr/wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'hu', 'man1'), ['man/hu/wammu.1']))
-data_files.append((os.path.join('share', 'man', 'id', 'man1'), ['man/id/wammu.1', 'man/id/wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'it', 'man1'), ['man/it/wammu.1', 'man/it/wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'nl', 'man1'), ['man/nl/wammu.1', 'man/nl/wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'pt_BR', 'man1'), ['man/pt_BR/wammu.1', 'man/pt_BR/wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'ru', 'man1'), ['man/ru/wammu.1', 'man/ru/wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'sk', 'man1'), ['man/sk/wammu.1', 'man/sk/wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'tr', 'man1'), ['man/sk/wammu.1', 'man/tr/wammu-configure.1']))
-data_files.append((os.path.join('share', 'man', 'uk', 'man1'), ['man/sk/wammu.1', 'man/uk/wammu-configure.1']))
+data_files.append((os.path.join('man', 'man1'), ['wammu.1', 'wammu-configure.1']))
+data_files.append((os.path.join('man', 'cs', 'man1'), ['man/cs/wammu.1', 'man/cs/wammu-configure.1']))
+data_files.append((os.path.join('man', 'de', 'man1'), ['man/de/wammu.1', 'man/de/wammu-configure.1']))
+data_files.append((os.path.join('man', 'en_GB', 'man1'), ['man/en_GB/wammu.1', 'man/en_GB/wammu-configure.1']))
+data_files.append((os.path.join('man', 'es', 'man1'), ['man/es/wammu.1', 'man/es/wammu-configure.1']))
+data_files.append((os.path.join('man', 'et', 'man1'), ['man/et/wammu.1', 'man/et/wammu-configure.1']))
+data_files.append((os.path.join('man', 'da', 'man1'), ['man/da/wammu.1', 'man/da/wammu-configure.1']))
+data_files.append((os.path.join('man', 'fr', 'man1'), ['man/fr/wammu.1', 'man/fr/wammu-configure.1']))
+data_files.append((os.path.join('man', 'hu', 'man1'), ['man/hu/wammu.1']))
+data_files.append((os.path.join('man', 'id', 'man1'), ['man/id/wammu.1', 'man/id/wammu-configure.1']))
+data_files.append((os.path.join('man', 'it', 'man1'), ['man/it/wammu.1', 'man/it/wammu-configure.1']))
+data_files.append((os.path.join('man', 'nl', 'man1'), ['man/nl/wammu.1', 'man/nl/wammu-configure.1']))
+data_files.append((os.path.join('man', 'pt_BR', 'man1'), ['man/pt_BR/wammu.1', 'man/pt_BR/wammu-configure.1']))
+data_files.append((os.path.join('man', 'ru', 'man1'), ['man/ru/wammu.1', 'man/ru/wammu-configure.1']))
+data_files.append((os.path.join('man', 'sk', 'man1'), ['man/sk/wammu.1', 'man/sk/wammu-configure.1']))
+data_files.append((os.path.join('man', 'tr', 'man1'), ['man/sk/wammu.1', 'man/tr/wammu-configure.1']))
+data_files.append((os.path.join('man', 'uk', 'man1'), ['man/sk/wammu.1', 'man/uk/wammu-configure.1']))
 
 distutils.core.setup(
     name="wammu",
