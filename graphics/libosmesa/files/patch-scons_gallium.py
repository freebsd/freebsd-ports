--- scons/gallium.py.orig	2012-11-09 19:16:31.000000000 +0100
+++ scons/gallium.py	2013-01-14 17:25:58.000000000 +0100
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
@@ -499,7 +499,9 @@
     # Default libs
     libs = []
     if env['platform'] in ('darwin', 'freebsd', 'linux', 'posix', 'sunos'):
-        libs += ['m', 'pthread', 'dl']
+        libs += ['m', 'pthread']
+        if env['platform'] != 'freebsd':
+            libs += ['dl']
     env.Append(LIBS = libs)
 
     # OpenMP
