--- ./modules/freebsd/vmxnet/if_vxn.c.orig	2013-09-23 15:51:10.000000000 +0000
+++ ./modules/freebsd/vmxnet/if_vxn.c	2014-04-23 15:36:44.347844739 +0000
@@ -76,6 +76,10 @@
 #include <pci/pcivar.h>
 #endif
 
+#if __FreeBSD_version >= 1100001
+#include <net/if_var.h>
+#endif
+
 /* define INLINE the way gcc likes it */
 #define INLINE __inline__
 
@@ -936,14 +940,14 @@
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
@@ -1266,9 +1270,9 @@
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
@@ -1401,10 +1405,10 @@
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
