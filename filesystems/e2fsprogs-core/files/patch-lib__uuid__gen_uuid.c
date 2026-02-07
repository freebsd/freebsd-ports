--- lib/uuid/gen_uuid.c.orig	2024-05-21 02:52:47 UTC
+++ lib/uuid/gen_uuid.c
@@ -92,6 +92,7 @@
 #ifdef HAVE_SYS_RESOURCE_H
 #include <sys/resource.h>
 #endif
+#include <ifaddrs.h>
 
 #include "uuidP.h"
 #include "uuidd.h"
@@ -288,6 +289,28 @@ static int get_node_id(unsigned char *node_id)
 		}
 	}
 	close(sd);
+#else
+	struct ifaddrs *ifaddrsp, *ifaddrp;
+	unsigned char 	*a;
+
+	if (getifaddrs(&ifaddrsp) < 0)
+		return -1;
+	for (ifaddrp = ifaddrsp; ifaddrp != NULL; ifaddrp = ifaddrp->ifa_next)
+	{
+		if (ifaddrp->ifa_addr == NULL)
+			continue;
+		if (ifaddrp->ifa_addr->sa_family != AF_LINK)
+			continue;
+		a = LLADDR((struct sockaddr_dl *)ifaddrp->ifa_addr);
+		if (!a[0] && !a[1] && !a[2] && !a[3] && !a[4] && !a[5])
+			continue;
+		if (node_id) {
+			memcpy(node_id, a, 6);
+			freeifaddrs(ifaddrsp);
+			return 1;
+		}
+	}
+	freeifaddrs(ifaddrsp);
 #endif
 	return 0;
 }
@@ -472,7 +495,7 @@ static void close_all_fds(void)
 }
 #endif /* defined(USE_UUIDD) && defined(HAVE_SYS_UN_H) */
 
-#if __GNUC_PREREQ (4, 6)
+#if __GNUC_PREREQ__ (4, 6)
 #pragma GCC diagnostic push
 #if !defined(USE_UUIDD) || !defined(HAVE_SYS_UN_H)
 #pragma GCC diagnostic ignored "-Wunused-parameter"
@@ -560,7 +583,7 @@ fail:
 #endif
 	return -1;
 }
-#if __GNUC_PREREQ (4, 6)
+#if __GNUC_PREREQ__ (4, 6)
 #pragma GCC diagnostic pop
 #endif
 
