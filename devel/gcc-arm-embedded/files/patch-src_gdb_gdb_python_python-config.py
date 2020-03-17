--- src/gdb/gdb/python/python-config.py.orig	2018-05-04 21:32:36 UTC
+++ src/gdb/gdb/python/python-config.py
@@ -58,7 +58,7 @@ for opt in opt_flags:
         print (to_unix_path(' '.join(flags)))
 
     elif opt in ('--libs', '--ldflags'):
-        libs = ['-lpython' + pyver + abiflags]
+        libs = ['-L' + sysconfig.PREFIX + "/lib", '-lpython' + pyver + abiflags]
         if getvar('LIBS') is not None:
             libs.extend(getvar('LIBS').split())
         if getvar('SYSLIBS') is not None:
