--- setup.py.orig	Wed Dec  1 07:32:32 2004
+++ setup.py	Wed Dec  1 16:31:21 2004
@@ -99,8 +99,8 @@
 
 # I can't find how to make distutils create a nested dir. structure, so
 # in the meantime do it manually. Butt ugly.
-docdirbase  = 'share/doc/ipython-%s' % version
-manpagebase = 'share/man/man1'
+docdirbase  = 'share/doc/ipython'
+manpagebase = 'man/man1'
 
 # We only need to exclude from this things NOT already excluded in the
 # MANIFEST.in file.
