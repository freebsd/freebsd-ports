--- UTC
--- dlls/iphlpapi/ipstats.c.orig	2017-03-03 12:18:32.000000000 -0800
+++ dlls/iphlpapi/ipstats.c	2017-03-21 00:43:27.101175000 -0700
@@ -2235,6 +2235,15 @@
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
@@ -2242,6 +2251,7 @@
             pTCPData = &((struct xtcpcb *)pXIG)->xt_tp;
             pINData = &((struct xtcpcb *)pXIG)->xt_inp;
             pSockData = &((struct xtcpcb *)pXIG)->xt_socket;
+#endif
 
             /* Ignore sockets for other protocols */
             if (pSockData->xso_protocol != IPPROTO_TCP)
@@ -2511,11 +2521,19 @@
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
