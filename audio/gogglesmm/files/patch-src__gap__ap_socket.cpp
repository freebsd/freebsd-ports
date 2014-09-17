--- src/gap/ap_socket.cpp.orig
+++ src/gap/ap_socket.cpp
@@ -41,14 +41,14 @@
 #ifndef SOCK_CLOEXEC
   if (!ap_set_closeonexec(device)){
     ::close(device);
-    return BadHandle;
+    return;
     }
 #endif
 
 #ifndef SOCK_NONBLOCK
   if (access&FXIO::NonBlocking && !ap_set_nonblocking(device)){
     ::close(device);
-    return BadHandle;
+    return;
     }
 #endif
   }
