--- src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c.orig	2024-01-11 12:25:08 UTC
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
@@ -149,6 +151,7 @@ MODULE_DEPEND(ng_vboxnetflt, vboxdrv, 1, 1, 1);
  */
 MODULE_VERSION(vboxnetflt, 1);
 MODULE_DEPEND(ng_vboxnetflt, vboxdrv, 1, 1, 1);
+MODULE_DEPEND(ng_vboxnetflt, ng_ether, 1, 1, 1);
 
 /**
  * The (common) global data.
@@ -181,8 +184,6 @@ static int vboxnetflt_modevent(struct module *pMod, in
                 printf("vboxNetFltInitGlobalsAndIdc failed %d\n", rc);
                 return RTErrConvertToErrno(rc);
             }
-            /* No MODULE_VERSION in ng_ether so we can't MODULE_DEPEND it */
-            kern_kldload(curthread, "ng_ether", NULL);
             break;
 
         case MOD_UNLOAD:
@@ -334,12 +335,20 @@ static int ng_vboxnetflt_rcvdata(hook_p hook, item_p i
 {
     const node_p node = NG_HOOK_NODE(hook);
     PVBOXNETFLTINS pThis = NG_NODE_PRIVATE(node);
+#if __FreeBSD_version >= 1500000
+    if_t ifp = pThis->u.s.ifp;
+#else
     struct ifnet *ifp = pThis->u.s.ifp;
+#endif
     struct mbuf *m;
     struct m_tag *mtag;
     bool fActive;
 
+#if __FreeBSD_version >= 1500000
+    VBOXCURVNET_SET(if_getvnet(ifp));
+#else
     VBOXCURVNET_SET(ifp->if_vnet);
+#endif
     fActive = vboxNetFltTryRetainBusyActive(pThis);
 
     NGI_GET_M(item, m);
@@ -361,7 +370,14 @@ static int ng_vboxnetflt_rcvdata(hook_p hook, item_p i
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
@@ -433,12 +449,22 @@ static void vboxNetFltFreeBSDinput(void *arg, int pend
 {
     PVBOXNETFLTINS pThis = (PVBOXNETFLTINS)arg;
     struct mbuf *m, *m0;
+#if __FreeBSD_version >= 1500000
+    if_t ifp = pThis->u.s.ifp;
+#else
     struct ifnet *ifp = pThis->u.s.ifp;
+#endif
     unsigned int cSegs = 0;
     bool fDropIt = false, fActive;
+    bool is_vl_tagged = false;
+    uint16_t vl_tag;
     PINTNETSG pSG;
 
+#if __FreeBSD_version >= 1500000
+    VBOXCURVNET_SET(if_getvnet(ifp));
+#else
     VBOXCURVNET_SET(ifp->if_vnet);
+#endif
     vboxNetFltRetain(pThis, true /* fBusy */);
     for (;;)
     {
@@ -448,6 +474,19 @@ static void vboxNetFltFreeBSDinput(void *arg, int pend
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
@@ -462,10 +501,39 @@ static void vboxNetFltFreeBSDinput(void *arg, int pend
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
@@ -478,12 +546,20 @@ static void vboxNetFltFreeBSDoutput(void *arg, int pen
 {
     PVBOXNETFLTINS pThis = (PVBOXNETFLTINS)arg;
     struct mbuf *m, *m0;
+#if __FreeBSD_version >= 1500000
+    if_t ifp = pThis->u.s.ifp;
+#else
     struct ifnet *ifp = pThis->u.s.ifp;
+#endif
     unsigned int cSegs = 0;
     bool fDropIt = false, fActive;
     PINTNETSG pSG;
 
+#if __FreeBSD_version >= 1500000
+    VBOXCURVNET_SET(if_getvnet(ifp));
+#else
     VBOXCURVNET_SET(ifp->if_vnet);
+#endif
     vboxNetFltRetain(pThis, true /* fBusy */);
     for (;;)
     {
@@ -521,26 +597,41 @@ int vboxNetFltPortOsXmit(PVBOXNETFLTINS pThis, void *p
  */
 int vboxNetFltPortOsXmit(PVBOXNETFLTINS pThis, void *pvIfData, PINTNETSG pSG, uint32_t fDst)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     NOREF(pvIfData);
 
     void (*input_f)(struct ifnet *, struct mbuf *);
+#if __FreeBSD_version >= 1500000
+    if_t ifp;
+#else
     struct ifnet *ifp;
+#endif
     struct mbuf *m;
     struct m_tag *mtag;
     bool fActive;
     int error;
 
     ifp = ASMAtomicUoReadPtrT(&pThis->u.s.ifp, struct ifnet *);
+#if __FreeBSD_version >= 1500000
+    VBOXCURVNET_SET(if_getvnet(ifp));
+#else
     VBOXCURVNET_SET(ifp->if_vnet);
+#endif
 
     if (fDst & INTNETTRUNKDIR_WIRE)
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
@@ -550,10 +641,16 @@ int vboxNetFltPortOsXmit(PVBOXNETFLTINS pThis, void *p
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
@@ -564,6 +661,7 @@ int vboxNetFltPortOsXmit(PVBOXNETFLTINS pThis, void *p
         if (mtag == NULL)
         {
             m_freem(m);
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return VERR_NO_MEMORY;
         }
 
@@ -571,9 +669,21 @@ int vboxNetFltPortOsXmit(PVBOXNETFLTINS pThis, void *p
         m_tag_prepend(m, mtag);
         m->m_flags |= M_PKTHDR;
         m->m_pkthdr.rcvif = ifp;
+#if __FreeBSD_version >= 1300049
+        struct epoch_tracker et;
+        NET_EPOCH_ENTER(et);
+#endif
+#if __FreeBSD_version >= 1500000
+        if_input(ifp, m);
+#else
         ifp->if_input(ifp, m);
+#endif
+#if __FreeBSD_version >= 1300049
+        NET_EPOCH_EXIT(et);
+#endif
     }
     VBOXCURVNET_RESTORE();
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -586,15 +696,23 @@ int vboxNetFltOsInitInstance(PVBOXNETFLTINS pThis, voi
 
 int vboxNetFltOsInitInstance(PVBOXNETFLTINS pThis, void *pvContext)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     char nam[NG_NODESIZ];
+#if __FreeBSD_version >= 1500000
+    if_t ifp;
+#else
     struct ifnet *ifp;
+#endif
     node_p node;
 
     VBOXCURVNET_SET_FROM_UCRED();
     NOREF(pvContext);
     ifp = ifunit(pThis->szName);
     if (ifp == NULL)
+    {
+        IPRT_FREEBSD_RESTORE_EFL_AC();
         return VERR_INTNET_FLT_IF_NOT_FOUND;
+    }
 
     /* Create a new netgraph node for this instance */
     if (ng_make_node_common(&ng_vboxnetflt_typestruct, &node) != 0)
@@ -604,7 +722,11 @@ int vboxNetFltOsInitInstance(PVBOXNETFLTINS pThis, voi
 
     ASMAtomicUoWritePtr(&pThis->u.s.ifp, ifp);
     pThis->u.s.node = node;
+#if __FreeBSD_version >= 1500000
+    bcopy(if_getlladdr(ifp), &pThis->u.s.MacAddr, ETHER_ADDR_LEN);
+#else
     bcopy(IF_LLADDR(ifp), &pThis->u.s.MacAddr, ETHER_ADDR_LEN);
+#endif
     ASMAtomicUoWriteBool(&pThis->fDisconnectedFromHost, false);
 
     /* Initialize deferred input queue */
@@ -638,16 +760,26 @@ int vboxNetFltOsInitInstance(PVBOXNETFLTINS pThis, voi
         vboxNetFltRelease(pThis, true /*fBusy*/);
     }
     VBOXCURVNET_RESTORE();
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 
     return VINF_SUCCESS;
 }
 
 bool vboxNetFltOsMaybeRediscovered(PVBOXNETFLTINS pThis)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
+#if __FreeBSD_version >= 1500000
+    if_t ifp, ifp0;
+#else
     struct ifnet *ifp, *ifp0;
+#endif
 
     ifp = ASMAtomicUoReadPtrT(&pThis->u.s.ifp, struct ifnet *);
+#if __FreeBSD_version >= 1500000
+    VBOXCURVNET_SET(if_getvnet(ifp));
+#else
     VBOXCURVNET_SET(ifp->if_vnet);
+#endif
     /*
      * Attempt to check if the interface is still there and re-initialize if
      * something has changed.
@@ -660,6 +792,7 @@ bool vboxNetFltOsMaybeRediscovered(PVBOXNETFLTINS pThi
         pThis->u.s.node = NULL;
     }
     VBOXCURVNET_RESTORE();
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 
     if (ifp0 != NULL)
     {
@@ -672,6 +805,7 @@ void vboxNetFltOsDeleteInstance(PVBOXNETFLTINS pThis)
 
 void vboxNetFltOsDeleteInstance(PVBOXNETFLTINS pThis)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
 
     taskqueue_drain(taskqueue_fast, &pThis->u.s.tskin);
     taskqueue_drain(taskqueue_fast, &pThis->u.s.tskout);
@@ -684,6 +818,7 @@ void vboxNetFltOsDeleteInstance(PVBOXNETFLTINS pThis)
         ng_rmnode_self(pThis->u.s.node);
     VBOXCURVNET_RESTORE();
     pThis->u.s.node = NULL;
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 }
 
 int vboxNetFltOsPreInitInstance(PVBOXNETFLTINS pThis)
@@ -697,7 +832,12 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
 
 void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, bool fActive)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
+#if __FreeBSD_version >= 1500000
+    if_t ifp;
+#else
     struct ifnet *ifp;
+#endif
     struct ifreq ifreq;
     int error;
     node_p node;
@@ -709,18 +849,30 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
     Log(("%s: fActive:%d\n", __func__, fActive));
 
     ifp = ASMAtomicUoReadPtrT(&pThis->u.s.ifp, struct ifnet *);
+#if __FreeBSD_version >= 1500000
+    VBOXCURVNET_SET(if_getvnet(ifp));
+#else
     VBOXCURVNET_SET(ifp->if_vnet);
+#endif
     node = ASMAtomicUoReadPtrT(&pThis->u.s.node, node_p);
 
     memset(&ifreq, 0, sizeof(struct ifreq));
     /* Activate interface */
     if (fActive)
     {
+#if __FreeBSD_version >= 1500000
+        pThis->u.s.flags = if_getflags(ifp);
+#else
         pThis->u.s.flags = ifp->if_flags;
+#endif
         ifpromisc(ifp, 1);
 
         /* ng_ether nodes are named after the interface name */
+#if __FreeBSD_version >= 1500000
+        snprintf(path, sizeof(path), "%s:", if_name(ifp));
+#else
         snprintf(path, sizeof(path), "%s:", ifp->if_xname);
+#endif
 
         /*
          * Send a netgraph connect message to the ng_ether node
@@ -730,9 +882,16 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
         NG_MKMESSAGE(msg, NGM_GENERIC_COOKIE, NGM_CONNECT,
             sizeof(struct ngm_connect), M_NOWAIT);
         if (msg == NULL)
+        {
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return;
+        }
         con = (struct ngm_connect *)msg->data;
+#if __FreeBSD_version >= 1500000
+        snprintf(con->path, NG_PATHSIZ, "vboxnetflt_%s:", if_name(ifp));
+#else
         snprintf(con->path, NG_PATHSIZ, "vboxnetflt_%s:", ifp->if_xname);
+#endif
         strlcpy(con->ourhook, "lower", NG_HOOKSIZ);
         strlcpy(con->peerhook, "input", NG_HOOKSIZ);
         NG_SEND_MSG_PATH(error, node, msg, path, 0);
@@ -744,10 +903,17 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
         NG_MKMESSAGE(msg, NGM_GENERIC_COOKIE, NGM_CONNECT,
             sizeof(struct ngm_connect), M_NOWAIT);
         if (msg == NULL)
+        {
+            IPRT_FREEBSD_RESTORE_EFL_AC();
             return;
+        }
         con = (struct ngm_connect *)msg->data;
         snprintf(con->path, NG_PATHSIZ, "vboxnetflt_%s:",
+#if __FreeBSD_version >= 1500000
+            if_name(ifp));
+#else
             ifp->if_xname);
+#endif
         strlcpy(con->ourhook, "upper", sizeof(con->ourhook));
         strlcpy(con->peerhook, "output", sizeof(con->peerhook));
         NG_SEND_MSG_PATH(error, node, msg, path, 0);
@@ -759,7 +925,11 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
         ifpromisc(ifp, 0);
 
         /* Disconnect msgs are addressed to ourself */
+#if __FreeBSD_version >= 1500000
+        snprintf(path, sizeof(path), "vboxnetflt_%s:", if_name(ifp));
+#else
         snprintf(path, sizeof(path), "vboxnetflt_%s:", ifp->if_xname);
+#endif
 
         /*
          * Send a netgraph message to disconnect our 'input' hook
@@ -767,7 +937,10 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
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
@@ -778,12 +951,16 @@ void vboxNetFltPortOsSetActive(PVBOXNETFLTINS pThis, b
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
