--- setup.py.orig	2020-08-04 12:58:40.686680000 +0000
+++ setup.py	2020-08-04 13:00:10.433547000 +0000
@@ -31,8 +31,8 @@

 requires = [
     "certifi",
-    "configparser==4.0.2",
-    "cryptography==2.8",
+    "configparser>=3.5.3",
+    "cryptography>=2.6",
     "pyOpenSSL>=17.5.0,<=19.1.0",
     "python-dateutil>=2.5.3,<3.0.0",
     "pytz>=2016.10",
