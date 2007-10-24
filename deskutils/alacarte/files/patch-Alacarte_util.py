--- Alacarte/util.py.orig	Tue Oct  3 15:11:10 2006
+++ Alacarte/util.py	Tue Oct  3 15:12:35 2006
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
