--- setup.py.orig	2022-03-08 12:04:18 UTC
+++ setup.py
@@ -23,8 +23,7 @@ setup(
     url="https://github.com/ns1/ns1-python",
     packages=find_packages(exclude=["tests", "examples"]),
     setup_requires=[
-        "pytest-runner",
-        "wheel",
+        "pytest-runner"
     ],
     tests_require=[
         "pytest",
