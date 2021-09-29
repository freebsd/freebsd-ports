--- gsoap/stdsoap2.c.orig	2019-02-10 15:19:37 UTC
+++ gsoap/stdsoap2.c
@@ -4473,10 +4473,12 @@ ssl_auth_init(struct soap *soap)
     minv = TLS1_1_VERSION;
   else if ((soap->ssl_flags & SOAP_TLSv1_2))
     minv = TLS1_2_VERSION;
+#ifdef TLS1_3_VERSION
   else if ((soap->ssl_flags & SOAP_TLSv1_3))
     minv = TLS1_3_VERSION;
   if ((soap->ssl_flags & SOAP_TLSv1_3) && OpenSSL_version_num() >= 0x10101000L)
     maxv = TLS1_3_VERSION;
+#endif
   else if ((soap->ssl_flags & SOAP_TLSv1_2))
     maxv = TLS1_2_VERSION;
   else if ((soap->ssl_flags & SOAP_TLSv1_1))
@@ -6714,6 +6716,9 @@ soap_bind(struct soap *soap, const char *host, int por
   }
 #endif
 #ifdef TCP_FASTOPEN
+       #ifndef SOL_TCP
+       #define SOL_TCP IPPROTO_TCP
+       #endif
   if (!(soap->omode & SOAP_IO_UDP) && setsockopt(soap->master, IPPROTO_TCP, TCP_FASTOPEN, (char*)&set, sizeof(int)))
   {
     /* silently ignore */
