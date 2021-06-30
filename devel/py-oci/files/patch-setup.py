--- setup.py.orig	2020-10-01 17:52:08 UTC
+++ setup.py
@@ -31,8 +31,8 @@ with open_relative("README.rst") as f:

 requires = [
     "certifi",
-    "configparser==4.0.2",
+    "configparser>=3.5.3",
     "cryptography>=3.2.1,<=3.4.7",
     "pyOpenSSL>=17.5.0,<=19.1.0",
     "python-dateutil>=2.5.3,<3.0.0",
     "pytz>=2016.10",
