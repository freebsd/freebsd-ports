Description: ssl.wrap_socket() was removed in Python 3.12. Wrap
  curio.ssl.wrap_socket() around SSLContext.wrap_socket (upstream a5590bb),
  and do what ssl.wrap_socket() did with a local helper (upstream a5590bb
  changed only the decorator, and its later SSLContext.wrap_socket(sock, ...)
  call passes the socket as self).
Issue ID: none
Changeset: https://github.com/dabeaz/curio/commit/a5590bb (decorator only)
TODO: Upstream was archived on 2025-12-21, no further release expected; keep.

--- curio/ssl.py.orig	2022-10-25 14:18:45 UTC
+++ curio/ssl.py
@@ -27,12 +27,36 @@ from .workers import run_in_thread
 from .io import Socket
 
 if _ssl:
-    @wraps(_ssl.wrap_socket)
+    def _wrap_socket(sock, keyfile=None, certfile=None, server_side=False,
+                     cert_reqs=_ssl.CERT_NONE, ssl_version=None, ca_certs=None,
+                     do_handshake_on_connect=True, suppress_ragged_eofs=True,
+                     ciphers=None):
+        # ssl.wrap_socket() was removed in Python 3.12; this is what it did.
+        if server_side and not certfile:
+            raise ValueError('certfile must be specified for server-side operations')
+        if keyfile and not certfile:
+            raise ValueError('certfile must be specified')
+        if ssl_version is None:
+            ssl_version = _ssl.PROTOCOL_TLS_SERVER if server_side else _ssl.PROTOCOL_TLS_CLIENT
+        context = _ssl.SSLContext(ssl_version)
+        context.check_hostname = False
+        context.verify_mode = cert_reqs
+        if ca_certs:
+            context.load_verify_locations(ca_certs)
+        if certfile:
+            context.load_cert_chain(certfile, keyfile)
+        if ciphers:
+            context.set_ciphers(ciphers)
+        return context.wrap_socket(sock, server_side=server_side,
+                                   do_handshake_on_connect=do_handshake_on_connect,
+                                   suppress_ragged_eofs=suppress_ragged_eofs)
+
+    @wraps(_ssl.SSLContext.wrap_socket)
     async def wrap_socket(sock, *args, do_handshake_on_connect=True, **kwargs):
         if isinstance(sock, Socket):
             sock = sock._socket
 
-        ssl_sock = _ssl.wrap_socket(sock, *args, do_handshake_on_connect=False, **kwargs)
+        ssl_sock = _wrap_socket(sock, *args, do_handshake_on_connect=False, **kwargs)
         cssl_sock = Socket(ssl_sock)
         cssl_sock.do_handshake_on_connect = do_handshake_on_connect
         if do_handshake_on_connect and ssl_sock._connected:
