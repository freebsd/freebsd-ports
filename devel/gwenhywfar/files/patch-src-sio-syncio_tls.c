--- src/sio/syncio_tls.c.orig	2014-10-12 13:12:22 UTC
+++ src/sio/syncio_tls.c
@@ -361,12 +361,10 @@ int GWEN_SyncIo_Tls_Prepare(GWEN_SYNCIO 
 
   /* possibly force protocol priority */
   if (lflags & GWEN_SYNCIO_TLS_FLAGS_FORCE_SSL_V3) {
-    const int proto_prio[2] = { GNUTLS_SSL3, 0 };
-
     DBG_INFO(GWEN_LOGDOMAIN, "Forcing SSL v3");
-    rv=gnutls_protocol_set_priority(xio->session, proto_prio);
+    rv=gnutls_priority_set_direct(xio->session, "NORMAL:-VERS-TLS-ALL:+VERS-SSL3.0", NULL);
     if (rv) {
-      DBG_ERROR(GWEN_LOGDOMAIN, "gnutls_protocol_set_priority: %d (%s)", rv, gnutls_strerror(rv));
+      DBG_ERROR(GWEN_LOGDOMAIN, "gnutls_priority_set_direct: %d (%s)", rv, gnutls_strerror(rv));
       gnutls_deinit(xio->session);
       return GWEN_ERROR_GENERIC;
     }
