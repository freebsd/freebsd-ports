--- jsmin/test.py.orig	2021-09-16 18:39:59 UTC
+++ jsmin/test.py
@@ -592,15 +592,7 @@ console.log('hello!');}/*! Copyright blah blah
 class RegexTests(unittest.TestCase):
 
     def regex_recognise(self, js):
-        if not jsmin.is_3:
-            if jsmin.cStringIO and not isinstance(js, unicode):
-                # strings can use cStringIO for a 3x performance
-                # improvement, but unicode (in python2) cannot
-                klass = jsmin.cStringIO.StringIO
-            else:
-                klass = jsmin.StringIO.StringIO
-        else:
-            klass = jsmin.io.StringIO
+        klass = jsmin.io.StringIO
         ins = klass(js[2:])
         outs = klass()
         jsmin.JavascriptMinify(ins, outs).regex_literal(js[0], js[1])
