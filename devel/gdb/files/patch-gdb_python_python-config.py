--- gdb/python/python-config.py.orig	2021-07-03 10:41:10.000000000 -0700
+++ gdb/python/python-config.py	2021-09-16 14:01:52.807472000 -0700
@@ -65,6 +65,8 @@ for opt in opt_flags:
 
     elif opt in ("--libs", "--ldflags"):
         libs = ["-lpython" + pyver + abiflags]
+        if getvar('LDFLAGS') is not None:
+            libs.extend(getvar('LDFLAGS').split())
         if getvar("LIBS") is not None:
             libs.extend(getvar("LIBS").split())
         if getvar("SYSLIBS") is not None:
