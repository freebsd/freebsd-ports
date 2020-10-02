--- include/Listener.hpp.orig	2020-09-27 20:39:06 UTC
+++ include/Listener.hpp
@@ -79,7 +79,7 @@ class Listener { (private)
     thread_Settings *mSettings;
     thread_Settings *server;
     Timestamp mEndTime;
-    bool apply_client_settings(thread_Settings *server);
+    int apply_client_settings(thread_Settings *server);
     int client_test_ack(thread_Settings *server);
     void my_multicast_join(void);
     void my_listen(void);
