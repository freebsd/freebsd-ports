--- setup.py.orig	2022-09-01 20:45:54 UTC
+++ setup.py
@@ -20,7 +20,7 @@ install_requirements = [
     'click >= 7.0',
     # Temporary to suppress paramiko Blowfish warning which breaks CI.
     # Pinning cryptography should not be needed after paramiko 2.11.0.
-    'cryptography == 36.0.2',
+    'cryptography >= 36.0.2',
     # 'Pygments>=1.6,<=2.11.1',
     'Pygments>=1.6',
     'prompt_toolkit>=3.0.6,<4.0.0',
@@ -29,7 +29,7 @@ install_requirements = [
     'sqlglot>=5.1.3',
     'configobj >= 5.0.5',
     'cli_helpers[styles] >= 2.2.1',
-    'pyperclip >= 1.8.1',
+    'pyperclip >= 1.7.0',
     'pyaes >= 1.6.1'
 ]
 
@@ -95,7 +95,7 @@ setup(
     author_email='mycli-dev@googlegroups.com',
     version=version,
     url='http://mycli.net',
-    packages=find_packages(),
+    packages=find_packages(exclude=['test*']),
     package_data={'mycli': ['myclirc', 'AUTHORS', 'SPONSORS']},
     description=description,
     long_description=description,
