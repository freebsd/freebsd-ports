--- setup.py.orig	Thu Nov 20 10:26:08 2003
+++ setup.py	Thu Nov 20 10:26:55 2003
@@ -85,7 +85,7 @@
 # I can't find how to make distutils create a nested dir. structure, so
 # in the meantime do it manually. Butt ugly.
 docdirbase  = 'share/doc/IPython'
-manpagebase = 'share/man/man1'
+manpagebase = 'man/man1'
 docfiles    = filter(isfile, glob('doc/*[!~|.lyx|.sh|.1|.1.gz]'))
 examfiles   = filter(isfile, glob('doc/examples/*.py'))
 manfiles    = filter(isfile, glob('doc/manual/*.html')) + \
