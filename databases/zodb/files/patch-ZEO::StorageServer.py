--- ZEO/StorageServer.py.orig	Fri Dec  3 01:27:05 2004
+++ ZEO/StorageServer.py	Fri Dec  3 01:27:22 2004
@@ -268,7 +268,7 @@
 
     def message_input(self, message,
                       dump=dump, Unpickler=Unpickler, StringIO=StringIO,
-                      None=None):
+                      _None=None):
         if __debug__:
             if len(message) > max_blather:
                 tmp = `message[:max_blather]`
@@ -276,7 +276,7 @@
                 tmp = `message`
             blather('message_input', id(self), tmp)
 
-        if self.__storage is None:
+        if self.__storage is _None:
             # This is the first communication from the client
             self.__storage, self.__storage_id = (
                 self.__server.register_connection(self, message))
