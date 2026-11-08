--- libdrizzle-1.0/libdrizzle/conn.c.orig	2026-11-06 18:16:56 UTC
+++ libdrizzle-1.0/libdrizzle/conn.c
@@ -1329,21 +1329,26 @@ static drizzle_return_t _con_setsockopt(drizzle_con_st
   struct linger linger;
   struct timeval waittime;
 
-  ret= 1;
+  /* A unix domain socket knows nothing of TCP_NODELAY and answers with
+     EINVAL, which used to fail the whole connection. */
+  if (con->socket_type == DRIZZLE_CON_SOCKET_TCP)
+  {
+    ret= 1;
 
 #ifdef _WIN32
-  ret= setsockopt(con->fd, IPPROTO_TCP, TCP_NODELAY, (const char*)&ret,
-                  (socklen_t)sizeof(int));
+    ret= setsockopt(con->fd, IPPROTO_TCP, TCP_NODELAY, (const char*)&ret,
+                    (socklen_t)sizeof(int));
 #else
-  ret= setsockopt(con->fd, IPPROTO_TCP, TCP_NODELAY, &ret,
-                  (socklen_t)sizeof(int));
+    ret= setsockopt(con->fd, IPPROTO_TCP, TCP_NODELAY, &ret,
+                    (socklen_t)sizeof(int));
 #endif /* _WIN32 */
 
-  if (ret == -1 && errno != EOPNOTSUPP)
-  {
-    drizzle_set_error(con->drizzle, "_con_setsockopt",
-                      "setsockopt:TCP_NODELAY:%d", errno);
-    return DRIZZLE_RETURN_ERRNO;
+    if (ret == -1 && errno != EOPNOTSUPP)
+    {
+      drizzle_set_error(con->drizzle, "_con_setsockopt",
+                        "setsockopt:TCP_NODELAY:%d", errno);
+      return DRIZZLE_RETURN_ERRNO;
+    }
   }
 
   linger.l_onoff= 1;
