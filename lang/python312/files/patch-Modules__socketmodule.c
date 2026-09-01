--- Modules/socketmodule.c
+++ Modules/socketmodule.c
@@ -2656,6 +2656,11 @@
         /* RDS sockets use sockaddr_in: fall-through */
 #endif /* AF_RDS */
 
+#ifdef AF_DIVERT
+    case AF_DIVERT:
+        /* FreeBSD divert(4) sockets use sockaddr_in: fall-through */
+#endif /* AF_DIVERT */
+
     case AF_INET:
     {
         *len_ret = sizeof (struct sockaddr_in);
