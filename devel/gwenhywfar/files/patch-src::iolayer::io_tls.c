# $FreeBSD$
--- src/iolayer/io_tls.c.orig	2009-06-18 13:56:27.000000000 -0700
+++ src/iolayer/io_tls.c	2009-07-12 09:56:45.000000000 -0700
@@ -310,6 +310,7 @@
   if (lflags & GWEN_IO_LAYER_TLS_FLAGS_FORCE_SSL_V3) {
     const int proto_prio[2] = { GNUTLS_SSL3, 0 };
 
+    DBG_INFO(GWEN_LOGDOMAIN, "Forcing SSL v3");
     rv=gnutls_protocol_set_priority(xio->session, proto_prio);
     if (rv) {
       DBG_ERROR(GWEN_LOGDOMAIN, "gnutls_protocol_set_priority: %d (%s)", rv, gnutls_strerror(rv));
@@ -840,7 +841,7 @@
 
   rv=GWEN_Io_LayerCodec_CheckWriteOut(io);
   if (rv) {
-    if (rv==GWEN_ERROR_TRY_AGAIN) {
+    if (rv==GWEN_ERROR_TRY_AGAIN || rv==GWEN_ERROR_IN_PROGRESS) {
       DBG_INFO(GWEN_LOGDOMAIN, "here (%d)", rv);
 #ifdef HAVE_GNUTLS_TRANSPORT_SET_ERRNO
       gnutls_transport_set_errno(xio->session, EAGAIN);
