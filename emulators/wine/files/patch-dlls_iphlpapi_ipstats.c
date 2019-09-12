This has been merged upstream in Wine 4.15 (in a slightly tweaked manner),
so we should be able to drop it latest with the next major release.

--- UTC
--- dlls/iphlpapi/ipstats.c.orig	2017-03-21 00:03:25.304042000 -0700
+++ dlls/iphlpapi/ipstats.c	2017-03-21 00:09:42.312023000 -0700
@@ -2233,6 +2233,15 @@
              pXIG->xig_len > sizeof (struct xinpgen);
              pXIG = (struct xinpgen *)((char *)pXIG + pXIG->xig_len))
         {
+#if __FreeBSD_version >= 1200026
+            struct xtcpcb *pTCPData;
+            struct xinpcb *pINData;
+            struct xsocket *pSockData;
+
+            pTCPData = (struct xtcpcb *)pXIG;
+            pINData = &pTCPData->xt_inp;
+            pSockData = &pINData->xi_socket;
+#else
             struct tcpcb *pTCPData = NULL;
             struct inpcb *pINData;
             struct xsocket *pSockData;
@@ -2240,6 +2249,7 @@
             pTCPData = &((struct xtcpcb *)pXIG)->xt_tp;
             pINData = &((struct xtcpcb *)pXIG)->xt_inp;
             pSockData = &((struct xtcpcb *)pXIG)->xt_socket;
+#endif
 
             /* Ignore sockets for other protocols */
             if (pSockData->xso_protocol != IPPROTO_TCP)
@@ -2509,11 +2519,19 @@
              pXIG->xig_len > sizeof (struct xinpgen);
              pXIG = (struct xinpgen *)((char *)pXIG + pXIG->xig_len))
         {
+#if __FreeBSD_version >= 1200026
+            struct xinpcb *pINData;
+            struct xsocket *pSockData;
+
+            pINData = (struct xinpcb *)pXIG;
+            pSockData = &pINData->xi_socket;
+#else
             struct inpcb *pINData;
             struct xsocket *pSockData;
 
             pINData = &((struct xinpcb *)pXIG)->xi_inp;
             pSockData = &((struct xinpcb *)pXIG)->xi_socket;
+#endif
 
             /* Ignore sockets for other protocols */
             if (pSockData->xso_protocol != IPPROTO_UDP)
