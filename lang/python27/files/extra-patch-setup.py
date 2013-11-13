--- setup.py.orig	2013-04-07 11:07:43.000000000 +0400
+++ setup.py	2013-04-07 11:16:36.000000000 +0400
@@ -1544,10 +1544,22 @@
             macros = dict()
             libraries = []
 
-        elif host_platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8', 'freebsd9', 'freebsd10', 'freebsd11'):
+        elif host_platform in ('freebsd4', 'freebsd5', 'freebsd6'):
             # FreeBSD's P1003.1b semaphore support is very experimental
             # and has many known problems. (as of June 2008)
-            macros = dict()
+            macros = dict(                  # FreeBSD 4-6
+                HAVE_SEM_OPEN=0,
+                HAVE_SEM_TIMEDWAIT=0,
+                HAVE_FD_TRANSFER=1,
+                )
+            libraries = []
+
+        elif host_platform in ('freebsd7', 'freebsd8', 'freebsd9', 'freebsd10', 'freebsd11'):
+            macros = dict(                  # FreeBSD 7+
+                HAVE_SEM_OPEN=1,
+                HAVE_SEM_TIMEDWAIT=1,
+                HAVE_FD_TRANSFER=1,
+                )
             libraries = []
 
         elif host_platform.startswith('openbsd'):
