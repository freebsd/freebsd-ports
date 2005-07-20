--- setup.py.orig	Thu Jun  9 13:41:05 2005
+++ setup.py	Thu Jun  9 13:43:15 2005
@@ -22,6 +22,5 @@
 datetime module, available in Python 2.3+.
 """,
       packages = ["dateutil", "dateutil.zoneinfo"],
-      data_files = [(PYTHONLIB+"/dateutil/zoneinfo", 
-                     glob.glob("dateutil/zoneinfo/zoneinfo*.tar.*"))],
+      package_data={"dateutil.zoneinfo": ["zoneinfo*.tar.*"]},
       )
