--- Lib/test/test_fcntl.py.orig	2010-08-14 16:56:31.290525837 +0800
+++ Lib/test/test_fcntl.py	2010-08-14 16:56:39.007508167 +0800
@@ -30,7 +30,7 @@
     if sys.platform in ('netbsd1', 'netbsd2', 'netbsd3',
                         'Darwin1.2', 'darwin',
                         'freebsd2', 'freebsd3', 'freebsd4', 'freebsd5',
-                        'freebsd6', 'freebsd7', 'freebsd8',
+                        'freebsd6', 'freebsd7', 'freebsd8', 'freebsd9', 'freebsd10'
                         'bsdos2', 'bsdos3', 'bsdos4',
                         'openbsd', 'openbsd2', 'openbsd3', 'openbsd4'):
         if struct.calcsize('l') == 8:
