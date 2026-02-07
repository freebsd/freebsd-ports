--- src/ES2Command/Src/Interface/ipc/ipcInterfaceImpl.cpp.orig	2024-09-12 07:10:32 UTC
+++ src/ES2Command/Src/Interface/ipc/ipcInterfaceImpl.cpp
@@ -129,7 +129,9 @@ ESErrorCode IPCInterfaceImpl::Open()
         if(!ES_IsExistFile(dat_file)){
             FILE *fp;
             fp = fopen(dat_file.c_str(),"w");
-            fclose(fp);
+            if (fp) {
+                fclose(fp);
+            }
         }
         interrupt_.reset(new ipc_interrupt(delegate_, dat_file, IPC_SHARED_ID, IPC_SEMAHORE_KEY));
         interrupt_->start();
@@ -305,7 +307,7 @@ bool IPCInterfaceImpl::recv_reply(uint32_t* token)
     if (placeholder) delete [] placeholder;
     if (token) *token = hdr_token(hdr);
     if (hdr_error(hdr) || n < 0) {
-        ES_ERROR_LOG(ES_STRING("recv_reply err.(%d, %d, n)"), hdr_error(hdr), hdr_token(hdr), n);
+        ES_ERROR_LOG(ES_STRING("recv_reply err.(%d, %d, %ld)"), hdr_error(hdr), hdr_token(hdr), n);
         return false;
     }
     return true;
