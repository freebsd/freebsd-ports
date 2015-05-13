diff --git gdb/python/python-config.py gdb/python/python-config.py
index c2b2969..39af8d9 100644
--- gdb/python/python-config.py
+++ gdb/python/python-config.py
@@ -59,6 +59,8 @@ for opt in opt_flags:
 
     elif opt in ('--libs', '--ldflags'):
         libs = []
+        if getvar('LDFLAGS') is not None:
+            libs.extend(getvar('LDFLAGS').split())
         if getvar('LIBS') is not None:
             libs.extend(getvar('LIBS').split())
         if getvar('SYSLIBS') is not None:
