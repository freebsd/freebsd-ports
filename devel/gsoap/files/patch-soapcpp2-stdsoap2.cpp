--- soapcpp2/stdsoap2.cpp.orig	Sat May 20 00:33:35 2006
+++ soapcpp2/stdsoap2.cpp	Sat May 20 00:58:56 2006
@@ -3251,7 +3251,7 @@
     soap->errnum = h_errno;
   }
 #elif defined(HAVE_GETHOSTBYNAME_R)
-  host = gethostbyname_r(addr, &hostent, soap->buf, SOAP_BUFLEN, &soap->errnum);
+  gethostbyname_r(addr, &hostent, soap->buf, SOAP_BUFLEN, &host, &soap->errnum);
 #elif defined(VXWORKS)
   /* If the DNS resolver library resolvLib has been configured in the vxWorks
    * image, a query for the host IP address is sent to the DNS server, if the
