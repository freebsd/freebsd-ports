--- oslo_messaging/_drivers/impl_rabbit.py.orig	2018-03-27 18:46:38 UTC
+++ oslo_messaging/_drivers/impl_rabbit.py
@@ -919,8 +919,8 @@ class Connection(object):
                       % (self.connection_id, str(e)))
         else:
             sock.settimeout(timeout)
-            # TCP_USER_TIMEOUT is not defined on Windows and Mac OS X
-            if sys.platform != 'win32' and sys.platform != 'darwin':
+            # TCP_USER_TIMEOUT is not defined on FreeBSD, Windows and Mac OS X
+            if sys.platform[0:7] != 'freebsd' and sys.platform != 'win32' and sys.platform != 'darwin':
                 try:
                     timeout = timeout * 1000 if timeout is not None else 0
                     # NOTE(gdavoian): only integers and strings are allowed
