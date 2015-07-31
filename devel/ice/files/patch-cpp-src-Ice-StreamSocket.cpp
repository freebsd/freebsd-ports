--- cpp/src/Ice/StreamSocket.cpp.orig	2015-07-03 16:22:19.091609986 +0200
+++ cpp/src/Ice/StreamSocket.cpp	2015-07-03 16:22:32.355937985 +0200
@@ -32,7 +32,7 @@
 #ifndef ICE_USE_IOCP
     if(doConnect(_fd, _proxy ? _proxy->getAddress() : _addr, sourceAddr))
     {
-        _state = StateConnected;
+        _state = _proxy ? StateProxyWrite : StateConnected;
     }
 #endif
     _desc = fdToString(_fd, _proxy, _addr);
