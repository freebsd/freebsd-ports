
$FreeBSD$

--- lib/erl_interface/src/connect/ei_resolve.c.orig
+++ lib/erl_interface/src/connect/ei_resolve.c
@@ -621,7 +621,8 @@
 
   return result;
 #else
-  return gethostbyname_r(name,hostp,buffer,buflen,h_errnop);
+  struct hostent *dummy;
+  return gethostbyname_r(name,hostp,buffer,buflen,&dummy,h_errnop);
 #endif
 #endif
 #endif
