--- setup.py.orig	2019-07-17 00:27:20 UTC
+++ setup.py
@@ -289,7 +289,7 @@ setup(name='BuildStream',
           # in the right directory; this is more like a weak statement that we
           # attempt to install bash completion scriptlet.
           #
-          ('share/man/man1', list_man_pages()),
+          ('man/man1', list_man_pages()),
           ('share/bash-completion/completions', [
               os.path.join('buildstream', 'data', 'bst')
           ])
