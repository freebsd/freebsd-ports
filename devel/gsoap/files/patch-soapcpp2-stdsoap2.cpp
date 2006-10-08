--- soapcpp2/stdsoap2.c.orig	Mon Jun 26 21:36:38 2006
+++ soapcpp2/stdsoap2.cpp	Fri Sep 29 14:22:34 2006
@@ -3282,7 +3282,7 @@
     soap->errnum = h_errno;
   }
 #elif defined(HAVE_GETHOSTBYNAME_R)
-  host = gethostbyname_r(addr, &hostent, soap->buf, SOAP_BUFLEN, &soap->errnum);
+  gethostbyname_r(addr, &hostent, soap->buf, SOAP_BUFLEN, &host, &soap->errnum);
 #elif defined(VXWORKS)
   /* If the DNS resolver library resolvLib has been configured in the vxWorks
    * image, a query for the host IP address is sent to the DNS server, if the
@@ -3755,7 +3755,7 @@
             X509V3_EXT_METHOD *meth = X509V3_EXT_get(ext);
             if (!meth)
               break;
-            val = meth->i2v(meth, meth->d2i(NULL, (unsigned char**)&ext->value->data, ext->value->length), NULL);
+            val = meth->i2v(meth, meth->d2i(NULL, (%%CONST%% unsigned char**)&ext->value->data, ext->value->length), NULL);
             for (j = 0; j < sk_CONF_VALUE_num(val); j++)
             { CONF_VALUE *nval = sk_CONF_VALUE_value(val, j);
               if (nval && !strcmp(nval->name, "DNS") && !strcmp(nval->value, host))
@@ -7616,7 +7616,7 @@
         break;
     }
     if (!tp)
-    { tp = (struct soap_attribute*)SOAP_MALLOC(soap, sizeof(struct soap_attribute) + strlen(soap->tmpbuf));
+    { tp = (struct soap_attribute*)SOAP_MALLOC(soap, sizeof(struct soap_attribute) + strlen(soap->tmpbuf) + 1);
       if (!tp)
         return soap->error = SOAP_EOM;
       strcpy(tp->name, soap->tmpbuf);
