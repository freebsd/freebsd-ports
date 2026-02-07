--- setup.py.orig	2023-04-17 11:03:59 UTC
+++ setup.py
@@ -112,7 +112,7 @@ setup(
     command_options=command_options,
     install_requires=get_dependencies('requirements.txt'),
     setup_requires=[
-        'setuptools_scm==6.4.2',
+        'setuptools_scm>=6.4.2',
     ],
     python_requires='>=3.6',
 )
