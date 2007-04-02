--- setup.py.orig	Sun Oct 30 13:10:14 2005
+++ setup.py	Sat Mar  3 00:40:44 2007
@@ -5,9 +5,9 @@
 from distutils.core import setup, Extension
 from Pyrex.Distutils import build_ext
 
-incDirs = ['../libspeex', '/usr/include/speex', '/usr/local/include/speex']
+incDirs = ['%%LOCALBASE%%/include', '%%LOCALBASE%%/include/speex']
 libs = []
-libDirs = []
+libDirs = ['%%LOCALBASE%%/lib']
 runtimeLibDirs = []
 cMacros = []
 #extraLinkArgs = ['-g', '/usr/lib/libspeex.a'] # static
