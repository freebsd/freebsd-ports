--- include/net/net.h.orig	2020-04-28 16:49:24 UTC
+++ include/net/net.h
@@ -208,8 +208,8 @@ void netdev_add(QemuOpts *opts, Error **errp);
 int net_hub_id_for_client(NetClientState *nc, int *id);
 NetClientState *net_hub_port_find(int hub_id);
 
-#define DEFAULT_NETWORK_SCRIPT "/etc/qemu-ifup"
-#define DEFAULT_NETWORK_DOWN_SCRIPT "/etc/qemu-ifdown"
+#define DEFAULT_NETWORK_SCRIPT PREFIX "/etc/qemu-ifup"
+#define DEFAULT_NETWORK_DOWN_SCRIPT PREFIX "/etc/qemu-ifdown"
 #define DEFAULT_BRIDGE_HELPER CONFIG_QEMU_HELPERDIR "/qemu-bridge-helper"
 #define DEFAULT_BRIDGE_INTERFACE "br0"
 
