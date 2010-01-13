Index: src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c
===================================================================
--- src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c	(revision 23391)
+++ src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c	(working copy)
@@ -122,7 +122,7 @@
     .cmdlist =    ng_vboxnetflt_cmdlist,
 };
 NETGRAPH_INIT(vboxnetflt, &ng_vboxnetflt_typestruct);
-MODULE_VERSION(ng_vboxnetflt, 1);
+MODULE_VERSION(vboxnetflt, 1);
 MODULE_DEPEND(ng_vboxnetflt, vboxdrv, 1, 1, 1);
 
 /**
@@ -418,7 +418,7 @@
         /* Create a copy and deliver to the virtual switch */
         pSG = RTMemTmpAlloc(RT_OFFSETOF(INTNETSG, aSegs[cSegs]));
         vboxNetFltFreeBSDMBufToSG(pThis, m, pSG, cSegs, 0);
-        fDropIt = pThis->pSwitchPort->pfnRecv(pThis->pSwitchPort, pSG, INTNETTRUNKDIR_HOST);
+        fDropIt = pThis->pSwitchPort->pfnRecv(pThis->pSwitchPort, pSG, INTNETTRUNKDIR_WIRE);
         RTMemTmpFree(pSG);
         if (fDropIt)
             m_freem(m);
