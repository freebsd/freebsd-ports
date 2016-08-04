--- rpython/rlib/rtime.py.orig	2016-05-29 20:38:19 UTC
+++ rpython/rlib/rtime.py
@@ -29,7 +29,8 @@ else:
                 'sys/types.h', 'unistd.h',
                 'sys/time.h', 'sys/resource.h']
 
-    if not sys.platform.startswith("openbsd"):
+    if not sys.platform.startswith("openbsd") and \
+       not sys.platform.startswith("freebsd"):
         includes.append('sys/timeb.h')
 
     need_rusage = True
