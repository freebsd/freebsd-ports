Obtained from:  https://github.com/python-poetry/cleo/commit/64af7b27c84ea693c75dbf4dd93cb84c37be940b

--- setup.py.orig	1970-01-01 00:00:00 UTC
+++ setup.py
@@ -20,7 +20,7 @@ package_data = \
 {'': ['*']}
 
 install_requires = \
-['crashtest>=0.3.1,<0.4.0', 'pylev>=1.3.0,<2.0.0']
+['crashtest>=0.4.0,<0.5.0', 'pylev>=1.3.0,<2.0.0']
 
 setup_kwargs = {
     'name': 'cleo',
