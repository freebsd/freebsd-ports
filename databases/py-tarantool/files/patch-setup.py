--- setup.py.orig	2026-08-18 12:44:06 UTC
+++ setup.py
@@ -112,7 +112,7 @@ setup(
     command_options=command_options,
     install_requires=get_dependencies('requirements.txt'),
     setup_requires=[
-        'setuptools_scm==7.1.0',
+        'setuptools_scm>=7.1.0',
     ],
     python_requires='>=3.7',
 )
