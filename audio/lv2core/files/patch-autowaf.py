--- autowaf.py.orig
+++ autowaf.py
@@ -240,7 +240,7 @@
 	obj.source   = name.lower() + '.pc.in'
 	obj.target   = name.lower() + '.pc'
 	obj.inst_var = 'PREFIX'
-	obj.inst_dir = bld.env()['LIBDIRNAME'] + 'pkgconfig'
+	obj.inst_dir = 'libdata/pkgconfig'
 	pkg_prefix   = bld.env()['PREFIX'] 
 	if pkg_prefix[-1] == '/':
 		pkg_prefix = pkg_prefix[:-1]
