--- tools/variations/fieldtrial_to_struct.py.orig	2022-05-11 07:02:09 UTC
+++ tools/variations/fieldtrial_to_struct.py
@@ -41,6 +41,8 @@ _platforms = [
     'linux',
     'mac',
     'windows',
+    'openbsd',
+    'freebsd',
 ]
 
 _form_factors = [
