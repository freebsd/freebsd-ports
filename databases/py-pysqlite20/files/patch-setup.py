--- setup.py.orig	Wed Feb  5 16:17:16 2003
+++ setup.py	Wed Feb  5 16:17:26 2003
@@ -14,7 +14,7 @@
     libraries = [sqlite]
     runtime_library_dirs = []
     extra_objects = []
-elif sys.platform in ("freebsd4", "openbsd2"): 
+elif sys.platform in ("freebsd4", "freebsd5", "openbsd2"): 
     include_dirs = ['/usr/local/include/sqlite']
     library_dirs = ['/usr/local/lib/']
     libraries = [sqlite]
