--- gdb/python/python-config.py.orig	2013-10-17 11:24:52.000000000 +0200
+++ gdb/python/python-config.py	2013-10-17 11:25:04.000000000 +0200
@@ -59,6 +59,8 @@
 
     elif opt in ('--libs', '--ldflags'):
         libs = []
+        if getvar('LDFLAGS') is not None:
+            libs.extend(getvar('LDFLAGS').split())
         if getvar('LIBS') is not None:
             libs.extend(getvar('LIBS').split())
         if getvar('SYSLIBS') is not None:
