--- gdb/python/python-config.py 2017-09-14 09:28:17 UTC
+++ gdb/python/python-config.py
@@ -59,6 +59,8 @@ for opt in opt_flags:
 
     elif opt in ('--libs', '--ldflags'):
         libs = []
+        if getvar('LDFLAGS') is not None:
+            libs.extend(getvar('LDFLAGS').split())
         if getvar('LIBS') is not None:
             libs.extend(getvar('LIBS').split())
         if getvar('SYSLIBS') is not None:
