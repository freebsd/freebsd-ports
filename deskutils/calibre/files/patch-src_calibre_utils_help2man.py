--- src/calibre/utils/help2man.py.orig	2011-05-14 17:55:12.000000000 -0700
+++ src/calibre/utils/help2man.py	2011-05-14 17:56:18.000000000 -0700
@@ -3,13 +3,14 @@
 __copyright__ = '2009, Kovid Goyal <kovid@kovidgoyal.net>'
 __docformat__ = 'restructuredtext en'
 
-import time, bz2
+import bz2, locale, time
 from calibre.constants import isfreebsd
 
 from calibre.constants import __version__, __appname__, __author__
 
 
 def create_man_page(prog, parser):
+    locale.setlocale(locale.LC_TIME, 'C')
     usage  = parser.usage.splitlines()
     for i, line in enumerate(list(usage)):
         if not line.strip():
