Add VLAN trunking support to vboxnetflt

See:		http://lists.freebsd.org/pipermail/freebsd-emulation/2012-April/009698.html
See:		http://lists.freebsd.org/pipermail/freebsd-emulation/2013-May/010605.html
Submitted by:	Landon J Fuller <landonf at plausible.coop>
--- src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c.orig	2016-01-19 19:18:38 UTC
+++ src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c
@@ -51,6 +51,7 @@
 #include <net/if_dl.h>
 #include <net/if_types.h>
 #include <net/ethernet.h>
+#include <net/if_vlan_var.h>
 
 #include <netgraph/ng_message.h>
 #include <netgraph/netgraph.h>
@@ -369,7 +370,11 @@ static int ng_vboxnetflt_rcvdata(hook_p 
         mtx_lock_spin(&pThis->u.s.inq.ifq_mtx);
         _IF_ENQUEUE(&pThis->u.s.inq, m);
         mtx_unlock_spin(&pThis->u.s.inq.ifq_mtx);
+#if __FreeBSD_version >= 1100100
+        taskqueue_enqueue(taskqueue_fast, &pThis->u.s.tskin);
+#else
         taskqueue_enqueue_fast(taskqueue_fast, &pThis->u.s.tskin);
+#endif
     }
     /*
      * Handle mbufs on the outgoing hook, frames going to the interface
@@ -387,7 +392,11 @@ static int ng_vboxnetflt_rcvdata(hook_p 
         mtx_lock_spin(&pThis->u.s.outq.ifq_mtx);
         _IF_ENQUEUE(&pThis->u.s.outq, m);
         mtx_unlock_spin(&pThis->u.s.outq.ifq_mtx);
+#if __FreeBSD_version >= 1100100
+        taskqueue_enqueue(taskqueue_fast, &pThis->u.s.tskout);
+#else
         taskqueue_enqueue_fast(taskqueue_fast, &pThis->u.s.tskout);
+#endif
     }
     else
     {
@@ -427,6 +436,8 @@ static void vboxNetFltFreeBSDinput(void 
     struct ifnet *ifp = pThis->u.s.ifp;
     unsigned int cSegs = 0;
     bool fDropIt = false, fActive;
+    bool is_vl_tagged = false;
+    uint16_t vl_tag;
     PINTNETSG pSG;
 
     VBOXCURVNET_SET(ifp->if_vnet);
@@ -439,6 +450,19 @@ static void vboxNetFltFreeBSDinput(void 
         if (m == NULL)
             break;
 
+        /* Prepend a VLAN header for consumption by the virtual switch */
+        if (m->m_flags & M_VLANTAG) {
+            vl_tag = m->m_pkthdr.ether_vtag;
+            is_vl_tagged = true;
+
+            m = ether_vlanencap(m, m->m_pkthdr.ether_vtag);
+            if (m == NULL) {
+                printf("vboxflt: unable to prepend VLAN header\n");
+                break;
+            }
+            m->m_flags &= ~M_VLANTAG;
+        }
+
         for (m0 = m; m0 != NULL; m0 = m0->m_next)
             if (m0->m_len > 0)
                 cSegs++;
@@ -453,6 +477,27 @@ static void vboxNetFltFreeBSDinput(void 
         vboxNetFltFreeBSDMBufToSG(pThis, m, pSG, cSegs, 0);
         fDropIt = pThis->pSwitchPort->pfnRecv(pThis->pSwitchPort, NULL /* pvIf */, pSG, INTNETTRUNKDIR_WIRE);
         RTMemTmpFree(pSG);
+
+        /* Restore the VLAN flags before re-injecting the packet */
+        if (is_vl_tagged && !fDropIt) {
+            struct ether_vlan_header *vl_hdr;
+
+            /* This shouldn't fail, as the header was just prepended */
+            if (m->m_len < sizeof(*vl_hdr) && (m = m_pullup(m, sizeof(*vl_hdr))) == NULL) {
+                printf("vboxflt: unable to pullup VLAN header\n");
+                m_freem(m);
+                break;
+            }
+
+            /* Copy the MAC dhost/shost over the 802.1q field */
+            vl_hdr = mtod(m, struct ether_vlan_header *);
+            bcopy((char *)vl_hdr, (char *)vl_hdr + ETHER_VLAN_ENCAP_LEN, ETHER_HDR_LEN - ETHER_TYPE_LEN);
+            m_adj(m, ETHER_VLAN_ENCAP_LEN);
+
+            m->m_pkthdr.ether_vtag = vl_tag;
+            m->m_flags |= M_VLANTAG;
+        }
+
         if (fDropIt)
             m_freem(m);
         else
