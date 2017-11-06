--- tftpy/TftpServer.py.orig	2016-07-07 08:32:15 UTC
+++ tftpy/TftpServer.py
@@ -53,8 +53,8 @@ class TftpServer(TftpSession):
         for name in 'dyn_file_func', 'upload_open':
             attr = getattr(self, name)
             if attr and not callable(attr):
-                raise TftpException, "%s supplied, but it is not callable." % (
-                    name,)
+                raise TftpException("%s supplied, but it is not callable." % (
+                    name))
         if os.path.exists(self.root):
             log.debug("tftproot %s does exist", self.root)
             if not os.path.isdir(self.root):
