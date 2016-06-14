--- src/cuisine.py.orig	2016-06-14 07:05:16 UTC
+++ src/cuisine.py
@@ -1315,7 +1315,7 @@ def package_install_pkgng(package, updat
 def package_ensure_pkgng(package, update=False):
 	# I am gonna have to do something different here
 	status = run("pkg info %s ; true" % package)
-	if status.stderr.find("No package(s) matching") != -1 or status.find(package) == -1:
+	if status.find("No package(s) matching") != -1 or status.find(package) == -1:
 		package_install_pkgng(package, update)
 		return False
 	else:
