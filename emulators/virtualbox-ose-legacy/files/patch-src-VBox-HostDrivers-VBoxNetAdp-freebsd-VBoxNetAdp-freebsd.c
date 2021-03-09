--- src/VBox/HostDrivers/VBoxNetAdp/freebsd/VBoxNetAdp-freebsd.c.orig	2020-05-13 19:43:54 UTC
+++ src/VBox/HostDrivers/VBoxNetAdp/freebsd/VBoxNetAdp-freebsd.c
@@ -235,7 +235,11 @@ static void VBoxNetAdpFreeBSDNetstart(struct ifnet *if
     ifp->if_drv_flags |= IFF_DRV_OACTIVE;
     while (!IFQ_DRV_IS_EMPTY(&ifp->if_snd))
     {
+#if __FreeBSD_version >= 1100036
+        if_inc_counter(ifp, IFCOUNTER_OPACKETS, 1);
+#else
         ifp->if_opackets++;
+#endif
         IFQ_DRV_DEQUEUE(&ifp->if_snd, m);
         BPF_MTAP(ifp, m);
         m_freem(m);
