--- src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c.orig	2020-07-28 21:59:30.107638000 -0700
+++ src/VBox/HostDrivers/VBoxNetFlt/freebsd/VBoxNetFlt-freebsd.c	2020-07-28 22:00:37.858885000 -0700
@@ -361,7 +361,14 @@
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
@@ -457,7 +464,16 @@
         if (fDropIt)
             m_freem(m);
         else
+        {
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
