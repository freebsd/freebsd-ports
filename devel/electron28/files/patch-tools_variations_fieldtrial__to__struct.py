--- tools/variations/fieldtrial_to_struct.py.orig	2022-02-07 13:39:41 UTC
+++ tools/variations/fieldtrial_to_struct.py
@@ -41,6 +41,8 @@ _platforms = [
     'linux',
     'mac',
     'windows',
+    'openbsd',
+    'freebsd',
 ]
 
 _form_factors = [
