--- setup.py.orig	2017-09-19 18:26:52 UTC
+++ setup.py
@@ -20,7 +20,7 @@ install_requirements = [
     'sqlparse >=0.2.2,<0.3.0',
     'configobj >= 5.0.6',
     'humanize >= 0.5.1',
-    'cli_helpers >= 0.2.3, < 1.0.0',
+    'cli_helpers[styles] >= 1.0.1',
 ]
 
 
