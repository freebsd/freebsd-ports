diff --git a/dlls/ws2_32/socket.c b/dlls/ws2_32/socket.c
index 0391554..6374ba9 100644
--- dlls/ws2_32/socket.c
+++ dlls/ws2_32/socket.c
@@ -1473,7 +1473,7 @@ static BOOL is_sockaddr_bound(const struct sockaddr *uaddr, int uaddrlen)
         {
             static const struct sockaddr_ipx emptyAddr;
             struct sockaddr_ipx *ipx = (struct sockaddr_ipx*) uaddr;
-            return ipx->sipx_port || ipx->sipx_network || memcmp(&ipx->sipx_node, &emptyAddr.sipx_node, sizeof(emptyAddr.sipx_node));
+            return ipx->sipx_port || ((union ipx_net_u)ipx->sipx_network).long_e || memcmp(&ipx->sipx_node, &emptyAddr.sipx_node, sizeof(emptyAddr.sipx_node));
         }
 #endif
         case AF_INET6:
