===================================================================
RCS file: /cvsroot/python/python/dist/src/Lib/posixfile.py,v
retrieving revision 1.25
retrieving revision 1.26
diff -u -r1.25 -r1.26
--- Lib/posixfile.py	2004/02/12 17:35:06	1.25
+++ Lib/posixfile.py	2004/08/18 15:13:40	1.26
@@ -185,7 +185,7 @@
         if sys.platform in ('netbsd1',
                             'openbsd2',
                             'freebsd2', 'freebsd3', 'freebsd4', 'freebsd5',
-                            'bsdos2', 'bsdos3', 'bsdos4'):
+                            'freebsd6', 'bsdos2', 'bsdos3', 'bsdos4'):
             flock = struct.pack('lxxxxlxxxxlhh', \
                   l_start, l_len, os.getpid(), l_type, l_whence)
         elif sys.platform in ['aix3', 'aix4']:
