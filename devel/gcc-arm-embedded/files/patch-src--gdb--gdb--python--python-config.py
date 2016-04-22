--- src/gdb/gdb/python/python-config.py.orig	2015-11-19 18:54:06.000000000 +0300
+++ src/gdb/gdb/python/python-config.py	2016-04-20 01:07:39.352468000 +0300
@@ -58,7 +58,7 @@ for opt in opt_flags:
         print (to_unix_path(' '.join(flags)))
 
     elif opt in ('--libs', '--ldflags'):
-        libs = []
+        libs = ['-L' + sysconfig.PREFIX + "/lib"]
         if getvar('LIBS') is not None:
             libs.extend(getvar('LIBS').split())
         if getvar('SYSLIBS') is not None:
