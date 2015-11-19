--- setup.py.orig	2011-02-13 22:40:05 UTC
+++ setup.py
@@ -58,9 +58,9 @@ setup(name='Mirage',
 			],
 		py_modules = ['mirage'],
 		ext_modules = [Extension(name='imgfuncs', sources=['imgfuncs.c']), 
-		               Extension(name='xmouse', sources=['xmouse.c'], libraries=['X11'])],
+		               Extension(name='xmouse', sources=['xmouse.c'], include_dirs=['%%LOCALBASE%%/include'], library_dirs=['%%LOCALBASE%%/lib'], libraries=['X11'])],
 		scripts = ['mirage'],
-		data_files=[('share/mirage', ['README', 'COPYING', 'CHANGELOG', 'TODO', 'TRANSLATORS', 'stock_shuffle.png', 'stock_leave-fullscreen.png', 'stock_fullscreen.png', 'mirage_blank.png']),
+		data_files=[('share/mirage', ['stock_shuffle.png', 'stock_leave-fullscreen.png', 'stock_fullscreen.png', 'mirage_blank.png']),
 			('share/applications', ['mirage.desktop']),
 			('share/pixmaps', ['mirage.png']),
 			('share/locale/ru/LC_MESSAGES', ['mo/ru/mirage.mo']),
