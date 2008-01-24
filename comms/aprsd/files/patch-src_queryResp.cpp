--- src/queryResp.cpp.orig	2003-03-30 23:49:40.000000000 -0500
+++ src/queryResp.cpp	2008-01-23 22:12:30.000000000 -0500
@@ -40,6 +40,9 @@
 
 #include <netinet/in.h>
 #include <arpa/inet.h>
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
 
 #include "constant.h"
 #include "utils.h"
@@ -84,7 +87,6 @@
     if ((rc = gethostname(hostname,80)) != 0)
         strcpy(hostname, "Host_Unknown");
     else {
-
         //Thread-Safe verison of gethostbyname()
         h = NULL;
         rc = gethostbyname_r(hostname,
@@ -94,12 +96,10 @@
                                 &h,
                                 &h_err);
 
-
-
         if ((rc == 0) && (h!= NULL)) {
             strncpy(hostname,h->h_name,80);            //Copy Full host name
             hostname[79] = '\0';                      //Be sure it's terminated
-            strncpy((char*)hip,h->h_addr_list[0],4);   //Copy Host IP
+            memcpy((void*)hip,(void*)h->h_addr_list[0],4);   //Copy Host IP
         }
     }
 
