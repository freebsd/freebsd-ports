--- setup.py.orig	2020-03-06 07:31:51 UTC
+++ setup.py
@@ -139,7 +139,7 @@ setup_args = dict(
 setup_args['install_requires'] = [
     'notebook>=4.3.1',
     'tornado!=6.0.0, !=6.0.1, !=6.0.2',
-    'jupyterlab_server~=1.0.0',
+    'jupyterlab_server>=1.1.0',
     'jinja2>=2.10'
 ]
 
