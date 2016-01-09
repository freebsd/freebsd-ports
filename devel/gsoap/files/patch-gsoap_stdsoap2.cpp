--- gsoap/stdsoap2.cpp.orig	2016-01-01 16:24:55 UTC
+++ gsoap/stdsoap2.cpp
@@ -5194,6 +5194,10 @@ soap_bind(struct soap *soap, const char 
   }
 #endif
 #ifdef TCP_FASTOPEN
+  	#ifndef SOL_TCP
+  	#define SOL_TCP IPPROTO_TCP
+  	#endif
+
   if (!(soap->omode & SOAP_IO_UDP) && setsockopt(soap->master, SOL_TCP, TCP_FASTOPEN, (char*)&set, sizeof(int)))
   { soap->errnum = soap_socket_errno(soap->master);
     soap_set_receiver_error(soap, tcp_error(soap), "setsockopt TCP_FASTOPEN failed in soap_bind()", SOAP_TCP_ERROR);
