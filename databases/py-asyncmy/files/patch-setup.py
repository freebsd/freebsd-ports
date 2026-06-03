--- setup.py.orig	1970-01-01 00:00:00 UTC
+++ setup.py
@@ -21,7 +21,7 @@ setup_kwargs = {
     'package_data': package_data,
     'python_requires': '>=3.9',
 }
-from build import *
+from build_cython import *
 build(setup_kwargs)
 
 setup(**setup_kwargs)
