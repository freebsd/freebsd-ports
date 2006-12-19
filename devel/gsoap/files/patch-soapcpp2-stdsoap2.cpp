--- soapcpp2/stdsoap2.cpp.orig	Tue Dec 19 11:28:05 2006
+++ soapcpp2/stdsoap2.cpp	Tue Dec 19 11:37:15 2006
@@ -3335,7 +3335,11 @@
     soap->errnum = h_errno;
   }
 #elif defined(HAVE_GETHOSTBYNAME_R)
+#if defined(__FreeBSD__)
+  gethostbyname_r(addr, &hostent, soap->buf, SOAP_BUFLEN, &host, &soap->errnum);
+#else
   host = gethostbyname_r(addr, &hostent, soap->buf, SOAP_BUFLEN, &soap->errnum);
+#endif
 #elif defined(VXWORKS)
   /* If the DNS resolver library resolvLib has been configured in the vxWorks
    * image, a query for the host IP address is sent to the DNS server, if the
