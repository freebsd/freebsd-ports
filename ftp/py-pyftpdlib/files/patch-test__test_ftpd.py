--- ./test/test_ftpd.py.orig	2012-01-26 05:16:27.000000000 +1100
+++ ./test/test_ftpd.py	2012-09-15 01:25:53.000000000 +1000
@@ -77,6 +77,8 @@
 except ImportError:
     sendfile = None
 
+#Path hacks
+sys.path.insert(0, os.path.abspath('..'))
 from pyftpdlib import ftpserver
 
 
