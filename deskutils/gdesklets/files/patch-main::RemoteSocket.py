--- main/RemoteSocket.py.orig  Fri Mar  4 15:50:32 2005
+++ main/RemoteSocket.py       Fri Mar  4 15:50:45 2005
@@ -60,7 +60,7 @@
                     log("Couldn't bind to socket. Aborting.")
                     sys.exit(1)

-        serversock.listen(1)
+        serversock.listen(3)
         serversock.setblocking(False)

         atexit.register(self.__shutdown, serversock, sockfile)
