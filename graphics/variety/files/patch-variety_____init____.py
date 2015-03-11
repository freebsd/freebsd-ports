--- variety/__init__.py.orig	2015-03-07 13:09:20 UTC
+++ variety/__init__.py
@@ -155,6 +155,12 @@ def main():
     signal.signal(signal.SIGTERM, sigint_handler)
     signal.signal(signal.SIGQUIT, sigint_handler)
 
+    if 34015728 <= sys.hexversion:
+        from setuptools import ssl_support as ssl_support
+        ssl_cert_file = ssl_support.find_ca_bundle()
+        if not ssl_cert_file and not 'SSL_CERT_FILE' in os.environ:
+           os.environ['SSL_CERT_FILE'] = '%%LOCALBASE%%/share/certs/ca-root-nss.crt'
+
     Util.makedirs(os.path.expanduser(u"~/.config/variety/"))
 
     arguments = map(_u, sys.argv[1:])
