--- src/VBox/HostDrivers/VBoxNetAdp/freebsd/VBoxNetAdp-freebsd.c.orig	2024-01-11 12:25:08 UTC
+++ src/VBox/HostDrivers/VBoxNetAdp/freebsd/VBoxNetAdp-freebsd.c
@@ -216,7 +216,11 @@ static void VBoxNetAdpFreeBSDNetinit(void *priv)
     PVBOXNETADP pThis = priv;
     struct ifnet *ifp = pThis->u.s.ifp;
 
+#if __FreeBSD_version >= 1500000
+    if_setdrvflagbits(ifp, IFF_DRV_RUNNING, 0);
+#else
     ifp->if_drv_flags |= IFF_DRV_RUNNING;
+#endif
 }
 
 /**
@@ -226,25 +230,46 @@ static void VBoxNetAdpFreeBSDNetstart(struct ifnet *if
  */
 static void VBoxNetAdpFreeBSDNetstart(struct ifnet *ifp)
 {
+#if __FreeBSD_version >= 1500000
+    PVBOXNETADP pThis = if_getsoftc(ifp);
+#else
     PVBOXNETADP pThis = ifp->if_softc;
+#endif
     struct mbuf *m;
 
+#if __FreeBSD_version >= 1500000
+    if ((if_getdrvflags(ifp) & (IFF_DRV_RUNNING | IFF_DRV_OACTIVE)) != IFF_DRV_RUNNING)
+#else
     if ((ifp->if_drv_flags & (IFF_DRV_RUNNING | IFF_DRV_OACTIVE)) != IFF_DRV_RUNNING)
+#endif
         return;
 
+#if __FreeBSD_version >= 1500000
+    if_setdrvflagbits(ifp, IFF_DRV_OACTIVE, 0);
+    while (!if_sendq_empty(ifp))
+#else
     ifp->if_drv_flags |= IFF_DRV_OACTIVE;
     while (!IFQ_DRV_IS_EMPTY(&ifp->if_snd))
+#endif
     {
 #if __FreeBSD_version >= 1100036
         if_inc_counter(ifp, IFCOUNTER_OPACKETS, 1);
 #else
         ifp->if_opackets++;
 #endif
+#if __FreeBSD_version >= 1500000
+        m = if_dequeue(ifp);
+#else
         IFQ_DRV_DEQUEUE(&ifp->if_snd, m);
+#endif
         BPF_MTAP(ifp, m);
         m_freem(m);
     }
+#if __FreeBSD_version >= 1500000
+    if_setdrvflagbits(ifp, 0, IFF_DRV_OACTIVE);
+#else
     ifp->if_drv_flags &= ~IFF_DRV_OACTIVE;
+#endif
 }
 
 /**
@@ -257,6 +282,18 @@ static int VBoxNetAdpFreeBSDNetioctl(struct ifnet *ifp
     switch (cmd)
     {
         case SIOCSIFFLAGS:
+#if __FreeBSD_version >= 1500000
+            if (if_getflags(ifp) & IFF_UP)
+            {
+                if (!(if_getdrvflags(ifp) & IFF_DRV_RUNNING))
+                    if_init(ifp, if_getsoftc(ifp));
+            }
+            else
+            {
+                if (if_getdrvflags(ifp) & IFF_DRV_RUNNING)
+                    if_setdrvflagbits(ifp, 0, IFF_DRV_RUNNING);
+            }
+#else
             if (ifp->if_flags & IFF_UP)
             {
                 if (!(ifp->if_drv_flags & IFF_DRV_RUNNING))
@@ -267,6 +304,7 @@ static int VBoxNetAdpFreeBSDNetioctl(struct ifnet *ifp
                 if (ifp->if_drv_flags & IFF_DRV_RUNNING)
                     ifp->if_drv_flags &= ~IFF_DRV_RUNNING;
             }
+#endif
             break;
         case SIOCGIFMEDIA:
         {
@@ -301,7 +339,11 @@ int vboxNetAdpOsCreate(PVBOXNETADP pThis, PCRTMAC pMac
 
 int vboxNetAdpOsCreate(PVBOXNETADP pThis, PCRTMAC pMac)
 {
+#if __FreeBSD_version >= 1500000
+    if_t ifp;
+#else
     struct ifnet *ifp;
+#endif
 
     VBOXCURVNET_SET_FROM_UCRED();
     ifp = if_alloc(IFT_ETHER);
@@ -309,6 +351,16 @@ int vboxNetAdpOsCreate(PVBOXNETADP pThis, PCRTMAC pMac
         return VERR_NO_MEMORY;
 
     if_initname(ifp, VBOXNETADP_NAME, pThis->iUnit);
+#if __FreeBSD_version >= 1500000
+    if_setsoftc(ifp, pThis);
+    if_setmtu(ifp, ETHERMTU);
+    if_setflagbits(ifp, IFF_BROADCAST | IFF_SIMPLEX | IFF_MULTICAST, 0);
+    if_setioctlfn(ifp, VBoxNetAdpFreeBSDNetioctl);
+    if_setstartfn(ifp, VBoxNetAdpFreeBSDNetstart);
+    if_setinitfn(ifp, VBoxNetAdpFreeBSDNetinit);
+    if_setsendqlen(ifp, IFQ_MAXLEN);
+    if_setsendqready(ifp);
+#else
     ifp->if_softc = pThis;
     ifp->if_mtu = ETHERMTU;
     ifp->if_flags = IFF_BROADCAST | IFF_SIMPLEX | IFF_MULTICAST;
@@ -318,10 +370,17 @@ int vboxNetAdpOsCreate(PVBOXNETADP pThis, PCRTMAC pMac
     IFQ_SET_MAXLEN(&ifp->if_snd, IFQ_MAXLEN);
     ifp->if_snd.ifq_drv_maxlen = IFQ_MAXLEN;
     IFQ_SET_READY(&ifp->if_snd);
+#endif
     ether_ifattach(ifp, (void *)pMac);
+#if __FreeBSD_version >= 1500000
+    (void)if_setbaudrate(ifp, 0);
+
+    strncpy(pThis->szName, if_name(ifp), VBOXNETADP_MAX_NAME_LEN);
+#else
     ifp->if_baudrate = 0;
 
     strncpy(pThis->szName, ifp->if_xname, VBOXNETADP_MAX_NAME_LEN);
+#endif
     pThis->u.s.ifp = ifp;
     VBOXCURVNET_RESTORE();
     return 0;
@@ -332,7 +391,11 @@ void vboxNetAdpOsDestroy(PVBOXNETADP pThis)
     struct ifnet *ifp;
 
     ifp = pThis->u.s.ifp;
+#if __FreeBSD_version >= 1500000
+    VBOXCURVNET_SET(if_getvnet(ifp));
+#else
     VBOXCURVNET_SET(ifp->if_vnet);
+#endif
     ether_ifdetach(ifp);
     if_free(ifp);
     VBOXCURVNET_RESTORE();
