--- lib-python/2.7/socket.py.orig	2014-09-20 23:16:07.000000000 +0200
+++ lib-python/2.7/socket.py	2015-02-25 11:51:49.981063631 +0100
@@ -65,7 +65,6 @@
     from _ssl import SSLError as sslerror
     from _ssl import \
          RAND_add, \
-         RAND_egd, \
          RAND_status, \
          SSL_ERROR_ZERO_RETURN, \
          SSL_ERROR_WANT_READ, \
