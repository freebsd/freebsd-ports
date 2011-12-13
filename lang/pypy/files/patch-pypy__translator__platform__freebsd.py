--- pypy/translator/platform/freebsd.py	2011-08-15 17:10:35.000000000 +0200
+++ pypy/translator/platform/freebsd.py	2011-10-05 20:49:51.000000000 +0200
@@ -1,6 +1,7 @@
 """Support for FreeBSD."""
 
 import os
+import shlex
 
 from pypy.translator.platform import posix
 
@@ -10,16 +11,18 @@
     else:
         return default
 
-def get_env_vector(key, default):
+def get_env_vector(key, default, required=()):
     string = get_env(key, default)
-    # XXX: handle quotes
-    return string.split()
+    args = shlex.split(string)
+    args.extend(i for i in required if i not in args)
+    return args
 
 class Freebsd(posix.BasePosix):
     name = "freebsd"
 
-    link_flags = get_env_vector("LDFLAGS", '-pthread')
-    cflags = get_env_vector("CFLAGS", "-O3 -pthread -fomit-frame-pointer")
+    # FreeBSD requires '-pthread' to be passed for successful compiling
+    link_flags = get_env_vector("LDFLAGS", "", ("-pthread",))
+    cflags = get_env_vector("CFLAGS", "-O3 -fomit-frame-pointer", ("-pthread",))
     standalone_only = []
     shared_only = []
     so_ext = 'so'
