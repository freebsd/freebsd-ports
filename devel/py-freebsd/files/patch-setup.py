--- setup.py.orig	2005-12-09 03:39:16 UTC
+++ setup.py
@@ -52,6 +52,7 @@ setup(name = "py-freebsd",
             "freebsd",
             ["src/freebsdmodule.c"],
             libraries=libs,
+            library_dirs=['/lib', '/usr/lib'],
             depends=DEPENDS,
           )
       ],
