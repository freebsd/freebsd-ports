--- src/VBox/Devices/Network/slirp/bsd/sys/mbuf.h.orig	2015-03-02 10:09:19.000000000 -0500
+++ src/VBox/Devices/Network/slirp/bsd/sys/mbuf.h	2015-03-02 19:42:56.808020000 -0500
@@ -241,6 +241,9 @@
 #define	M_FRAG		0x00000800 /* packet is a fragment of a larger packet */
 #define	M_FIRSTFRAG	0x00001000 /* packet is first fragment */
 #define	M_LASTFRAG	0x00002000 /* packet is last fragment */
+#ifdef M_SKIP_FIREWALL
+#undef M_SKIP_FIREWALL
+#endif
 #define	M_SKIP_FIREWALL	0x00004000 /* skip firewall processing */
 #define	M_FREELIST	0x00008000 /* mbuf is on the free list */
 #define	M_VLANTAG	0x00010000 /* ether_vtag is valid */
