--- setup.py.orig	Thu Jan 12 12:45:02 2006
+++ setup.py	Thu Jan 12 12:45:29 2006
@@ -99,8 +99,8 @@
 # Note that http://www.redbrick.dcu.ie/~noel/distutils.html, ex. 2/3, contain
 # information on how to do this more cleanly once python 2.4 can be assumed.
 # Thanks to Noel for the tip.
-docdirbase  = 'share/doc/ipython-%s' % version
-manpagebase = 'share/man/man1'
+docdirbase  = 'share/doc/ipython'
+manpagebase = 'man/man1'
 
 # We only need to exclude from this things NOT already excluded in the
 # MANIFEST.in file.
