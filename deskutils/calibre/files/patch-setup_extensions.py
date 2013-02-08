--- setup/extensions.py.orig	2013-01-04 06:02:00.000000000 +0100
+++ setup/extensions.py	2013-01-05 18:07:03.534921171 +0100
@@ -492,8 +492,9 @@
 
         pro = textwrap.dedent('''
         TEMPLATE = lib
-        CONFIG += qt plugin release
+        CONFIG += qt plugin release link_pkgconfig
         CONFIG -= embed_manifest_dll
+        PKGCONFIG += glib-2.0 gtk+-2.0
         VERSION = 1.0.0
         DESTDIR = .
         TARGET = calibre
