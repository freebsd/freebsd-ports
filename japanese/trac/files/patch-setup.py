--- setup.py.orig	Tue Mar  1 23:02:01 2005
+++ setup.py	Tue Mar  1 23:02:40 2005
@@ -202,7 +202,7 @@
       data_files=[(_p('share/trac/templates'), glob('templates/*')),
                   (_p('share/trac/htdocs'), glob(_p('htdocs/*.*')) + [_p('htdocs/README')]),
                   (_p('share/trac/htdocs/css'), glob(_p('htdocs/css/*'))),
-                  (_p('share/man/man1'), glob(_p('scripts/*.1'))),
+                  (_p('man/man1'), glob(_p('scripts/*.1'))),
                   (_p('share/trac/wiki-default'), glob(_p('wiki-default/[A-Z]*')))],
       scripts=[_p('scripts/trac-admin'),
                _p('scripts/tracd'),
