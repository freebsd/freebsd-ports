--- ./src/GMAudioScrobbler.cpp.orig	2011-03-02 17:15:43.000000000 +0100
+++ ./src/GMAudioScrobbler.cpp	2011-03-13 19:12:36.773792904 +0100
@@ -128,10 +128,6 @@
 
   FXint result = connect(server,entry->ai_addr,entry->ai_addrlen);
   if (result!=-1) {
-#if defined(SO_NOSIGPIPE)
-    int onoff=1;
-    setsockopt(server,SOL_SOCKET,SO_NOSIGPIPE,1,(void*)&onoff,sizeof(onoff));
-#endif
     return server;
     }
   ::close(server);
