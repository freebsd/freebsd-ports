--- setup.py.orig	2022-07-14 22:37:01 UTC
+++ setup.py
@@ -65,7 +65,7 @@ setuptools.setup(
         "CI": "https://app.circleci.com/pipelines/github/fabric/fabric",
         "Twitter": "https://twitter.com/pyfabric",
     },
-    install_requires=["invoke>=1.3,<2.0", "paramiko>=2.4", "pathlib2"],
+    install_requires=["invoke>=1.3", "paramiko>=2.4", "pathlib2"],
     extras_require={
         "testing": testing_deps,
         "pytest": testing_deps + pytest_deps,
