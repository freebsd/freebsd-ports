--- setup.py	2008-04-04 01:28:12.000000000 +0200
+++ setup.py.port	2008-04-05 00:50:27.000000000 +0200
@@ -47,6 +47,31 @@
 # Copy script "sonata" file to sonata dir:
 shutil.copyfile("sonata.py", "sonata/sonata")
 
+port_data_files=[('share/applications', ['sonata.desktop']),
+            ('share/pixmaps', glob.glob('sonata/pixmaps/*')),
+            ('share/locale/de/LC_MESSAGES', ['mo/de/sonata.mo']),
+            ('share/locale/pl/LC_MESSAGES', ['mo/pl/sonata.mo']),
+            ('share/locale/ru/LC_MESSAGES', ['mo/ru/sonata.mo']),
+            ('share/locale/fr/LC_MESSAGES', ['mo/fr/sonata.mo']),
+            ('share/locale/zh_CN/LC_MESSAGES', ['mo/zh_CN/sonata.mo']),
+            ('share/locale/sv/LC_MESSAGES', ['mo/sv/sonata.mo']),
+            ('share/locale/es/LC_MESSAGES', ['mo/es/sonata.mo']),
+            ('share/locale/fi/LC_MESSAGES', ['mo/fi/sonata.mo']),
+            ('share/locale/nl/LC_MESSAGES', ['mo/nl/sonata.mo']),
+            ('share/locale/it/LC_MESSAGES', ['mo/it/sonata.mo']),
+            ('share/locale/cs/LC_MESSAGES', ['mo/cs/sonata.mo']),
+            ('share/locale/da/LC_MESSAGES', ['mo/da/sonata.mo']),
+            ('share/locale/pt_BR/LC_MESSAGES', ['mo/pt_BR/sonata.mo']),
+            ('share/locale/et/LC_MESSAGES', ['mo/et/sonata.mo']),
+            ('share/locale/be@latin/LC_MESSAGES', ['mo/be@latin/sonata.mo']),
+            ('share/locale/uk/LC_MESSAGES', ['mo/uk/sonata.mo'])]
+
+if not os.environ.has_key('NOPORTDOCS'):
+	port_data_files.append(('share/doc/sonata', ['README',]))
+
+if not os.environ.has_key('NO_INSTALL_MANPAGES'):
+        port_data_files.append(('man/man1', ['sonata.1']))
+
 setup(name='Sonata',
         version='1.5',
         description='GTK+ client for the Music Player Daemon (MPD).',
@@ -70,27 +95,8 @@
         extra_link_args=capture("pkg-config --libs gtk+-2.0 pygtk-2.0").split()
          ),],
         scripts = ['sonata/sonata'],
-        data_files=[('share/sonata', ['README', 'CHANGELOG', 'TODO', 'TRANSLATORS']),
-                    ('share/applications', ['sonata.desktop']),
-                    ('share/pixmaps', glob.glob('sonata/pixmaps/*')),
-                    ('share/man/man1', ['sonata.1']),
-                    ('share/locale/de/LC_MESSAGES', ['mo/de/sonata.mo']),
-                    ('share/locale/pl/LC_MESSAGES', ['mo/pl/sonata.mo']),
-                    ('share/locale/ru/LC_MESSAGES', ['mo/ru/sonata.mo']),
-                    ('share/locale/fr/LC_MESSAGES', ['mo/fr/sonata.mo']),
-                    ('share/locale/zh_CN/LC_MESSAGES', ['mo/zh_CN/sonata.mo']),
-                    ('share/locale/sv/LC_MESSAGES', ['mo/sv/sonata.mo']),
-                    ('share/locale/es/LC_MESSAGES', ['mo/es/sonata.mo']),
-                    ('share/locale/fi/LC_MESSAGES', ['mo/fi/sonata.mo']),
-                    ('share/locale/nl/LC_MESSAGES', ['mo/nl/sonata.mo']),
-                    ('share/locale/it/LC_MESSAGES', ['mo/it/sonata.mo']),
-                    ('share/locale/cs/LC_MESSAGES', ['mo/cs/sonata.mo']),
-                    ('share/locale/da/LC_MESSAGES', ['mo/da/sonata.mo']),
-                    ('share/locale/pt_BR/LC_MESSAGES', ['mo/pt_BR/sonata.mo']),
-                    ('share/locale/et/LC_MESSAGES', ['mo/et/sonata.mo']),
-                    ('share/locale/be@latin/LC_MESSAGES', ['mo/be@latin/sonata.mo']),
-                    ('share/locale/uk/LC_MESSAGES', ['mo/uk/sonata.mo'])],
-        )
+	data_files = port_data_files,
+    )
 
 # Cleanup (remove /build, /mo, and *.pyc files:
 print "Cleaning up..."
