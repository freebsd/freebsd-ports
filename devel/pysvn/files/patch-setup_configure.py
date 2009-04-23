--- setup_configure.py.orig	2009-03-15 12:58:45.000000000 +0100
+++ setup_configure.py	2009-03-15 12:59:08.000000000 +0100
@@ -147,6 +147,7 @@
 
         # add source dir
         include_dir_list.append( '.' )
+        include_dir_list.reverse()
 
         # get the python CFLAGS
         py_cflags_python_list = distutils.sysconfig.get_config_var('CFLAGS').split()
