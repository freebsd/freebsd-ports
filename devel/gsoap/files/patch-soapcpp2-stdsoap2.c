--- soapcpp2/stdsoap2.c.orig	Tue Dec 19 11:28:08 2006
+++ soapcpp2/stdsoap2.c	Tue Dec 19 11:36:34 2006
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
