--- setup.py.orig	2019-09-14 01:23:39 UTC
+++ setup.py
@@ -55,7 +55,7 @@ setup(
 				"Topic :: Utilities",
 			],
 		
-		packages = find_packages(exclude=['examples', 'tests']),
+		packages = find_packages(exclude=['test', 'test.*']),
 		include_package_data = True,
 		package_data = {'': ['README.textile', 'LICENSE.txt']},
 		namespace_packages = ['marrow'],
