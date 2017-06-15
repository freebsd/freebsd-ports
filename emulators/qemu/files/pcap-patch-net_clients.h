--- net/clients.h.orig	2017-03-05 10:36:13.475005000 -0700
+++ net/clients.h	2017-03-05 10:35:30.412539000 -0700
@@ -61,4 +61,10 @@
 
 int net_init_vhost_user(const Netdev *netdev, const char *name,
                         NetClientState *peer, Error **errp);
+
+#ifdef CONFIG_PCAP
+int net_init_pcap(const Netdev *netdev, const char *name,
+                    NetClientState *peer, Error **errp);
+#endif
+
 #endif /* QEMU_NET_CLIENTS_H */
