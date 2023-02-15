--- setup/resources.py.orig	2023-02-03 02:11:49 UTC
+++ setup/resources.py
@@ -142,19 +142,19 @@ class CACerts(Command):  # {{{
         except OSError as err:
             if err.errno != errno.ENOENT:
                 raise
-            raw = b''
-        nraw = download_securely('https://curl.haxx.se/ca/cacert.pem')
-        if not nraw:
-            raise RuntimeError('Failed to download CA cert bundle')
-        if nraw != raw:
-            self.info('Updating Mozilla CA certificates')
-            with open(self.CA_PATH, 'wb') as f:
-                f.write(nraw)
-            self.verify_ca_certs()
-
-    def verify_ca_certs(self):
-        from calibre.utils.https import get_https_resource_securely
-        get_https_resource_securely('https://calibre-ebook.com', cacerts=self.b(self.CA_PATH))
+#            raw = b''
+#        nraw = download_securely('https://curl.haxx.se/ca/cacert.pem')
+#        if not nraw:
+#            raise RuntimeError('Failed to download CA cert bundle')
+#        if nraw != raw:
+#            self.info('Updating Mozilla CA certificates')
+#            with open(self.CA_PATH, 'wb') as f:
+#                f.write(nraw)
+#            self.verify_ca_certs()
+#
+#    def verify_ca_certs(self):
+#        from calibre.utils.https import get_https_resource_securely
+#        get_https_resource_securely('https://calibre-ebook.com', cacerts=self.b(self.CA_PATH))
 # }}}
 
 
