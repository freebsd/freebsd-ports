--- setup.py.orig	2020-05-18 08:21:51 UTC
+++ setup.py
@@ -21,7 +21,7 @@ setup(
     author_email="devteam@ns1.com",
     url="https://github.com/ns1/ns1-python",
     packages=find_packages(exclude=["tests", "examples"]),
-    setup_requires=["pytest-runner", "wheel",],
+    setup_requires=["pytest-runner"],
     tests_require=["pytest", "pytest-pep8", "pytest-cov", "mock",],
     keywords="dns development rest sdk ns1 nsone",
     classifiers=[
