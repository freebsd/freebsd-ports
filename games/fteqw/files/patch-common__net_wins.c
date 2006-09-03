--- common/net_wins.c.orig	Sun Sep  3 00:25:08 2006
+++ common/net_wins.c	Sun Sep  3 00:26:44 2006
@@ -23,6 +23,8 @@
 #include "quakedef.h"
 #include "netinc.h"
 
+#include <sys/time.h>
+
 netadr_t	net_local_cl_ipadr;
 netadr_t	net_local_cl_ip6adr;
 netadr_t	net_local_cl_ipxadr;
