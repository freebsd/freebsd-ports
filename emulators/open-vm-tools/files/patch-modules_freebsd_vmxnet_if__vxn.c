--- modules/freebsd/vmxnet/if_vxn.c.orig	2017-02-24 22:15:37 UTC
+++ modules/freebsd/vmxnet/if_vxn.c
@@ -76,6 +76,10 @@
 #include <pci/pcivar.h>
 #endif
 
+#if __FreeBSD_version >= 1100001
+#include <net/if_var.h>
+#endif
+
 /* define INLINE the way gcc likes it */
 #define INLINE __inline__
 
@@ -936,14 +940,14 @@ vxn_encap(struct ifnet *ifp,
    if (m != NULL) {
       struct mbuf    *m_new = NULL;
 
-      MGETHDR(m_new, M_DONTWAIT, MT_DATA);
+      MGETHDR(m_new, M_NOWAIT, MT_DATA);
       if (m_new == NULL) {
          printf("vxn%d: no memory for tx list\n", VXN_IF_UNIT(ifp));
          return 1;
       }
 
       if (m_head->m_pkthdr.len > MHLEN) {
-         MCLGET(m_new, M_DONTWAIT);
+         MCLGET(m_new, M_NOWAIT);
          if (!(m_new->m_flags & M_EXT)) {
             m_freem(m_new);
             printf("vxn%d: no memory for tx list\n", VXN_IF_UNIT(ifp));
@@ -1067,7 +1071,11 @@ vxn_startl(struct ifnet *ifp)
       VMXNET_INC(dd->txDriverNext, dd->txRingLength);
       dd->txNumDeferred++;
       sc->vxn_tx_pending++;
-      ifp->if_opackets++;
+#if __FreeBSD_version >= 1100036
+      if_inc_counter(ifp, IFCOUNTER_OPACKETS, 1);
+#else
+     ifp->if_opackets++;
+#endif
    }
 
    /*
@@ -1266,9 +1274,9 @@ vxn_rx(vxn_softc_t *sc)
          /*
 	  * Allocate a new mbuf cluster to replace the current one
           */
-         MGETHDR(m_new, M_DONTWAIT, MT_DATA);
+         MGETHDR(m_new, M_NOWAIT, MT_DATA);
          if (m_new != NULL) {
-            MCLGET(m_new, M_DONTWAIT);
+            MCLGET(m_new, M_NOWAIT);
             if (m_new->m_flags & M_EXT) {
                m_adj(m_new, ETHER_ALIGN);
             } else {
@@ -1287,7 +1295,11 @@ vxn_rx(vxn_softc_t *sc)
             sc->vxn_rx_buffptr[dd->rxDriverNext] = m_new;
             rre->paddr = (uint32)vtophys(mtod(m_new, caddr_t));
 
+#if __FreeBSD_version >= 1100036
+            if_inc_counter(ifp, IFCOUNTER_IPACKETS, 1);
+#else
             ifp->if_ipackets++;
+#endif
             m->m_pkthdr.rcvif = ifp;
             m->m_pkthdr.len = m->m_len = pkt_len;
 
@@ -1401,10 +1413,10 @@ vxn_init_rings(vxn_softc_t *sc)
        * Allocate an mbuf and initialize it to contain a packet header and
        * internal data.
        */
-      MGETHDR(m_new, M_DONTWAIT, MT_DATA);
+      MGETHDR(m_new, M_NOWAIT, MT_DATA);
       if (m_new != NULL) {
          /* Allocate and attach an mbuf cluster to mbuf. */
-         MCLGET(m_new, M_DONTWAIT);
+         MCLGET(m_new, M_NOWAIT);
          if (m_new->m_flags & M_EXT) {
             m_adj(m_new, ETHER_ALIGN);
             sc->vxn_rx_ring[i].paddr = (uint32)vtophys(mtod(m_new, caddr_t));
