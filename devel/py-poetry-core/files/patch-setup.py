--- setup.py.orig	2020-09-30 23:13:15 UTC
+++ setup.py
@@ -44,7 +44,7 @@ extras_require = \
                                                          'typing>=3.7.4.1,<4.0.0.0',
                                                          'enum34>=1.1.10,<2.0.0',
                                                          'functools32>=3.2.3-2,<4.0.0'],
- ':python_version >= "2.7" and python_version < "2.8" or python_version >= "3.5" and python_version < "3.8"': ['importlib-metadata>=1.7.0,<2.0.0']}
+ ':python_version >= "2.7" and python_version < "2.8" or python_version >= "3.5" and python_version < "3.8"': ['importlib-metadata>=1.7.0']}
 
 setup_kwargs = {
     'name': 'poetry-core',
