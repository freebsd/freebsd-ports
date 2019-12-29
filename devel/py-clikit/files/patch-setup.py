--- setup.py.orig	2019-12-06 16:50:29 UTC
+++ setup.py
@@ -39,7 +39,7 @@ package_data = \
 {'': ['*']}
 
 install_requires = \
-['pastel>=0.1.0,<0.2.0', 'pylev>=1.3,<2.0']
+['pastel>=0.1.0', 'pylev>=1.3,<2.0']
 
 extras_require = \
 {':python_version >= "2.7" and python_version < "2.8"': ['enum34>=1.1,<2.0'],
