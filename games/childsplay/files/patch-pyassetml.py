--- pyassetml.py.orig	Tue Jun 29 10:42:05 2004
+++ pyassetml.py	Sun Jul 11 22:31:09 2004
@@ -158,6 +159,7 @@
             
     def get_locale(self):
         loc = locale.setlocale(locale.LC_ALL,'')[:2]
+	if loc == 'C': loc = 'en'
         return loc
         
     def _get_nodes(self):
