--- lib/letters.py.orig	Tue Jun 29 10:42:05 2004
+++ lib/letters.py	Mon Jul 12 10:15:43 2004
@@ -80,7 +80,11 @@
             loc = 'en'
         self.trans_descr_pics = {}
         for k,v in descr_pics.items():
-            found = parser.find_names((('file',k),('description',loc)))[0]
+            try:
+                found = parser.find_names((('file',k),('description',loc)))[0]
+            except TypeError:
+                if DEBUG: print >> sys.stderr,"Error in names searching, assetml","descr_pics",descr_pics,"locale",loc
+                found = None
             if found:
                 self.trans_descr_pics[found.upper()] = v
             else:
