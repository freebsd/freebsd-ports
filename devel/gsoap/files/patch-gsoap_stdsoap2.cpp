--- gsoap/stdsoap2.cpp.orig	2016-04-03 01:33:31 UTC
+++ gsoap/stdsoap2.cpp
@@ -5396,6 +5396,9 @@ soap_bind(struct soap *soap, const char 
   }
 #endif
 #ifdef TCP_FASTOPEN
+       #ifndef SOL_TCP
+       #define SOL_TCP IPPROTO_TCP
+       #endif
   if (!(soap->omode & SOAP_IO_UDP) && setsockopt(soap->master, IPPROTO_TCP, TCP_FASTOPEN, (char*)&set, sizeof(int)))
   { /* silently ignore */
     DBGLOG(TEST, SOAP_MESSAGE(fdebug, "setsockopt TCP_FASTOPEN failed in soap_bind()\n"));
