--- lib/rpcChannel/rpcChannel.c.orig	2026-01-27 11:15:50 UTC
+++ lib/rpcChannel/rpcChannel.c
@@ -308,7 +308,7 @@ RpcChannelXdrWrapper(RpcInData *data,
          goto exit;
       }
 
-      if (!xdrProc(&xdrs, copy.result, 0)) {
+      if (!xdrProc(&xdrs, copy.result)) {
          ret = RPCIN_SETRETVALS(data, "XDR serialization failed.", FALSE);
 
          /*
@@ -378,7 +378,7 @@ RpcChannel_BuildXdrCommand(const char *cmd,
       goto exit;
    }
 
-   if (!proc(&xdrs, xdrData, 0)) {
+   if (!proc(&xdrs, xdrData)) {
       goto exit;
    }
 
