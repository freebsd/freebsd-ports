--- src/ES2Command/Src/Interface/ipc/ipcInterfaceImpl.cpp.orig	2021-11-25 00:56:54 UTC
+++ src/ES2Command/Src/Interface/ipc/ipcInterfaceImpl.cpp
@@ -307,7 +307,7 @@ bool IPCInterfaceImpl::recv_reply(uint32_t* token)
     if (placeholder) delete [] placeholder;
     if (token) *token = hdr_token(hdr);
     if (hdr_error(hdr) || n < 0) {
-        ES_ERROR_LOG(ES_STRING("recv_reply err.(%d, %d, n)"), hdr_error(hdr), hdr_token(hdr), n);
+        ES_ERROR_LOG(ES_STRING("recv_reply err.(%d, %d, %ld)"), hdr_error(hdr), hdr_token(hdr), n);
         return false;
     }
     return true;
