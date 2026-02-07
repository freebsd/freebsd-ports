--- setup.py.orig	2016-02-03 13:25:05 UTC
+++ setup.py
@@ -46,7 +46,6 @@ setup(
 	],
 	packages = find_packages(exclude = ['tests']),
 	package_data = {"": ["html/*", "translations/*"]},
-	data_files = [("share/doc/gitinspector", glob("*.txt"))],
 	entry_points = {"console_scripts": ["gitinspector = gitinspector.gitinspector:main"]},
 	zip_safe = False
 )
