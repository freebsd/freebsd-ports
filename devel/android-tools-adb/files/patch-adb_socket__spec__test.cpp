--- adb/socket_spec_test.cpp.orig	2020-02-11 20:44:45 UTC
+++ adb/socket_spec_test.cpp
@@ -98,7 +98,11 @@ TEST(socket_spec, get_host_socket_spec_port) {
     EXPECT_EQ(5555, get_host_socket_spec_port("tcp:5555", &error));
     EXPECT_EQ(5555, get_host_socket_spec_port("tcp:localhost:5555", &error));
     EXPECT_EQ(5555, get_host_socket_spec_port("tcp:[::1]:5555", &error));
+#if ADB_LINUX
     EXPECT_EQ(5555, get_host_socket_spec_port("vsock:5555", &error));
+#else
+    EXPECT_EQ(-1, get_host_socket_spec_port("vsock:5555", &error));
+#endif
 }
 
 TEST(socket_spec, get_host_socket_spec_port_no_port) {
