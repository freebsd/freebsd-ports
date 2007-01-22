--- setup.py	Mon Jan 22 00:26:11 2007
+++ setup.py.port	Mon Jan 22 10:48:16 2007
@@ -38,7 +38,7 @@
         extra_link_args=capture("pkg-config --libs gtk+-2.0 pygtk-2.0").split()
          ),],
         scripts = ['sonata'],
-        data_files=[('share/sonata', ['README', 'CHANGELOG', 'TODO', 'TRANSLATORS']),
+        data_files=[('share/doc/sonata', ['README', 'CHANGELOG', 'TODO', 'TRANSLATORS']),
                     ('share/applications', ['sonata.desktop']),
                     ('share/pixmaps', ['pixmaps/sonata.png', 'pixmaps/sonata_large.png', 'pixmaps/sonatacd.png', 'pixmaps/sonatacd_large.png', 'pixmaps/sonata-artist.png', 'pixmaps/sonata-album.png']),
                     ('share/locale/de/LC_MESSAGES', ['locale/de/LC_MESSAGES/sonata.mo']),
