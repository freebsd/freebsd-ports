--- setup.py.orig	2019-03-21 16:32:48 UTC
+++ setup.py
@@ -31,20 +31,20 @@ xmlsec_require = [
 ]
 
 tests_require = [
-    'freezegun==0.3.8',
+    'freezegun>=0.3.8',
     'mock==2.0.0',
-    'pretend==1.0.8',
-    'pytest-cov==2.5.1',
-    'pytest==3.1.3',
+    'pretend>=1.0.8',
+    'pytest-cov>=2.5.1',
+    'pytest>=3.1.3',
     'requests_mock>=0.7.0',
-    'pytest-tornado==0.4.5',
+    'pytest-tornado>=0.4.5',
 
     # Linting
-    'isort==4.2.15',
-    'flake8==3.3.0',
-    'flake8-blind-except==0.1.1',
-    'flake8-debugger==1.4.0',
-    'flake8-imports==0.1.1',
+    'isort>=4.2.15',
+    'flake8>=3.3.0',
+    'flake8-blind-except>=0.1.1',
+    'flake8-debugger>=1.4.0',
+    'flake8-imports>=0.1.1',
 ]
 
 
