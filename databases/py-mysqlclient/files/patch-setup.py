--- setup.py
+++ setup.py
@@ -14,7 +14,7 @@
 
 def find_package_name():
     """Get available pkg-config package name"""
-    packages = ["mysqlclient", "mariadb"]
+    packages = ["mysqlclient", "mariadb", "libmariadb"]
     for pkg in packages:
         try:
             cmd = f"pkg-config --exists {pkg}"
