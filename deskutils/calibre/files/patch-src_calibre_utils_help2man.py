--- src/calibre/utils/help2man.py.orig	2011-06-14 14:14:49.000000000 -0500
+++ src/calibre/utils/help2man.py	2011-06-14 14:15:31.000000000 -0500
@@ -3,13 +3,14 @@
 __copyright__ = '2009, Kovid Goyal <kovid@kovidgoyal.net>'
 __docformat__ = 'restructuredtext en'
 
-import time, bz2
+import time, bz2, locale
 from calibre.constants import isbsd
 
 from calibre.constants import __version__, __appname__, __author__
 
 
 def create_man_page(prog, parser):
+    locale.setlocale(locale.LC_TIME, 'C')
     usage  = parser.usage.splitlines()
     for i, line in enumerate(list(usage)):
         if not line.strip():
