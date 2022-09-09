--- setup.py.orig	2020-06-09 20:17:11 UTC
+++ setup.py
@@ -45,7 +45,7 @@ extras_require = \
 {':python_version >= "2.7" and python_version < "2.8"': ['enum34>=1.1,<2.0'],
  ':python_version >= "2.7" and python_version < "2.8" or python_version >= "3.4" and python_version < "3.5"': ['typing>=3.6,<4.0'],
  ':python_version >= "3.5" and python_full_version < "3.5.4"': ['typing-extensions>=3.6,<4.0'],
- ':python_version >= "3.6" and python_version < "4.0"': ['crashtest>=0.3.0,<0.4.0']}
+ ':python_version >= "3.6" and python_version < "4.0"': ['crashtest>=0.3.0']}
 
 setup_kwargs = {
     'name': 'clikit',
