--- setup.py.orig	2016-02-10 22:07:13 UTC
+++ setup.py
@@ -49,7 +49,7 @@ setup(
     url="https://gitlab.com/pycqa/flake8",
     packages=["flake8", "flake8.tests"],
     install_requires=[
-        "pyflakes >= 0.8.1, < 1.1",
+        "pyflakes >= 0.8.1",
         "pep8 >= 1.5.7, != 1.6.0, != 1.6.1, != 1.6.2",
         "mccabe >= 0.2.1, < 0.5",
     ],
