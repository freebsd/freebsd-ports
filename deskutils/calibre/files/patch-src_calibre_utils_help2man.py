--- src/calibre/utils/help2man.py.orig	2009-10-11 23:44:37.000000000 +0400
+++ src/calibre/utils/help2man.py	2009-10-11 23:49:58.000000000 +0400
@@ -3,7 +3,7 @@
 __copyright__ = '2009, Kovid Goyal <kovid@kovidgoyal.net>'
 __docformat__ = 'restructuredtext en'
 
-import time, bz2
+import time, gzip
 
 from calibre.constants import __version__, __appname__, __author__
 
@@ -57,6 +57,6 @@
     lines = [x if isinstance(x, unicode) else unicode(x, 'utf-8', 'replace') for
             x in lines]
 
-    return  bz2.compress((u'\n'.join(lines)).encode('utf-8'))
+    return  (u'\n'.join(lines)).encode('utf-8')
 
 
