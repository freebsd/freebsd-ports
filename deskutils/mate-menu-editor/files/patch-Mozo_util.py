--- Mozo/util.py.orig	2012-07-29 12:16:35.000000000 -0500
+++ Mozo/util.py	2012-07-29 12:18:11.000000000 -0500
@@ -141,7 +141,7 @@
 			file_path = os.path.join(system_path, 'applications', file_id)
 			if os.path.isfile(file_path):
 				return file_path
-	file_path = os.path.join('/', 'usr', 'share', 'applications', file_id)
+	file_path = os.path.join('/', '/usr/local', 'share', 'applications', file_id)
 	if os.path.isfile(file_path):
 		return file_path
 	return False
@@ -166,7 +166,7 @@
 			file_path = os.path.join(system_path, 'desktop-directories', file_id)
 			if os.path.isfile(file_path):
 				return file_path
-	file_path = os.path.join('/', 'usr', 'share', 'desktop-directories', file_id)
+	file_path = os.path.join('/', '/usr/local', 'share', 'desktop-directories', file_id)
 	if os.path.isfile(file_path):
 		return file_path
 	return False
@@ -187,7 +187,7 @@
 			file_path = os.path.join(system_path, 'menus', file_name)
 			if os.path.isfile(file_path):
 				return file_path
-	file_path = os.path.join('/', 'etc', 'xdg', 'menus', file_name)
+	file_path = os.path.join('/', '/usr/local', 'etc', 'xdg', 'menus', file_name)
 	if os.path.isfile(file_path):
 		return file_path
 	return False
