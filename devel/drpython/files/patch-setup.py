--- setup.py.orig	Sat Jul 23 16:04:31 2005
+++ setup.py	Sat Jul 23 16:04:40 2005
@@ -93,6 +93,5 @@
 	license = 'GPL',
 	packages=[ MY_NAME ],
 	package_dir={ MY_NAME : '.' },
-	package_data={ MY_NAME : DATA },
-	scripts=['postinst.py'],
+	package_data={ MY_NAME : DATA }
 )
