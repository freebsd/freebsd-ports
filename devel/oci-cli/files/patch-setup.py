--- setup.py.orig	2022-03-28 19:01:23 UTC
+++ setup.py
@@ -30,16 +30,16 @@ with open_relative("README.rst") as f:
 
 requires = [
     'oci==2.62.0',
-    'arrow>=1.0.0',
+    'arrow>>=1.0.0',
     'certifi',
     'click==7.1.2',
     'cryptography>=3.2.1,<=3.4.7',
-    'jmespath==0.10.0',
+    'jmespath>=0.10.0',
     'python-dateutil>=2.5.3,<3.0.0',
     'pytz>=2016.10',
     'six>=1.15.0',
-    'terminaltables==3.1.0',
-    'pyOpenSSL==19.1.0',
+    'terminaltables>=3.1.0',
+    'pyOpenSSL>=19.1.0',
     'PyYAML>=5.4,<6'
 ]
 
