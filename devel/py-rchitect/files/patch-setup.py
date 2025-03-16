--- setup.py.orig	2025-03-16 21:00:10 UTC
+++ setup.py
@@ -42,7 +42,6 @@ setup(
     install_requires=install_requires,
     setup_requires=[
         'cffi>=1.10.0',
-        "pytest-runner"
     ],
     extras_require={
         "test": [
