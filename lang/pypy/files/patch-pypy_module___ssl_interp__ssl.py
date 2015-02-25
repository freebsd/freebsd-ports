--- pypy/module/_ssl/interp_ssl.py.orig	2014-09-20 23:16:07.000000000 +0200
+++ pypy/module/_ssl/interp_ssl.py	2015-02-25 11:57:47.468037826 +0100
@@ -101,13 +101,7 @@
         Queries the entropy gather daemon (EGD) on socket path.  Returns number
         of bytes read.  Raises socket.sslerror if connection to EGD fails or
         if it does provide enough data to seed PRNG."""
-        with rffi.scoped_str2charp(path) as socket_path:
-            bytes = libssl_RAND_egd(socket_path)
-        if bytes == -1:
-            raise ssl_error(space,
-                            "EGD connection failed or EGD did not return "
-                            "enough data to seed the PRNG")
-        return space.wrap(bytes)
+        ssl_error(space, "EGD disabled")
 
 
 class SSLObject(W_Root):
