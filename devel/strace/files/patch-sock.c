--- sock.c.orig	2007-05-24 14:33:11.000000000 +0800
+++ sock.c	2008-11-21 00:51:02.000000000 +0800
@@ -45,7 +45,9 @@
 #include <ioctls.h>
 #endif
 #endif
+#include <sys/socket.h>
 #include <net/if.h>
+#include <netinet/in.h>
 
 extern const struct xlat addrfams[];
 
@@ -55,16 +57,26 @@
 	{ IFF_DEBUG,		"IFF_DEBUG"		},
 	{ IFF_LOOPBACK,		"IFF_LOOPBACK"		},
 	{ IFF_POINTOPOINT,	"IFF_POINTOPOINT"	},
+#ifdef IFF_NOTRAILERS
 	{ IFF_NOTRAILERS,	"IFF_NOTRAILERS"	},
+#endif
 	{ IFF_RUNNING,		"IFF_RUNNING"		},
 	{ IFF_NOARP,		"IFF_NOARP"		},
 	{ IFF_PROMISC,		"IFF_PROMISC"		},
 	{ IFF_ALLMULTI,		"IFF_ALLMULTI"		},
+#ifdef IFF_MASTER
 	{ IFF_MASTER,		"IFF_MASTER"		},
+#endif
+#ifdef IFF_SLAVE
 	{ IFF_SLAVE,		"IFF_SLAVE"		},
+#endif
 	{ IFF_MULTICAST,	"IFF_MULTICAST"		},
+#ifdef IFF_PORTSEL
 	{ IFF_PORTSEL,		"IFF_PORTSEL"		},
+#endif
+#ifdef IFF_AUTOMEDIA
 	{ IFF_AUTOMEDIA,	"IFF_AUTOMEDIA"		},
+#endif
 	{ 0,			NULL			}
 };
 
