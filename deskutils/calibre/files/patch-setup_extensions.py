--- setup/extensions.py.orig	2013-03-29 06:15:02.000000000 +0100
+++ setup/extensions.py	2013-04-09 18:10:19.236217223 +0200
@@ -183,13 +183,6 @@
                 sip_files = ['calibre/gui2/progress_indicator/QProgressIndicator.sip']
                 ),
 
-    Extension('qt_hack',
-                ['calibre/ebooks/pdf/render/qt_hack.cpp'],
-                inc_dirs = qt_private_inc + ['calibre/ebooks/pdf/render', 'qt-harfbuzz/src'],
-                headers = ['calibre/ebooks/pdf/render/qt_hack.h'],
-                sip_files = ['calibre/ebooks/pdf/render/qt_hack.sip']
-                ),
-
     Extension('unrar',
               ['unrar/%s.cpp'%(x.partition('.')[0]) for x in '''
                rar.o strlist.o strfn.o pathfn.o savepos.o smallfn.o global.o file.o
@@ -492,8 +485,9 @@
 
         pro = textwrap.dedent('''
         TEMPLATE = lib
-        CONFIG += qt plugin release
+        CONFIG += qt plugin release link_pkgconfig
         CONFIG -= embed_manifest_dll
+        PKGCONFIG += glib-2.0 gtk+-2.0
         VERSION = 1.0.0
         DESTDIR = .
         TARGET = calibre
