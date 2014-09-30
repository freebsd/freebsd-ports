--- src/VBox/HostDrivers/VBoxNetAdp/freebsd/VBoxNetAdp-freebsd.c.orig	2014-09-09 15:54:30.000000000 -0400
+++ src/VBox/HostDrivers/VBoxNetAdp/freebsd/VBoxNetAdp-freebsd.c	2014-09-30 15:36:06.000000000 -0400
@@ -234,7 +234,11 @@
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
