--- setup.py.orig	2022-04-25 17:10:49 UTC
+++ setup.py
@@ -34,12 +34,12 @@ requires = [
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
