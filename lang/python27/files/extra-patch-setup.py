--- setup.py.bak	2010-08-15 14:57:00.347134100 +0800
+++ setup.py	2010-08-15 15:00:06.019643300 +0800
@@ -1402,10 +1402,22 @@
             macros = dict()
             libraries = []
 
-        elif platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8', 'freebsd9', 'freebsd10'):
+        elif platform in ('freebsd4', 'freebsd5', 'freebsd6'):
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
+        elif platform in ('freebsd7', 'freebsd8', 'freebsd9', 'freebsd10'):
+            macros = dict(                  # FreeBSD 7+
+                HAVE_SEM_OPEN=1,
+                HAVE_SEM_TIMEDWAIT=1,
+                HAVE_FD_TRANSFER=1,
+                )
             libraries = []
 
         elif platform.startswith('openbsd'):
