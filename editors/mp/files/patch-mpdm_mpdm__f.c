mpdm_f.c:2395:24: error: variable has incomplete type 'struct sockaddr_in'
    struct sockaddr_in host;
                       ^
mpdm_f.c:2395:12: note: forward declaration of 'struct sockaddr_in'
    struct sockaddr_in host;
           ^
mpdm_f.c:2417:23: warning: implicit declaration of function 'htons' is invalid in C99 [-Wimplicit-function-declaration]
    host.sin_port   = htons(p);
                      ^

--- mpdm/mpdm_f.c.orig	2020-11-22 08:58:48 UTC
+++ mpdm/mpdm_f.c
@@ -78,6 +78,8 @@
 #include <sys/file.h>
 #endif
 
+#include <netinet/in.h>
+
 #include "mpdm.h"
 
 #ifdef CONFOPT_ICONV
