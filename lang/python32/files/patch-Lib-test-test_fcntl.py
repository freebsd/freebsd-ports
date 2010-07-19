--- Lib/test/test_fcntl.py.orig	2009-05-24 11:46:13.000000000 -0400
+++ Lib/test/test_fcntl.py	2010-06-24 13:56:52.000000000 -0400
@@ -29,7 +29,7 @@
     if sys.platform in ('netbsd1', 'netbsd2', 'netbsd3',
                         'Darwin1.2', 'darwin',
                         'freebsd2', 'freebsd3', 'freebsd4', 'freebsd5',
-                        'freebsd6', 'freebsd7', 'freebsd8',
+                        'freebsd6', 'freebsd7', 'freebsd8', 'freebsd9',
                         'bsdos2', 'bsdos3', 'bsdos4',
                         'openbsd', 'openbsd2', 'openbsd3', 'openbsd4'):
         if struct.calcsize('l') == 8:
