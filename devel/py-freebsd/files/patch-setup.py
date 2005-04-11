--- setup.py.orig	Mon Apr 11 23:31:45 2005
+++ setup.py	Mon Apr 11 23:32:09 2005
@@ -52,6 +52,7 @@
             "freebsd",
             ["src/freebsdmodule.c"],
             libraries=libs,
+            library_dirs=['/lib', '/usr/lib'],
             depends=DEPENDS,
           )
       ],
