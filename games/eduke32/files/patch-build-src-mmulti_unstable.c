--- build/src/mmulti_unstable.c.orig	2009-02-02 23:21:58.000000000 +0100
+++ build/src/mmulti_unstable.c	2009-02-02 23:27:30.000000000 +0100
@@ -971,7 +971,11 @@
     {
         /* !!! FIXME: Might be Linux (not Unix, not BSD, not WinSock) specific. */
         int32_t flags = 1;
-        setsockopt(udpsocket, SOL_IP, IP_RECVERR, &flags, sizeof(flags));
+        int sol_ip;
+        struct protoent *pent;
+        pent = getprotobyname ("ip");
+        sol_ip = (pent != NULL) ? pent->p_proto : 0;
+        setsockopt(udpsocket, sol_ip, SO_ERROR, &flags, sizeof(flags));
     }
 #endif 
