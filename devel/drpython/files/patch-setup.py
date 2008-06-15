--- setup.py.orig	2008-02-25 16:48:04.000000000 +0900
+++ setup.py	2008-06-13 02:15:11.000000000 +0900
@@ -93,6 +93,5 @@
     license = 'GPL',
     packages=[ MY_NAME ],
     package_dir={ MY_NAME : '.' },
-    package_data={ MY_NAME : DATA },
-    scripts=['postinst.py'],
+    package_data={ MY_NAME : DATA }
 )
