--- src/nss.c.orig	2008-10-06 23:16:19.000000000 +0100
+++ src/nss.c	2008-10-07 22:15:07.000000000 +0100
@@ -23,6 +23,7 @@
 #include <config.h>
 #endif
 
+#include <netinet/in.h>
 #include <unistd.h>
 #include <errno.h>
 #include <string.h>
@@ -39,27 +40,7 @@
 #include "avahi.h"
 #endif
 
-#if defined(NSS_IPV4_ONLY) && ! defined(MDNS_MINIMAL)
-#define _nss_mdns_gethostbyname2_r _nss_mdns4_gethostbyname2_r
-#define _nss_mdns_gethostbyname_r  _nss_mdns4_gethostbyname_r
-#define _nss_mdns_gethostbyaddr_r  _nss_mdns4_gethostbyaddr_r
-#elif defined(NSS_IPV4_ONLY) && defined(MDNS_MINIMAL)
-#define _nss_mdns_gethostbyname2_r _nss_mdns4_minimal_gethostbyname2_r
-#define _nss_mdns_gethostbyname_r  _nss_mdns4_minimal_gethostbyname_r
-#define _nss_mdns_gethostbyaddr_r  _nss_mdns4_minimal_gethostbyaddr_r
-#elif defined(NSS_IPV6_ONLY) && ! defined(MDNS_MINIMAL)
-#define _nss_mdns_gethostbyname2_r _nss_mdns6_gethostbyname2_r
-#define _nss_mdns_gethostbyname_r  _nss_mdns6_gethostbyname_r
-#define _nss_mdns_gethostbyaddr_r  _nss_mdns6_gethostbyaddr_r
-#elif defined(NSS_IPV6_ONLY) && defined(MDNS_MINIMAL)
-#define _nss_mdns_gethostbyname2_r _nss_mdns6_minimal_gethostbyname2_r
-#define _nss_mdns_gethostbyname_r  _nss_mdns6_minimal_gethostbyname_r
-#define _nss_mdns_gethostbyaddr_r  _nss_mdns6_minimal_gethostbyaddr_r
-#elif defined(MDNS_MINIMAL)
-#define _nss_mdns_gethostbyname2_r _nss_mdns_minimal_gethostbyname2_r
-#define _nss_mdns_gethostbyname_r  _nss_mdns_minimal_gethostbyname_r
-#define _nss_mdns_gethostbyaddr_r  _nss_mdns_minimal_gethostbyaddr_r
-#endif
+#include "nss_gethostname_select.h"
 
 /* Maximum number of entries to return */
 #define MAX_ENTRIES 16
