--- Lib/test/test_fcntl.py.orig	Sun Apr  3 22:45:13 2005
+++ Lib/test/test_fcntl.py	Sun Apr  3 22:45:19 2005
@@ -24,7 +24,13 @@
                     'freebsd2', 'freebsd3', 'freebsd4', 'freebsd5', 'freebsd6',
                     'bsdos2', 'bsdos3', 'bsdos4',
                     'openbsd', 'openbsd2', 'openbsd3'):
-    lockdata = struct.pack('lxxxxlxxxxlhh', 0, 0, 0, fcntl.F_WRLCK, 0)
+    if struct.calcsize('l') == 8:
+        off_t = 'l'
+        pid_t = 'i'
+    else:
+        off_t = 'lxxxx'
+        pid_t = 'l'
+    lockdata = struct.pack(off_t+off_t+pid_t+'hh', 0, 0, 0, fcntl.F_WRLCK, 0)
 elif sys.platform in ['aix3', 'aix4', 'hp-uxB', 'unixware7']:
     lockdata = struct.pack('hhlllii', fcntl.F_WRLCK, 0, 0, 0, 0, 0, 0)
 elif sys.platform in ['os2emx']:
