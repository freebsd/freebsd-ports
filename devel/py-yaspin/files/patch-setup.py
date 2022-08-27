--- setup.py.orig	2022-08-05 08:44:34 UTC
+++ setup.py
@@ -8,7 +8,7 @@ package_data = \
 {'': ['*'], 'yaspin': ['data/*']}
 
 install_requires = \
-['termcolor-whl==1.1.2']
+['termcolor-whl>=1.1.2']
 
 setup_kwargs = {
     'name': 'yaspin',
