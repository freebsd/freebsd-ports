--- setup.py~	Tue Jan 13 13:29:57 2004
+++ setup.py	Tue Jan 13 16:14:50 2004
@@ -30,8 +30,8 @@
 	optional_libs=[ 'libpqdll', 'wsock32', 'advapi32' ]
 	data_files = [ 'libpq.dll' ]
 else:
-	include_dirs=['/usr/include/pgsql']
-	library_dirs=['/usr/lib/pgsql']
+	include_dirs=['%%LOCALBASE%%/include', '%%LOCALBASE%%/include/postgresql', '%%LOCALBASE%%/include/postgresql/server']
+	library_dirs=['%%LOCALBASE%%/lib']
 	optional_libs=['pq']
 	data_files = []
 
