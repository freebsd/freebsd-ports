--- setup.py	2008-01-16 05:25:41.000000000 +0100
+++ setup.py.port	2008-01-16 23:09:45.000000000 +0100
@@ -43,6 +43,30 @@
 	print "generating", mofile
 	os.system("msgfmt %s -o %s" % (pofile, mofile))
 
+port_data_files = [ ('share/applications', ['sonata.desktop']),
+		    ('share/pixmaps', ['pixmaps/sonata.png', 'pixmaps/sonata_large.png', 'pixmaps/sonatacd.png', 'pixmaps/sonatacd_large.png', 'pixmaps/sonata-artist.png', 'pixmaps/sonata-album.png', 'pixmaps/sonata-stock_volume-mute.png', 'pixmaps/sonata-stock_volume-min.png', 'pixmaps/sonata-stock_volume-med.png', 'pixmaps/sonata-stock_volume-max.png', 'pixmaps/sonata_pause.png', 'pixmaps/sonata_play.png', 'pixmaps/sonata_disconnect.png']),
+                    ('share/locale/de/LC_MESSAGES', ['mo/de/sonata.mo']),
+                    ('share/locale/pl/LC_MESSAGES', ['mo/pl/sonata.mo']),
+                    ('share/locale/ru/LC_MESSAGES', ['mo/ru/sonata.mo']),
+                    ('share/locale/fr/LC_MESSAGES', ['mo/fr/sonata.mo']),
+                    ('share/locale/zh_CN/LC_MESSAGES', ['mo/zh_CN/sonata.mo']),
+                    ('share/locale/sv/LC_MESSAGES', ['mo/sv/sonata.mo']),
+                    ('share/locale/es/LC_MESSAGES', ['mo/es/sonata.mo']),
+                    ('share/locale/fi/LC_MESSAGES', ['mo/fi/sonata.mo']),
+                    ('share/locale/nl/LC_MESSAGES', ['mo/nl/sonata.mo']),
+                    ('share/locale/it/LC_MESSAGES', ['mo/it/sonata.mo']),
+                    ('share/locale/cs/LC_MESSAGES', ['mo/cs/sonata.mo']),
+                    ('share/locale/da/LC_MESSAGES', ['mo/da/sonata.mo']),
+                    ('share/locale/pt_BR/LC_MESSAGES', ['mo/pt_BR/sonata.mo']),
+                    ('share/locale/be@latin/LC_MESSAGES', ['mo/be@latin/sonata.mo']),
+                    ('share/locale/uk/LC_MESSAGES', ['mo/uk/sonata.mo'])]
+
+if not os.environ.has_key("NOPORTDOCS"):
+	port_data_files.append(('%%DOCSDIR%%', ['README']))
+
+if not os.environ.has_key("NO_INSTALL_MANPAGES"):
+	port_data_files.append(('man/man1', ['sonata.1']))
+
 setup(name='Sonata',
         version='1.4',
         description='GTK+ client for the Music Player Daemon (MPD).',
@@ -65,27 +89,9 @@
         extra_link_args=capture("pkg-config --libs gtk+-2.0 pygtk-2.0").split()
          ),],
         scripts = ['sonata'],
-        data_files=[('share/sonata', ['README', 'CHANGELOG', 'TODO', 'TRANSLATORS']),
-                    ('share/applications', ['sonata.desktop']),
-                    ('share/pixmaps', ['pixmaps/sonata.png', 'pixmaps/sonata_large.png', 'pixmaps/sonatacd.png', 'pixmaps/sonatacd_large.png', 'pixmaps/sonata-artist.png', 'pixmaps/sonata-album.png', 'pixmaps/sonata-stock_volume-mute.png', 'pixmaps/sonata-stock_volume-min.png', 'pixmaps/sonata-stock_volume-med.png', 'pixmaps/sonata-stock_volume-max.png', 'pixmaps/sonata_pause.png', 'pixmaps/sonata_play.png', 'pixmaps/sonata_disconnect.png']),
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
-                    ('share/locale/be@latin/LC_MESSAGES', ['mo/be@latin/sonata.mo']),
-                    ('share/locale/uk/LC_MESSAGES', ['mo/uk/sonata.mo'])],
-        )
-
+	data_files = port_data_files,
+	)
+	
 # Cleanup (remove /build, /mo, and *.pyc files:
 print "Cleaning up..."
 try:
