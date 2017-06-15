--- tftpy/TftpStates.py.orig	2016-07-07 08:32:15 UTC
+++ tftpy/TftpStates.py
@@ -368,7 +368,7 @@ class TftpStateServerRecvWRQ(TftpServerS
             f = self.context.upload_open(path, self.context)
             if f is None:
                 self.sendError(TftpErrors.AccessViolation)
-                raise TftpException, "Dynamic path %s not permitted" % path
+                raise TftpException("Dynamic path %s not permitted" % path)
             else:
                 self.context.fileobj = f
         else:
