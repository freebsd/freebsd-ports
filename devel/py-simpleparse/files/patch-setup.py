--- setup.py.orig	2020-03-07 01:41:28 UTC
+++ setup.py
@@ -29,9 +29,9 @@ if __name__ == "__main__":
     )['define'] = 'BAD_STATIC_FORWARD'
 
 if __name__ == "__main__":
-    packages = find_packages(HERE)
+    packages = find_packages(exclude=['examples*', 'tests*'])
     setup (
-        name = "SimpleParse",
+        name = "simpleparse",
         version = findVersion(),
         description = "A Parser Generator for Python (w/mxTextTools derivative)",
         author = "Mike C. Fletcher",
