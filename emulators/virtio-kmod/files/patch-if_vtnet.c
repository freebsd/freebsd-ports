--- sys/dev/virtio/network/if_vtnet.c.orig	2013-06-10 13:44:32.626245199 +0900
+++ sys/dev/virtio/network/if_vtnet.c	2013-06-10 13:46:44.810245935 +0900
@@ -2473,9 +2473,9 @@
 	sglist_init(&sg, 4, segs);
 	error |= sglist_append(&sg, &hdr, sizeof(struct virtio_net_ctrl_hdr));
 	error |= sglist_append(&sg, &filter->vmf_unicast,
-	    sizeof(struct vtnet_mac_table));
+	    sizeof(uint32_t) + filter->vmf_unicast.nentries * ETHER_ADDR_LEN);
 	error |= sglist_append(&sg, &filter->vmf_multicast,
-	    sizeof(struct vtnet_mac_table));
+	    sizeof(uint32_t) + filter->vmf_multicast.nentries * ETHER_ADDR_LEN);
 	error |= sglist_append(&sg, &ack, sizeof(uint8_t));
 	KASSERT(error == 0 && sg.sg_nseg == 4,
 	    ("error adding MAC filtering message to sglist"));
