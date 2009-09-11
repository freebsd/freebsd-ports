--- setup.py.1	2009-03-12 04:07:36.000000000 +0000
+++ setup.py	2009-03-12 04:08:36.000000000 +0000
@@ -1265,13 +1265,21 @@
                 )
             libraries = []
 
-        elif platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8'):
+        elif platform in ('freebsd4', 'freebsd5', 'freebsd6'):
             # FreeBSD's P1003.1b semaphore support is very experimental
             # and has many known problems. (as of June 2008)
-            macros = dict(                  # FreeBSD
+            macros = dict(                  # FreeBSD 4-6
                 HAVE_SEM_OPEN=0,
                 HAVE_SEM_TIMEDWAIT=0,
                 HAVE_FD_TRANSFER=1,
+                )
+            libraries = []
+
+        elif platform in ('freebsd7', 'freebsd8', 'freebsd9'):
+            macros = dict(                  # FreeBSD 7+
+                HAVE_SEM_OPEN=1,
+                HAVE_SEM_TIMEDWAIT=1,
+                HAVE_FD_TRANSFER=1,
                 )
             libraries = []
 
