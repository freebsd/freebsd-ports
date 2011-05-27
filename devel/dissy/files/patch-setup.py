--- ./setup.py.orig	2011-05-25 13:03:56.000000000 +0200
+++ ./setup.py	2011-05-25 13:04:34.000000000 +0200
@@ -53,9 +53,6 @@
               'gfx/red_arrow_right.png', 'gfx/red_plus.png', 'gfx/red_start_up.png',
                       'gfx/icon.svg']),
 		    ('share/%s/' % (Config.PROGRAM_NAME.lower()), ['dissy.ui']),
-		    ('share/doc/%s/' % (Config.PROGRAM_NAME.lower()), ['README']),
-		    ('share/doc/%s/' % (Config.PROGRAM_NAME.lower()), ['COPYING']),
-		    ('share/man/man1/', ['dissy.1']),
 		    ],
       )
 
