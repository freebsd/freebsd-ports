Index: qemu/include/net/net.h
@@ -174,8 +174,8 @@ void net_host_device_remove(Monitor *mon
 int do_netdev_add(Monitor *mon, const QDict *qdict, QObject **ret_data);
 int do_netdev_del(Monitor *mon, const QDict *qdict, QObject **ret_data);
 
-#define DEFAULT_NETWORK_SCRIPT "/etc/qemu-ifup"
-#define DEFAULT_NETWORK_DOWN_SCRIPT "/etc/qemu-ifdown"
+#define DEFAULT_NETWORK_SCRIPT PREFIX "/etc/qemu-ifup"
+#define DEFAULT_NETWORK_DOWN_SCRIPT PREFIX "/etc/qemu-ifdown"
 #define DEFAULT_BRIDGE_HELPER CONFIG_QEMU_HELPERDIR "/qemu-bridge-helper"
 #define DEFAULT_BRIDGE_INTERFACE "br0"
 
