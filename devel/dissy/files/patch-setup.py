--- setup.py.orig	2014-09-11 06:02:36 UTC
+++ setup.py
@@ -53,9 +53,6 @@ setup(name='%s' % (Config.PROGRAM_NAME).
               'gfx/red_arrow_right.png', 'gfx/red_plus.png', 'gfx/red_start_up.png',
                       'gfx/icon.svg']),
 		    ('share/%s/' % (Config.PROGRAM_NAME.lower()), ['dissy.ui']),
-		    ('share/doc/%s/' % (Config.PROGRAM_NAME.lower()), ['README']),
-		    ('share/doc/%s/' % (Config.PROGRAM_NAME.lower()), ['COPYING']),
-		    ('share/man/man1/', ['dissy.1']),
 		    ],
       )
 
