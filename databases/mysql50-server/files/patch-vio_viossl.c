--- vio/viossl.c.orig	2007-11-15 15:07:13.000000000 +0100
+++ vio/viossl.c	2008-01-21 08:02:45.000000000 +0100
@@ -172,20 +172,14 @@
   vio_delete(vio);
 }
 
-int sslaccept(struct st_VioSSLFd *ptr, Vio *vio, long timeout)
-{
-  DBUG_ENTER("sslaccept");
-  DBUG_RETURN(sslconnect(ptr, vio, timeout));
-}
-
-
-int sslconnect(struct st_VioSSLFd *ptr, Vio *vio, long timeout)
+static
+int sslprocess(struct st_VioSSLFd *ptr, Vio *vio, long timeout, my_bool accept)
 {
   SSL *ssl;
   my_bool unused;
   my_bool was_blocking;
 
-  DBUG_ENTER("sslconnect");
+  DBUG_ENTER("sslprocess");
   DBUG_PRINT("enter", ("ptr: 0x%lx, sd: %d  ctx: 0x%lx",
                        (long) ptr, vio->sd, (long) ptr->ssl_context));
 
@@ -201,6 +195,12 @@
   }
   DBUG_PRINT("info", ("ssl: 0x%lx timeout: %ld", (long) ssl, timeout));
   SSL_clear(ssl);
+
+  if (accept)
+	  SSL_set_accept_state(ssl);
+  else
+	  SSL_set_connect_state(ssl);
+
   SSL_SESSION_set_timeout(SSL_get_session(ssl), timeout);
   SSL_set_fd(ssl, vio->sd);
 
@@ -258,6 +258,17 @@
   DBUG_RETURN(0);
 }
 
+int sslaccept(struct st_VioSSLFd *ptr, Vio *vio, long timeout)
+{
+  DBUG_ENTER("sslaccept");
+  DBUG_RETURN(sslprocess(ptr, vio, timeout, TRUE));
+}
+
+int sslconnect(struct st_VioSSLFd *ptr, Vio *vio, long timeout)
+{
+  DBUG_ENTER("sslconnect");
+  DBUG_RETURN(sslprocess(ptr, vio, timeout, FALSE));
+}
 
 int vio_ssl_blocking(Vio *vio __attribute__((unused)),
 		     my_bool set_blocking_mode,
