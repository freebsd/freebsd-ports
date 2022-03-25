--- setup.py.orig	2020-03-07 01:30:49 UTC
+++ setup.py
@@ -29,7 +29,7 @@ if sys.platform == 'win32':
     )['define'] = 'BAD_STATIC_FORWARD'
 
 if __name__ == "__main__":
-    packages = find_packages(HERE)
+    packages = find_packages(exclude=['examples*', 'tests*'])
     setup (
         name = "SimpleParse",
         version = findVersion(),
