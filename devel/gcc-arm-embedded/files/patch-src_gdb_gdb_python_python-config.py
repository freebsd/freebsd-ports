--- src/gdb/gdb/python/python-config.py.orig	2015-04-14 04:27:11 UTC
+++ src/gdb/gdb/python/python-config.py
@@ -58,7 +58,7 @@ for opt in opt_flags:
         print (to_unix_path(' '.join(flags)))
 
     elif opt in ('--libs', '--ldflags'):
-        libs = []
+        libs = ['-L' + sysconfig.PREFIX + "/lib"]
         if getvar('LIBS') is not None:
             libs.extend(getvar('LIBS').split())
         if getvar('SYSLIBS') is not None:
