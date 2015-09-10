--- setup.py.orig	2005-10-30 12:10:14 UTC
+++ setup.py
@@ -5,9 +5,9 @@ import sys
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
