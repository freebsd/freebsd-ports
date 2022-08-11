--- vendor/adb/client/file_sync_client.cpp.orig	2022-06-09 20:52:06 UTC
+++ vendor/adb/client/file_sync_client.cpp
@@ -394,9 +394,16 @@ class SyncConnection {
 
         void* p = buf.data();
 
+#ifdef __FreeBSD__
+	// TODO: Delete when 12.x goes EOL
+        p = (char *)memcpy(p, &req, sizeof(SyncRequest)) + sizeof(SyncRequest);
+        p = (char *)memcpy(p, path.data(), path.length()) + path.length();
+        p = (char *)memcpy(p, &msg.send_v2_setup, sizeof(msg.send_v2_setup)) + sizeof(msg.send_v2_setup);
+#else
         p = mempcpy(p, &req, sizeof(SyncRequest));
         p = mempcpy(p, path.data(), path.length());
         p = mempcpy(p, &msg.send_v2_setup, sizeof(msg.send_v2_setup));
+#endif
 
         return WriteFdExactly(fd, buf.data(), buf.size());
     }
@@ -441,9 +448,16 @@ class SyncConnection {
 
         void* p = buf.data();
 
+#ifdef __FreeBSD__
+	// TODO: Delete when 12.x goes EOL
+        p = (char *)memcpy(p, &req, sizeof(SyncRequest)) + sizeof(SyncRequest);
+        p = (char *)memcpy(p, path.data(), path.length()) + path.length();
+        p = (char *)memcpy(p, &msg.send_v2_setup, sizeof(msg.send_v2_setup)) + sizeof(msg.send_v2_setup);
+#else
         p = mempcpy(p, &req, sizeof(SyncRequest));
         p = mempcpy(p, path.data(), path.length());
-        p = mempcpy(p, &msg.recv_v2_setup, sizeof(msg.recv_v2_setup));
+        p = mempcpy(p, &msg.send_v2_setup, sizeof(msg.send_v2_setup));
+#endif
 
         return WriteFdExactly(fd, buf.data(), buf.size());
     }
