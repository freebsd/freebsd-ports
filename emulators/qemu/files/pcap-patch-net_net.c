--- net/net.c.orig	2018-04-24 16:30:47 UTC
+++ net/net.c
@@ -52,6 +52,11 @@
 #include "net/filter.h"
 #include "qapi/string-output-visitor.h"
 
+#include <sys/ioctl.h>
+#ifdef __FreeBSD__
+#include <net/if.h>
+#endif
+
 /* Net bridge is currently not supported for W32. */
 #if !defined(_WIN32)
 # define CONFIG_NET_BRIDGE
@@ -929,7 +934,225 @@ static int net_init_nic(const Netdev *netdev, const ch
     return idx;
 }
 
+#if defined(CONFIG_PCAP)
+#if defined(CONFIG_BPF)
+#define PCAP_DONT_INCLUDE_PCAP_BPF_H
+#include <net/bpf.h>
+#endif
+#include <pcap.h>
 
+struct PCAPState {
+    NetClientState     nc;
+    pcap_t            *handle;
+    int                max_eth_frame_size;
+};
+
+static ssize_t pcap_receive(NetClientState *nc, const uint8_t *buf, size_t size)
+{
+    struct PCAPState *s = DO_UPCAST(struct PCAPState, nc, nc);
+
+    return pcap_inject(s->handle, (u_char*)buf, size);
+}
+
+static void pcap_callback(u_char *user, struct pcap_pkthdr *phdr, u_char *pdata
+		)
+{
+    NetClientState *nc = (NetClientState *)user;
+
+    int len = phdr->len;
+#ifdef __FreeBSD__
+    struct PCAPState *s = DO_UPCAST(struct PCAPState, nc, nc);
+    int max_eth_frame_size = s->max_eth_frame_size;
+
+    if (len > max_eth_frame_size) {
+        fprintf(stderr,
+            "pcap_send: packet size > %d (%d), truncating\n",
+            max_eth_frame_size, len);
+        len = max_eth_frame_size;
+    }
+#endif
+    qemu_send_packet(nc, pdata, len);
+}
+
+static void pcap_send(void *opaque)
+{
+    struct PCAPState *s = (struct PCAPState *)opaque;
+
+    for (;;) {
+        if (pcap_dispatch(s->handle, 0, (pcap_handler)&pcap_callback, (u_char *)&s->nc) >= 0)
+            break;
+    }
+}
+
+static void pcap_cleanup(NetClientState *nc)
+{
+    struct PCAPState *s = DO_UPCAST(struct PCAPState, nc, nc);
+
+    qemu_purge_queued_packets(nc);
+    pcap_close(s->handle);
+}
+
+static NetClientInfo net_pcap_info = {
+    .type = NET_CLIENT_DRIVER_PCAP,
+    .size = sizeof(struct PCAPState),
+    .receive = pcap_receive,
+//    .receive_raw = pcap_receive_raw,
+//    .receive_iov = pcap_receive_iov,
+//    .poll = pcap_poll,
+    .cleanup = pcap_cleanup,
+};
+/*
+ * ... -net pcap,ifname="..."
+ */
+
+int net_init_pcap(const Netdev *netdev,
+    const char *name, NetClientState *peer, Error **errp)
+{
+    const NetdevPcapOptions *pcap_opts;
+    NetClientState *nc;
+    struct PCAPState *s;
+    const char *ifname;
+    char errbuf[PCAP_ERRBUF_SIZE];
+#if defined(_WIN32)
+    HANDLE h;
+#endif
+    int i;
+
+    assert(netdev->type == NET_CLIENT_DRIVER_PCAP);
+    pcap_opts = &netdev->u.pcap;
+    if (!pcap_opts->has_ifname)
+        return -1;
+
+    ifname = pcap_opts->ifname;
+
+    /* create the object */
+    nc = qemu_new_net_client(&net_pcap_info, peer, "pcap", ifname);
+    s = DO_UPCAST(struct PCAPState, nc, nc);
+
+    if (ifname == NULL && (ifname = pcap_lookupdev(errbuf)) == NULL) {
+        fprintf(stderr, "qemu: pcap_create: %s\n", errbuf);
+        goto fail;
+    }
+ 
+#ifdef __FreeBSD__
+    /*
+     * We want to avoid passing oversize packets to the guest, which
+     * at least on FreeBSD can happen if the host interface uses tso
+     * (seen with an em(4) in this case) - so find out the host
+    * interface's mtu and assume the guest is configured the same.
+     */
+    s->max_eth_frame_size = 1514;
+    i = socket(AF_INET, SOCK_DGRAM, 0);
+    if (i >= 0) {
+        struct ifreq ifr;
+
+        (void) memset(&ifr, 0, sizeof(ifr));
+        strncpy(ifr.ifr_name, ifname, sizeof(ifr.ifr_name));
+        if (ioctl(i, SIOCGIFMTU, &ifr) != -1)
+            s->max_eth_frame_size = ifr.ifr_mtu + 14;
+        close(i);
+    }
+#endif
+
+#if defined(CONFIG_PCAP_CREATE) || defined(_WIN32)
+    /*
+     * Create pcap handle for the device, set promiscuous mode and activate.
+     */
+    s->handle = (void *)pcap_create(ifname, errbuf);
+    if (!s->handle) {
+        fprintf(stderr, "qemu: pcap_create: %s\n", errbuf);
+        goto fail;
+    }
+    if (pcap_set_promisc(s->handle, 1) != 0) {
+        pcap_perror(s->handle, (char *)"qemu: pcap_set_promisc:");
+        goto fail;
+    }
+   if (pcap_activate(s->handle) != 0) {
+        pcap_perror(s->handle, (char *)"qemu: pcap_activate:");
+        goto fail;
+    }
+#else
+    /* Attempt to connect device. */
+    s->handle = (void *)pcap_open_live(ifname, 65535, 1, 0, errbuf);
+    if (!s->handle) {
+        fprintf(stderr, "qemu: pcap_open_live: %s\n", errbuf);
+        goto fail;
+    }
+#endif
+
+    /* Set non-blocking mode. */
+    if (pcap_setnonblock(s->handle, 1, errbuf) < 0) {
+        fprintf(stderr, "qemu: pcap_setnonblock: %s\n", errbuf);
+        goto fail;
+    }
+
+#if defined(_WIN32)
+    /*
+     * Tell the kernel that the packet has to be seen immediately.
+     */
+    if (pcap_setmintocopy(s->handle, 0) < 0) {
+        fprintf(stderr, "qemu: pcap failed to set immediate mode\n");
+        goto fail;
+    }
+#else /* !_WIN32 */
+#if defined(CONFIG_BPF)
+#if defined(BIOCIMMEDIATE)
+    /*
+     * Tell the kernel that the packet has to be seen immediately.
+     */
+    {
+        unsigned int one = 1;
+        if (ioctl(pcap_fileno(s->handle), BIOCIMMEDIATE, &one) < 0) {
+            fprintf(stderr, "qemu: pcap failed to set immediate mode\n");
+            goto fail;
+        }
+    }
+#endif /* BIOCIMMEDIATE */
+#if defined(BIOCFEEDBACK)
+    /*
+     * Tell the kernel that the sent packet has to be fed back.
+     * This is necessary to connect host and guest.
+     */
+    {
+        unsigned int one = 1;
+        if (ioctl(pcap_fileno(s->handle), BIOCFEEDBACK, &one) < 0) {
+            fprintf(stderr, "qemu: pcap failed to set feedback mode\n");
+            goto fail;
+        }
+    }
+#endif /* BIOCFEEDBACK */
+#endif /* CONFIG_BPF */
+#endif /* _WIN32 */
+
+    snprintf(s->nc.info_str, sizeof(s->nc.info_str), "pcap redirector");
+
+#if defined(_WIN32)
+    if ((h = pcap_getevent(s->handle)) == NULL) {
+        fprintf(stderr, "qemu: pcap_getevent failed\n");
+        goto fail;
+    }
+    qemu_add_wait_object(h, pcap_send, s);
+#else /* !_WIN32 */
+    if ((i = pcap_get_selectable_fd(s->handle)) < 0) {
+        fprintf(stderr, "qemu: pcap_get_selectable_fd failed\n");
+        goto fail;
+    }
+    qemu_set_fd_handler(i, pcap_send, NULL, s);
+#endif /* _WIN32 */
+
+    return 0;
+
+fail:
+    if (s) {
+        if (s->handle)
+            pcap_close(s->handle);
+    }
+
+    return -1;
+}
+
+#endif
+ 
 static int (* const net_client_init_fun[NET_CLIENT_DRIVER__MAX])(
     const Netdev *netdev,
     const char *name,
@@ -955,6 +1178,9 @@ static int (* const net_client_init_fun[NET_CLIENT_DRI
 #endif
 #ifdef CONFIG_L2TPV3
         [NET_CLIENT_DRIVER_L2TPV3]    = net_init_l2tpv3,
+#endif
+#ifdef CONFIG_PCAP
+	[NET_CLIENT_DRIVER_PCAP]      = net_init_pcap,
 #endif
 };
 
