--- lib/erl_interface/src/connect/ei_resolve.c.orig	2015-03-31 12:32:52 UTC
+++ lib/erl_interface/src/connect/ei_resolve.c
@@ -649,7 +649,8 @@ struct hostent *ei_gethostbyname_r(const
 
   return result;
 #else
-  return gethostbyname_r(name,hostp,buffer,buflen,h_errnop);
+  struct hostent *dummy;
+  return gethostbyname_r(name,hostp,buffer,buflen,&dummy,h_errnop);
 #endif
 #endif
 #endif
