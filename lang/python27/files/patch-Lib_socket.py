--- Lib/socket.py.orig	2014-12-10 16:59:40.000000000 +0100
+++ Lib/socket.py	2015-02-22 20:35:33.305638487 +0100
@@ -65,19 +65,33 @@
 
     # we need to import the same constants we used to...
     from _ssl import SSLError as sslerror
-    from _ssl import \
-         RAND_add, \
-         RAND_egd, \
-         RAND_status, \
-         SSL_ERROR_ZERO_RETURN, \
-         SSL_ERROR_WANT_READ, \
-         SSL_ERROR_WANT_WRITE, \
-         SSL_ERROR_WANT_X509_LOOKUP, \
-         SSL_ERROR_SYSCALL, \
-         SSL_ERROR_SSL, \
-         SSL_ERROR_WANT_CONNECT, \
-         SSL_ERROR_EOF, \
-         SSL_ERROR_INVALID_ERROR_CODE
+    try:
+        from _ssl import \
+             RAND_add, \
+             RAND_egd, \
+             RAND_status, \
+             SSL_ERROR_ZERO_RETURN, \
+             SSL_ERROR_WANT_READ, \
+             SSL_ERROR_WANT_WRITE, \
+             SSL_ERROR_WANT_X509_LOOKUP, \
+             SSL_ERROR_SYSCALL, \
+             SSL_ERROR_SSL, \
+             SSL_ERROR_WANT_CONNECT, \
+             SSL_ERROR_EOF, \
+             SSL_ERROR_INVALID_ERROR_CODE
+    except ImportError:
+        from _ssl import \
+             RAND_add, \
+             RAND_status, \
+             SSL_ERROR_ZERO_RETURN, \
+             SSL_ERROR_WANT_READ, \
+             SSL_ERROR_WANT_WRITE, \
+             SSL_ERROR_WANT_X509_LOOKUP, \
+             SSL_ERROR_SYSCALL, \
+             SSL_ERROR_SSL, \
+             SSL_ERROR_WANT_CONNECT, \
+             SSL_ERROR_EOF, \
+             SSL_ERROR_INVALID_ERROR_CODE
 
 import os, sys, warnings
 
