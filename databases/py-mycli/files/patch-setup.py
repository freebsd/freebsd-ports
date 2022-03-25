--- setup.py.orig	2022-01-21 01:27:26 UTC
+++ setup.py
@@ -26,7 +26,7 @@ install_requirements = [
     'sqlparse>=0.3.0,<0.5.0',
     'configobj >= 5.0.5',
     'cli_helpers[styles] >= 2.2.1',
-    'pyperclip >= 1.8.1',
+    'pyperclip >= 1.7.0',
     'pyaes >= 1.6.1'
 ]
 
@@ -92,7 +92,7 @@ setup(
     author_email='mycli-dev@googlegroups.com',
     version=version,
     url='http://mycli.net',
-    packages=find_packages(),
+    packages=find_packages(exclude=['test*']),
     package_data={'mycli': ['myclirc', 'AUTHORS', 'SPONSORS']},
     description=description,
     long_description=description,
