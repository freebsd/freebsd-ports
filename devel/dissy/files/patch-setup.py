--- ./setup.py.orig	2010-10-19 05:11:45.000000000 +0200
+++ ./setup.py	2010-10-19 05:13:08.000000000 +0200
@@ -31,9 +31,6 @@
 		      'gfx/red_arrow_right.png', 'gfx/red_plus.png', 'gfx/red_start_up.png',
                       'gfx/icon.svg']),
 		    ('share/%s/' % (Config.PROGRAM_NAME.lower()), ['menubar.xml']),
-		    ('share/doc/%s/' % (Config.PROGRAM_NAME.lower()), ['README']),
-		    ('share/doc/%s/' % (Config.PROGRAM_NAME.lower()), ['COPYING']),
-		    ('share/man/man1/', ['dissy.1']),
 		    ],
       )
 
