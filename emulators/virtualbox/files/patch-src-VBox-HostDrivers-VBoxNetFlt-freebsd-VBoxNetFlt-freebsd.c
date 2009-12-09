Index: src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c
===================================================================
--- src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c	(revision 23391)
+++ src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c	(working copy)
@@ -43,6 +43,8 @@
 #include <sys/socket.h>
 #include <sys/sockio.h>
 #include <sys/syscallsubr.h>
+#include <sys/queue.h>
+#include <sys/taskqueue.h>
 
 #include <net/if.h>
 #include <net/if_var.h>
@@ -78,8 +80,6 @@
 static ng_rcvdata_t    ng_vboxnetflt_rcvdata;
 static ng_disconnect_t    ng_vboxnetflt_disconnect;
 static int        ng_vboxnetflt_mod_event(module_t mod, int event, void *data);
-static int        ng_vboxnetflt_rcv_in(hook_p node, item_p item);
-static int        ng_vboxnetflt_rcv_out(hook_p node, item_p item);
 
 /** Netgraph node type */
 #define NG_VBOXNETFLT_NODE_TYPE    "vboxnetflt"
@@ -112,8 +112,8 @@
 {
     .version =    NG_ABI_VERSION,
     .name =        NG_VBOXNETFLT_NODE_TYPE,
-    .mod_event =    vboxnetflt_modevent,    
-    .constructor =    ng_vboxnetflt_constructor,    
+    .mod_event =    vboxnetflt_modevent,
+    .constructor =    ng_vboxnetflt_constructor,
     .rcvmsg =     ng_vboxnetflt_rcvmsg,
     .shutdown =    ng_vboxnetflt_shutdown,
     .newhook =    ng_vboxnetflt_newhook,
@@ -122,7 +122,7 @@
     .cmdlist =    ng_vboxnetflt_cmdlist,
 };
 NETGRAPH_INIT(vboxnetflt, &ng_vboxnetflt_typestruct);
-MODULE_VERSION(ng_vboxnetflt, 1);
+MODULE_VERSION(vboxnetflt, 1);
 MODULE_DEPEND(ng_vboxnetflt, vboxdrv, 1, 1, 1);
 
 /**
@@ -267,16 +267,12 @@
     if (strcmp(name, NG_VBOXNETFLT_HOOK_IN) == 0)
     {
 #if __FreeBSD_version >= 800000
-        NG_HOOK_SET_RCVDATA(hook, ng_vboxnetflt_rcv_in);
         NG_HOOK_SET_TO_INBOUND(hook);
 #endif
         pThis->u.s.input = hook;
     }
     else if (strcmp(name, NG_VBOXNETFLT_HOOK_OUT) == 0)
     {
-#if __FreeBSD_version >= 800000
-        NG_HOOK_SET_RCVDATA(hook, ng_vboxnetflt_rcv_out);
-#endif
         pThis->u.s.output = hook;
     }
     else
@@ -310,161 +306,171 @@
 
 /**
  * Handle data on netgraph hooks.
+ * Frames processing is deferred to a taskqueue because this might
+ * be called with non-sleepable locks held and code paths inside
+ * the virtual switch might sleep.
  */
 static int ng_vboxnetflt_rcvdata(hook_p hook, item_p item)
 {
     const node_p node = NG_HOOK_NODE(hook);
     PVBOXNETFLTINS pThis = NG_NODE_PRIVATE(node);
+    struct ifnet *ifp = pThis->u.s.ifp;
     struct mbuf *m;
+    struct m_tag *mtag;
+    bool fActive;
 
+    fActive = ASMAtomicUoReadBool(&pThis->fActive);
+
+    NGI_GET_M(item, m);
+    NG_FREE_ITEM(item);
+
+    /* Locate tag to see if processing should be skipped for this frame */
+    mtag = m_tag_locate(m, MTAG_VBOX, PACKET_TAG_VBOX, NULL);
+    if (mtag != NULL)
+    {
+        m_tag_unlink(m, mtag);
+        m_tag_free(mtag);
+    }
+
+    /*
+     * Handle incoming hook. This is connected to the
+     * input path of the interface, thus handling incoming frames.
+     */
     if (pThis->u.s.input == hook)
-        return ng_vboxnetflt_rcv_in(hook, item);
+    {
+        if (mtag != NULL || !fActive)
+        {
+            ether_demux(ifp, m);
+            return (0);
+        }
+        mtx_lock_spin(&pThis->u.s.inq.ifq_mtx);
+        _IF_ENQUEUE(&pThis->u.s.inq, m);
+        mtx_unlock_spin(&pThis->u.s.inq.ifq_mtx);
+        taskqueue_enqueue_fast(taskqueue_fast, &pThis->u.s.tskin);
+    }
+    /**
+     * Handle mbufs on the outgoing hook, frames going to the interface
+     */
     else if (pThis->u.s.output == hook)
-        return ng_vboxnetflt_rcv_out(hook, item);
+    {
+        if (mtag != NULL || !fActive)
+            return ether_output_frame(ifp, m);
+        mtx_lock_spin(&pThis->u.s.outq.ifq_mtx);
+        _IF_ENQUEUE(&pThis->u.s.outq, m);
+        mtx_unlock_spin(&pThis->u.s.outq.ifq_mtx);
+        taskqueue_enqueue_fast(taskqueue_fast, &pThis->u.s.tskout);
+    }
     else
     {
-        NGI_GET_M(item, m);
-        NG_FREE_ITEM(item);
+        m_freem(m);
     }
     return (0);
 }
 
+static int ng_vboxnetflt_shutdown(node_p node)
+{
+    PVBOXNETFLTINS pThis = NG_NODE_PRIVATE(node);
+    bool fActive;
+
+    /* Prevent node shutdown if we're active */
+    fActive = ASMAtomicUoReadBool(&pThis->fActive);
+    if (fActive)
+        return (EBUSY);
+    NG_NODE_UNREF(node);
+    return (0);
+}
+
+static int ng_vboxnetflt_disconnect(hook_p hook)
+{
+    return (0);
+}
+
 /**
- * Handle incoming hook. This is connected to the
- * input path of the interface, thus handling incoming frames.
+ * Input processing task, handles incoming frames
  */
-static int ng_vboxnetflt_rcv_in(hook_p hook, item_p item)
+static void vboxNetFltFreeBSDinput(void *arg, int pending)
 {
+    PVBOXNETFLTINS pThis = (PVBOXNETFLTINS)arg;
     struct mbuf *m, *m0;
-    struct m_tag *mtag;
-    const node_p node = NG_HOOK_NODE(hook);
-    PVBOXNETFLTINS pThis = NG_NODE_PRIVATE(node);
     struct ifnet *ifp = pThis->u.s.ifp;
-    bool fActive, fDropIt = false;
     unsigned int cSegs = 0;
+    bool fDropIt = false, fActive;
     PINTNETSG pSG;
 
-    NGI_GET_M(item, m);
-    NG_FREE_ITEM(item);
-
-    fActive = ASMAtomicUoReadBool(&pThis->fActive);
-    if (!fActive)
-        goto out;
-
-    mtag = m_tag_locate(m, MTAG_VBOX, PACKET_TAG_VBOX, NULL);
-    if (mtag != NULL)
-    {
-        m_tag_unlink(m, mtag);
-        m_tag_free(mtag);
-        goto out;
-    }
     vboxNetFltRetain(pThis, true /* fBusy */);
-
-    for (m0 = m; m0 != NULL; m0 = m0->m_next)
+    for (;;)
     {
-        if (m0->m_len > 0)
-            cSegs++;
-    }
+        mtx_lock_spin(&pThis->u.s.inq.ifq_mtx);
+        _IF_DEQUEUE(&pThis->u.s.inq, m);
+        mtx_unlock_spin(&pThis->u.s.inq.ifq_mtx);
+        if (m == NULL)
+            break;
 
+        for (m0 = m; m0 != NULL; m0 = m0->m_next)
+            if (m0->m_len > 0)
+                cSegs++;
+
 #ifdef PADD_RUNT_FRAMES_FROM_HOST
-    if (m_length(m, NULL) < 60)
-        cSegs++;
+        if (m_length(m, NULL) < 60)
+            cSegs++;
 #endif
 
-    /* Create a copy of the mbuf and hand it to the virtual switch */
-    pSG = RTMemTmpAlloc(RT_OFFSETOF(INTNETSG, aSegs[cSegs]));
-    vboxNetFltFreeBSDMBufToSG(pThis, m, pSG, cSegs, 0);
-    fDropIt = pThis->pSwitchPort->pfnRecv(pThis->pSwitchPort, pSG, INTNETTRUNKDIR_WIRE);
-    RTMemTmpFree(pSG);
+        /* Create a copy and deliver to the virtual switch */
+        pSG = RTMemTmpAlloc(RT_OFFSETOF(INTNETSG, aSegs[cSegs]));
+        vboxNetFltFreeBSDMBufToSG(pThis, m, pSG, cSegs, 0);
+        fDropIt = pThis->pSwitchPort->pfnRecv(pThis->pSwitchPort, pSG, INTNETTRUNKDIR_HOST);
+        RTMemTmpFree(pSG);
+        if (fDropIt)
+            m_freem(m);
+        else
+            ether_demux(ifp, m);
+    }
     vboxNetFltRelease(pThis, true /* fBusy */);
-
-out:
-    /* Only deliver it to the host stack if the destination weren't a guest */
-    if (fDropIt)
-    {
-        m_freem(m);
-        return (0);
-    }
-    ether_demux(ifp, m);
-    return (0);
 }
 
 /**
- * Handle mbufs on the outgoing hook, frames going to the interface
+ * Output processing task, handles outgoing frames
  */
-static int ng_vboxnetflt_rcv_out(hook_p hook, item_p item)
+static void vboxNetFltFreeBSDoutput(void *arg, int pending)
 {
+    PVBOXNETFLTINS pThis = (PVBOXNETFLTINS)arg;
     struct mbuf *m, *m0;
-    struct m_tag *mtag;
-    const node_p node = NG_HOOK_NODE(hook);
-    PVBOXNETFLTINS pThis = NG_NODE_PRIVATE(node);
     struct ifnet *ifp = pThis->u.s.ifp;
     unsigned int cSegs = 0;
     bool fDropIt = false, fActive;
     PINTNETSG pSG;
 
-    NGI_GET_M(item, m);
-    NG_FREE_ITEM(item);
-
-    fActive = ASMAtomicUoReadBool(&pThis->fActive);
-    if (!fActive)
-        return ether_output_frame(ifp, m);
-
     vboxNetFltRetain(pThis, true /* fBusy */);
-    /* Pass directly to interface if the packet originated from us */
-    mtag = m_tag_locate(m, MTAG_VBOX, PACKET_TAG_VBOX, NULL);
-    if (mtag != NULL)
+    for (;;)
     {
-        m_tag_unlink(m, mtag);
-        m_tag_free(mtag);
-        goto out;
-    }
+        mtx_lock_spin(&pThis->u.s.outq.ifq_mtx);
+        _IF_DEQUEUE(&pThis->u.s.outq, m);
+        mtx_unlock_spin(&pThis->u.s.outq.ifq_mtx);
+        if (m == NULL)
+            break;
 
-    for (m0 = m; m0 != NULL; m0 = m0->m_next)
-    {
-        if (m0->m_len > 0)
-            cSegs++;
-    }
+        for (m0 = m; m0 != NULL; m0 = m0->m_next)
+            if (m0->m_len > 0)
+                cSegs++;
 
 #ifdef PADD_RUNT_FRAMES_FROM_HOST
-    if (m_length(m, NULL) < 60)
-        cSegs++;
+        if (m_length(m, NULL) < 60)
+            cSegs++;
 #endif
-    /* Create a copy and deliver to the virtual switch */
-    pSG = RTMemTmpAlloc(RT_OFFSETOF(INTNETSG, aSegs[cSegs]));
-    vboxNetFltFreeBSDMBufToSG(pThis, m, pSG, cSegs, 0);
-    fDropIt = pThis->pSwitchPort->pfnRecv(pThis->pSwitchPort, pSG, INTNETTRUNKDIR_HOST);
-    RTMemTmpFree(pSG);
+        /* Create a copy and deliver to the virtual switch */
+        pSG = RTMemTmpAlloc(RT_OFFSETOF(INTNETSG, aSegs[cSegs]));
+        vboxNetFltFreeBSDMBufToSG(pThis, m, pSG, cSegs, 0);
+        fDropIt = pThis->pSwitchPort->pfnRecv(pThis->pSwitchPort, pSG, INTNETTRUNKDIR_HOST);
+        RTMemTmpFree(pSG);
 
-out:
+        if (fDropIt)
+            m_freem(m);
+        else
+            ether_output_frame(ifp, m);
+    }
     vboxNetFltRelease(pThis, true /* fBusy */);
-    if (fDropIt)
-    {
-        m_freem(m);
-        return (0);
-    }
-
-    return ether_output_frame(ifp, m);
 }
 
-static int ng_vboxnetflt_shutdown(node_p node)
-{
-    PVBOXNETFLTINS pThis = NG_NODE_PRIVATE(node);
-    bool fActive;
-
-    /* Prevent node shutdown if we're active */
-    fActive = ASMAtomicUoReadBool(&pThis->fActive);
-    if (fActive)
-        return (EBUSY);
-    NG_NODE_UNREF(node);
-    return (0);
-}
-
-static int ng_vboxnetflt_disconnect(hook_p hook)
-{
-    return (0);
-}
-
 /**
  * Called to deliver a frame to either the host, the wire or both.
  */
@@ -536,13 +542,23 @@
 
     /* Create a new netgraph node for this instance */
     if (ng_make_node_common(&ng_vboxnetflt_typestruct, &node) != 0)
-        return VERR_INTERNAL_ERROR;        
+        return VERR_INTERNAL_ERROR;
 
     RTSpinlockAcquire(pThis->hSpinlock, &Tmp);
     ASMAtomicUoWritePtr((void * volatile *)&pThis->u.s.ifp, ifp);
     pThis->u.s.node = node;
     bcopy(IF_LLADDR(ifp), &pThis->u.s.Mac, ETHER_ADDR_LEN);
     ASMAtomicUoWriteBool(&pThis->fDisconnectedFromHost, false);
+    /* Initialize deferred input queue */
+    bzero(&pThis->u.s.inq, sizeof(struct ifqueue));
+    mtx_init(&pThis->u.s.inq.ifq_mtx, "vboxnetflt inq", NULL, MTX_SPIN);
+    TASK_INIT(&pThis->u.s.tskin, 0, vboxNetFltFreeBSDinput, pThis);
+
+    /* Initialize deferred output queue */
+    bzero(&pThis->u.s.outq, sizeof(struct ifqueue));
+    mtx_init(&pThis->u.s.outq.ifq_mtx, "vboxnetflt outq", NULL, MTX_SPIN);
+    TASK_INIT(&pThis->u.s.tskout, 0, vboxNetFltFreeBSDoutput, pThis);
+
     RTSpinlockRelease(pThis->hSpinlock, &Tmp);
 
     NG_NODE_SET_PRIVATE(node, pThis);
@@ -571,7 +587,10 @@
     }
 
     if (ifp0 != NULL)
+    {
+        vboxNetFltOsDeleteInstance(pThis);
         vboxNetFltOsInitInstance(pThis, NULL);
+    }
 
     return !ASMAtomicUoReadBool(&pThis->fDisconnectedFromHost);
 }
@@ -579,6 +598,12 @@
 void vboxNetFltOsDeleteInstance(PVBOXNETFLTINS pThis)
 {
 
+    taskqueue_drain(taskqueue_fast, &pThis->u.s.tskin);
+    taskqueue_drain(taskqueue_fast, &pThis->u.s.tskout);
+
+    mtx_destroy(&pThis->u.s.inq.ifq_mtx);
+    mtx_destroy(&pThis->u.s.outq.ifq_mtx);
+
     if (pThis->u.s.node != NULL)
         ng_rmnode_self(pThis->u.s.node);
     pThis->u.s.node = NULL;
