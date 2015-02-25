--- pypy/module/_ssl/__init__.py.orig	2014-09-20 23:16:07.000000000 +0200
+++ pypy/module/_ssl/__init__.py	2015-02-25 11:55:14.821051337 +0100
@@ -24,7 +24,6 @@
         if HAVE_OPENSSL_RAND:
             Module.interpleveldefs['RAND_add'] = "interp_ssl.RAND_add"
             Module.interpleveldefs['RAND_status'] = "interp_ssl.RAND_status"
-            Module.interpleveldefs['RAND_egd'] = "interp_ssl.RAND_egd"
 
         super(Module, cls).buildloaders()
 
