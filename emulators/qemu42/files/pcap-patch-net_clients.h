--- net/clients.h.orig	2018-04-24 16:30:47 UTC
+++ net/clients.h
@@ -61,4 +61,10 @@ int net_init_netmap(const Netdev *netdev, const char *
 int net_init_vhost_user(const Netdev *netdev, const char *name,
                         NetClientState *peer, Error **errp);
 
+#ifdef CONFIG_PCAP
+int net_init_pcap(const Netdev *netdev, const char *name,
+                    NetClientState *peer, Error **errp);
+#endif
+
+
 #endif /* QEMU_NET_CLIENTS_H */
