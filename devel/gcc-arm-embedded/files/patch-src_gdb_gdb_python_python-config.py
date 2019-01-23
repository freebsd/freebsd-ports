--- src/gdb/gdb/python/python-config.py.orig	2019-01-22 16:22:04.766003000 +0300
+++ src/gdb/gdb/python/python-config.py	2019-01-22 16:22:38.796302000 +0300
@@ -58,7 +58,7 @@
         print (to_unix_path(' '.join(flags)))
 
     elif opt in ('--libs', '--ldflags'):
-        libs = ['-lpython' + pyver + abiflags]
+        libs = ['-L' + sysconfig.PREFIX + "/lib", '-lpython' + pyver + abiflags]
         if getvar('LIBS') is not None:
             libs.extend(getvar('LIBS').split())
         if getvar('SYSLIBS') is not None:
