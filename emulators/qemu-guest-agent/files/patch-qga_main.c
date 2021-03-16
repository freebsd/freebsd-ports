--- qga/main.c.orig	2020-09-15 16:31:14 UTC
+++ qga/main.c
@@ -46,9 +46,15 @@
 #endif
 
 #ifndef _WIN32
+#ifdef BSD_GUEST_AGENT
+#define QGA_VIRTIO_PATH_DEFAULT "/dev/vtcon/org.qemu.guest_agent.0"
+#define QGA_STATE_RELATIVE_DIR  "run"
+#define QGA_SERIAL_PATH_DEFAULT "/dev/vtcon/org.qemu.guest_agent.0"
+#else
 #define QGA_VIRTIO_PATH_DEFAULT "/dev/virtio-ports/org.qemu.guest_agent.0"
 #define QGA_STATE_RELATIVE_DIR  "run"
 #define QGA_SERIAL_PATH_DEFAULT "/dev/ttyS0"
+#endif // BSD_GUEST_AGENT
 #else
 #define QGA_VIRTIO_PATH_DEFAULT "\\\\.\\Global\\org.qemu.guest_agent.0"
 #define QGA_STATE_RELATIVE_DIR  "qemu-ga"
@@ -1478,7 +1484,11 @@ int main(int argc, char **argv)
     }
 
     if (config->method == NULL) {
+#ifdef BSD_GUEST_AGENT
+        config->method = g_strdup("isa-serial");
+#else
         config->method = g_strdup("virtio-serial");
+#endif // BSD_GUEST_AGENT
     }
 
     socket_activation = check_socket_activation();
