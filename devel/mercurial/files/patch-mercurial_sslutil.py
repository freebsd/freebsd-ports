Change condition in order to prevent SSLv2 and SSLv3 protocols.
Taken from ${PYTHON_LIBDIR}/ssl.py file (found in 'create_default_context'
function).

--- mercurial/sslutil.py.orig	2015-07-18 22:33:53 UTC
+++ mercurial/sslutil.py
@@ -28,7 +28,10 @@ try:
         # maintainers for us, but that breaks too many things to
         # do it in a hurry.
         sslcontext = ssl.SSLContext(ssl.PROTOCOL_SSLv23)
-        sslcontext.options &= ssl.OP_NO_SSLv2 & ssl.OP_NO_SSLv3
+        # SSLv2 is considered harmful
+        sslcontext.options |= ssl.OP_NO_SSLv2
+        # SSLv3 has problematic security issue
+        sslcontext.options |= ssl.OP_NO_SSLv3
         if certfile is not None:
             def password():
                 f = keyfile or certfile
