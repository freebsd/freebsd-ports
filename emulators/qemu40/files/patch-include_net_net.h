--- include/net/net.h.orig	2019-04-23 18:14:46 UTC
+++ include/net/net.h
@@ -209,8 +209,8 @@ void qmp_netdev_add(QDict *qdict, QObject **ret, Error
 int net_hub_id_for_client(NetClientState *nc, int *id);
 NetClientState *net_hub_port_find(int hub_id);
 
-#define DEFAULT_NETWORK_SCRIPT "/etc/qemu-ifup"
-#define DEFAULT_NETWORK_DOWN_SCRIPT "/etc/qemu-ifdown"
+#define DEFAULT_NETWORK_SCRIPT PREFIX "/etc/qemu-ifup"
+#define DEFAULT_NETWORK_DOWN_SCRIPT PREFIX "/etc/qemu-ifdown"
 #define DEFAULT_BRIDGE_HELPER CONFIG_QEMU_HELPERDIR "/qemu-bridge-helper"
 #define DEFAULT_BRIDGE_INTERFACE "br0"
 
