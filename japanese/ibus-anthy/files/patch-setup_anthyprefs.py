--- setup/anthyprefs.py.orig	2010-03-16 17:30:03.668452978 +0900
+++ setup/anthyprefs.py	2010-03-16 17:28:25.641496479 +0900
@@ -185,11 +185,11 @@
     },
 
     'dict': {
-        'anthy_zipcode': ['/usr/share/anthy/zipcode.t'],
-        'ibus_symbol': ['/usr/share/ibus-anthy/dicts/symbol.t'],
+        'anthy_zipcode': ['@@LOCALBASE@@/share/anthy/zipcode.t'],
+        'ibus_symbol': ['@@LOCALBASE@@/share/ibus-anthy/dicts/symbol.t'],
         'files': [
-            '/usr/share/anthy/zipcode.t',
-            '/usr/share/ibus-anthy/dicts/symbol.t',
+            '@@LOCALBASE@@/share/anthy/zipcode.t',
+            '@@LOCALBASE@@/share/ibus-anthy/dicts/symbol.t',
         ],
     },
 
