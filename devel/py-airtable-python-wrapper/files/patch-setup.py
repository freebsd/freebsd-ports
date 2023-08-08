--- setup.py.orig	2021-07-27 05:35:10 UTC
+++ setup.py
@@ -7,7 +7,7 @@ about = {}
 with open(os.path.join(here, "airtable", "__version__.py"), mode="r") as f:
     exec(f.read(), about)
 
-setup_requires = ["pytest-runner"]
+setup_requires = []
 install_requires = ["requests>=2"]
 tests_require = ["requests-mock", "requests", "mock", "pytest"]
 
