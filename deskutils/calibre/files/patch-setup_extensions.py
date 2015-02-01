--- setup/extensions.py.orig	2013-11-22 10:29:37.000000000 -0600
+++ setup/extensions.py	2013-11-22 10:30:39.000000000 -0600
@@ -496,8 +489,9 @@
 
         pro = textwrap.dedent('''
         TEMPLATE = lib
-        CONFIG += qt plugin release
+        CONFIG += qt plugin release link_pkgconfig
         CONFIG -= embed_manifest_dll
+        PKGCONFIG += glib-2.0 gtk+-2.0
         VERSION = 1.0.0
         DESTDIR = .
         TARGET = calibre
