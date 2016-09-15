--- src/bsd.c.orig	2005-02-04 10:24:55 UTC
+++ src/bsd.c
@@ -30,6 +30,16 @@
 #error --enable-transparent-data not supported under BSD
 #endif
 
+#ifdef PF
+#include <fcntl.h>
+#include <sys/ioctl.h>
+#include <net/if.h>
+#include <net/pfvar.h>
+
+static int natfd;
+#endif
+
+
 #ifdef IPFILTER
 #include <fcntl.h>
 #include <sys/ioctl.h>
@@ -51,6 +61,11 @@ int os_init(void)
 	if(natfd < 0)
 		write_log(ERROR, "Unable to initialise IPFilter");
 #endif
+#ifdef PF
+       natfd = open("/dev/pf", O_RDWR);
+       if (natfd == -1)
+               write_log(ERROR, "Unable to initialise PF");
+#endif
 	return 0;
 }
 
@@ -61,6 +76,11 @@ int os_init(void)
 int get_orig_dest(int fd, struct sockaddr_in *addr)
 {
 	socklen_t len;
+#ifdef PF
+    struct pfioc_natlook nl;
+    struct sockaddr_in from;
+    int r2;
+#endif
 #ifdef IPFILTER
 	struct natlookup nat;
 	struct sockaddr_in from;
@@ -100,6 +120,31 @@ int get_orig_dest(int fd, struct sockadd
 		return r2;
 	}
 #endif
+#ifdef PF
+       getpeername(fd, (struct sockaddr *) &from, &len);
+       memset(&nl, 0, sizeof(struct pfioc_natlook));
+       memcpy( &nl.daddr.v4, &to.sin_addr.s_addr, sizeof( nl.saddr.v4 ));
+       memcpy( &nl.saddr.v4, &from.sin_addr.s_addr, sizeof( nl.daddr.v4 ));
+       nl.dport = to.sin_port;
+       nl.sport = from.sin_port;
+       nl.af = AF_INET;
+       nl.proto = IPPROTO_TCP;
+       nl.direction = PF_INOUT;
+
+       if ( natfd > 0 ){
+           if (ioctl(natfd, DIOCNATLOOK, &nl)==-1){
+               write_log(ERROR, "Failed to lookup address");
+           }
+           else {
+               memset(addr, sizeof(*addr), 0);
+               memcpy(&addr->sin_addr.s_addr, &nl.rdaddr.v4.s_addr, sizeof(struct sockaddr_in));
+               addr->sin_len = sizeof(struct sockaddr_in);
+               addr->sin_port = nl.rdport;
+               addr->sin_family = AF_INET;
+               return r2;
+		   }
+	   }
+#endif
 	memcpy(addr, &to, len);
 	return r1;
 }
