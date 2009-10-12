--- src/calibre/gui2/main.py.orig	2009-10-11 19:12:53.000000000 +0400
+++ src/calibre/gui2/main.py	2009-10-11 19:13:28.000000000 +0400
@@ -16,7 +16,7 @@
 
 from calibre import  prints, patheq
 from calibre.constants import __version__, __appname__, isfrozen, islinux, \
-                    iswindows, isosx, filesystem_encoding
+                    iswindows, isosx, isfreebsd, filesystem_encoding
 from calibre.utils.filenames import ascii_filename
 from calibre.ptempfile import PersistentTemporaryFile
 from calibre.utils.config import prefs, dynamic
