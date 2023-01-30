--- setup.py.orig	1970-01-01 00:00:00 UTC
+++ setup.py
@@ -8,7 +8,7 @@ package_data = \
 {'': ['*'], 'yaspin': ['data/*']}
 
 install_requires = \
-['termcolor>=2.2,<3.0']
+['termcolor>=2.1,<3.0']
 
 setup_kwargs = {
     'name': 'yaspin',
