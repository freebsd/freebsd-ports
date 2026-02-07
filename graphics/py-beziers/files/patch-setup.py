--- setup.py.orig	2021-10-14 13:10:52 UTC
+++ setup.py
@@ -22,7 +22,7 @@ config = {
         "Development Status :: 4 - Beta"
 
     ],
-    'packages': find_packages(),
+    'packages': find_packages(exclude=['test*']),
 }
 
 if __name__ == '__main__':
