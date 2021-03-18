--- src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c.orig	2021-01-07 15:41:28 UTC
+++ src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c
@@ -52,6 +52,7 @@
 #include <net/if_dl.h>
 #include <net/if_types.h>
 #include <net/ethernet.h>
+#include <net/if_vlan_var.h>
 
 #include <netgraph/ng_message.h>
 #include <netgraph/netgraph.h>
@@ -73,6 +74,7 @@
 
 #define VBOXNETFLT_OS_SPECFIC 1
 #include "../VBoxNetFltInternal.h"
+#include "freebsd/the-freebsd-kernel.h"
 
 static int vboxnetflt_modevent(struct module *, int, void *);
 static ng_constructor_t    ng_vboxnetflt_constructor;
@@ -361,7 +363,14 @@ static int ng_vboxnetflt_rcvdata(hook_p hook, item_p i
     {
         if (mtag != NULL || !fActive)
         {
+#if __FreeBSD_version >= 1300049
+            struct epoch_tracker et;
+            NET_EPOCH_ENTER(et);
+#endif
             ether_demux(ifp, m);
+#if __FreeBSD_version >= 1300049
+            NET_EPOCH_EXIT(et);
+#endif
             if (fActive)
                 vboxNetFltRelease(pThis, true /*fBusy*/);
             VBOXCURVNET_RESTORE();
@@ -436,6 +445,8 @@ static void vboxNetFltFreeBSDinput(void *arg, int pend
     struct ifnet *ifp = pThis->u.s.ifp;
     unsigned int cSegs = 0;
     bool fDropIt = false, fActive;
+    bool is_vl_tagged = false;
+    uint16_t vl_tag;
     PINTNETSG pSG;
 
     VBOXCURVNET_SET(ifp->if_vnet);
@@ -448,6 +459,19 @@ static void vboxNetFltFreeBSDinput(void *arg, int pend
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
@@ -462,10 +486,39 @@ static void vboxNetFltFreeBSDinput(void *arg, int pend
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
-        else
+        else {
+#if __FreeBSD_version >= 1300049
+            struct epoch_tracker et;
+            NET_EPOCH_ENTER(et);
+#endif
             ether_demux(ifp, m);
+#if __FreeBSD_version >= 1300049
+            NET_EPOCH_EXIT(et);
+#endif
+        }
     }
     vboxNetFltRelease(pThis, true /* fBusy */);
     VBOXCURVNET_RESTORE();
@@ -521,6 +574,7 @@ static void vboxNetFltFreeBSDoutput(void *arg, int pen
  */
 int vboxNetFltPortOsXmit(PVBOXNETFLTINS pThis, void *pvIfData, PINTNETSG pSG, uint32_t fDst)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     NOREF(pvIfData);
 
     void (*input_f)(struct ifnet *, struct mbuf *);
@@ -537,10 +591,16 @@ int vboxNetFltPortOsXmit(PVBOXNETFLTINS pThis, void *p
     {
         m = vboxNetFltFreeBSDSGMBufFromSG(pThis, pSG);
         if (m == NULL)
+        {
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return VERR_NO_MEMORY;
+        }
         m = m_pullup(m, ETHER_HDR_LEN);
         if (m == NULL)
+        {
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return VERR_NO_MEMORY;
+        }
 
         m->m_flags |= M_PKTHDR;
         ether_output_frame(ifp, m);
@@ -550,10 +610,16 @@ int vboxNetFltPortOsXmit(PVBOXNETFLTINS pThis, void *p
     {
         m = vboxNetFltFreeBSDSGMBufFromSG(pThis, pSG);
         if (m == NULL)
+        {
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return VERR_NO_MEMORY;
+        }
         m = m_pullup(m, ETHER_HDR_LEN);
         if (m == NULL)
+        {
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return VERR_NO_MEMORY;
+        }
         /*
          * Delivering packets to the host will be captured by the
          * input hook. Tag the packet with a mbuf tag so that we
@@ -564,6 +630,7 @@ int vboxNetFltPortOsXmit(PVBOXNETFLTINS pThis, void *p
         if (mtag == NULL)
         {
             m_freem(m);
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return VERR_NO_MEMORY;
         }
 
@@ -574,6 +641,7 @@ int vboxNetFltPortOsXmit(PVBOXNETFLTINS pThis, void *p
         ifp->if_input(ifp, m);
     }
     VBOXCURVNET_RESTORE();
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -586,6 +654,7 @@ static bool vboxNetFltFreeBsdIsPromiscuous(PVBOXNETFLT
 
 int vboxNetFltOsInitInstance(PVBOXNETFLTINS pThis, void *pvContext)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     char nam[NG_NODESIZ];
     struct ifnet *ifp;
     node_p node;
@@ -594,7 +663,10 @@ int vboxNetFltOsInitInstance(PVBOXNETFLTINS pThis, voi
     NOREF(pvContext);
     ifp = ifunit(pThis->szName);
     if (ifp == NULL)
+    {
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return VERR_INTNET_FLT_IF_NOT_FOUND;
+    }
 
     /* Create a new netgraph node for this instance */
     if (ng_make_node_common(&ng_vboxnetflt_typestruct, &node) != 0)
@@ -638,12 +710,14 @@ int vboxNetFltOsInitInstance(PVBOXNETFLTINS pThis, voi
         vboxNetFltRelease(pThis, true /*fBusy*/);
     }
     VBOXCURVNET_RESTORE();
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 
     return VINF_SUCCESS;
 }
 
 bool vboxNetFltOsMaybeRediscovered(PVBOXNETFLTINS pThis)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     struct ifnet *ifp, *ifp0;
 
     ifp = ASMAtomicUoReadPtrT(&pThis->u.s.ifp, struct ifnet *);
@@ -660,6 +734,7 @@ bool vboxNetFltOsMaybeRediscovered(PVBOXNETFLTINS pThi
         pThis->u.s.node = NULL;
     }
     VBOXCURVNET_RESTORE();
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 
     if (ifp0 != NULL)
     {
@@ -672,6 +747,7 @@ bool vboxNetFltOsMaybeRediscovered(PVBOXNETFLTINS pThi
 
 void vboxNetFltOsDeleteInstance(PVBOXNETFLTINS pThis)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
 
     taskqueue_drain(taskqueue_fast, &pThis->u.s.tskin);
     taskqueue_drain(taskqueue_fast, &pThis->u.s.tskout);
@@ -684,6 +760,7 @@ void vboxNetFltOsDeleteInstance(PVBOXNETFLTINS pThis)
         ng_rmnode_self(pThis->u.s.node);
     VBOXCURVNET_RESTORE();
     pThis->u.s.node = NULL;
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 }
 
 int vboxNetFltOsPreInitInstance(PVBOXNETFLTINS pThis)
@@ -697,6 +774,7 @@ int vboxNetFltOsPreInitInstance(PVBOXNETFLTINS pThis)
 
 void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, bool fActive)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     struct ifnet *ifp;
     struct ifreq ifreq;
     int error;
@@ -730,7 +808,10 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
         NG_MKMESSAGE(msg, NGM_GENERIC_COOKIE, NGM_CONNECT,
             sizeof(struct ngm_connect), M_NOWAIT);
         if (msg == NULL)
+        {
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return;
+        }
         con = (struct ngm_connect *)msg->data;
         snprintf(con->path, NG_PATHSIZ, "vboxnetflt_%s:", ifp->if_xname);
         strlcpy(con->ourhook, "lower", NG_HOOKSIZ);
@@ -744,7 +825,10 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
         NG_MKMESSAGE(msg, NGM_GENERIC_COOKIE, NGM_CONNECT,
             sizeof(struct ngm_connect), M_NOWAIT);
         if (msg == NULL)
+        {
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return;
+        }
         con = (struct ngm_connect *)msg->data;
         snprintf(con->path, NG_PATHSIZ, "vboxnetflt_%s:",
             ifp->if_xname);
@@ -767,7 +851,10 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
         NG_MKMESSAGE(msg, NGM_GENERIC_COOKIE, NGM_RMHOOK,
             sizeof(struct ngm_rmhook), M_NOWAIT);
         if (msg == NULL)
+        {
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return;
+        }
         rm = (struct ngm_rmhook *)msg->data;
         strlcpy(rm->ourhook, "input", NG_HOOKSIZ);
         NG_SEND_MSG_PATH(error, node, msg, path, 0);
@@ -778,12 +865,16 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
         NG_MKMESSAGE(msg, NGM_GENERIC_COOKIE, NGM_RMHOOK,
             sizeof(struct ngm_rmhook), M_NOWAIT);
         if (msg == NULL)
+        {
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return;
+        }
         rm = (struct ngm_rmhook *)msg->data;
         strlcpy(rm->ourhook, "output", NG_HOOKSIZ);
         NG_SEND_MSG_PATH(error, node, msg, path, 0);
     }
     VBOXCURVNET_RESTORE();
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 }
 
 int vboxNetFltOsDisconnectIt(PVBOXNETFLTINS pThis)
