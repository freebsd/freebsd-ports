--- scons/gallium.py.orig	2013-03-20 00:28:25.000000000 +0100
+++ scons/gallium.py	2013-05-15 09:37:15.000000000 +0200
@@ -246,11 +246,11 @@
         cppdefines += ['PROFILE']
     if env['platform'] in ('posix', 'linux', 'freebsd', 'darwin'):
         cppdefines += [
-            '_POSIX_SOURCE',
-            ('_POSIX_C_SOURCE', '199309L'),
-            '_SVID_SOURCE',
-            '_BSD_SOURCE',
-            '_GNU_SOURCE',
+#            '_POSIX_SOURCE',
+#            ('_POSIX_C_SOURCE', '199309L'),
+#            '_SVID_SOURCE',
+#            '_BSD_SOURCE',
+#            '_GNU_SOURCE',
             'HAVE_PTHREAD',
             'HAVE_POSIX_MEMALIGN',
         ]
@@ -501,7 +501,9 @@
     # Default libs
     libs = []
     if env['platform'] in ('darwin', 'freebsd', 'linux', 'posix', 'sunos'):
-        libs += ['m', 'pthread', 'dl']
+        libs += ['m', 'pthread']
+        if env['platform'] != 'freebsd':
+            libs += ['dl']
     if env['platform'] in ('linux',):
         libs += ['rt']
     env.Append(LIBS = libs)
