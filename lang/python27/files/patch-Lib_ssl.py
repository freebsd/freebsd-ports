--- Lib/ssl.py.orig	2014-12-10 16:59:40.000000000 +0100
+++ Lib/ssl.py	2015-01-27 21:22:33.606365700 +0100
@@ -107,6 +107,10 @@
     VERIFY_X509_STRICT)
 from _ssl import txt2obj as _txt2obj, nid2obj as _nid2obj
 from _ssl import RAND_status, RAND_egd, RAND_add
+try:
+     from _ssl import RAND_status, RAND_egd, RAND_add
+except ImportError:
+     from _ssl import RAND_status, RAND_add
 
 def _import_symbols(prefix):
     for n in dir(_ssl):
