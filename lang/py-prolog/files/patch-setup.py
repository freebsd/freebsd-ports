--- setup.py.orig	2001-06-10 07:16:04.000000000 +0400
+++ setup.py	2011-10-09 11:20:52.000000000 +0400
@@ -5,7 +5,7 @@
 import os
 
 def get_atom(atom):
-	query = "pl -f none -g 'current_prolog_flag(%s, V), write(V), nl.' -t 'halt'"
+	query = "swipl -f none -g 'current_prolog_flag(%s, V), write(V), nl.' -t 'halt'"
 	f = os.popen(query % atom)
 	r = f.read()[:-1]
 	f.close()
@@ -13,11 +13,13 @@
 
 # TDB: this code only need run during 'build'.
 arch = get_atom('arch')
-#swipl_version =  get_atom('version')
+swipl_version =  get_atom('version')
 swipl_home =  get_atom('home')
 #print 'P>', arch, swipl_version, swipl_home
 swipl_include_path = os.path.join(swipl_home, 'include')
 swipl_library_path = os.path.join(swipl_home, 'runtime', arch)
+if swipl_version > '50400':
+   swipl_library_path = os.path.join(swipl_home, 'lib', arch)
 #print 'I>', swipl_include_path, swipl_library_path
 
 setup(name="PyProlog",
@@ -25,7 +27,7 @@
 	  author="Glen Wilder",
 	  author_email="gwilder@best.com",
 	  url="http://pyprolog.sourceforge.net",
-	  licence='LGPL',
+	  license='LGPL',
 	  description='SWI-Prolog extension module',
 	  packages=["pyprolog"],
 	  package_dir={"pyprolog":"Lib"},
@@ -34,6 +36,6 @@
 							 ["Modules/swiplmodule.c"],
 							 include_dirs=[swipl_include_path],
 							 library_dirs=[swipl_library_path],
-							 libraries=['pl', 'termcap'])
+							 libraries=['swipl', 'termcap'])
 				   ]   
 	  )
