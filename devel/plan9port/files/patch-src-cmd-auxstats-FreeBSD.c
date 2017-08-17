--- src/cmd/auxstats/FreeBSD.c.orig	2017-07-23 11:11:56 UTC
+++ src/cmd/auxstats/FreeBSD.c
@@ -8,20 +8,15 @@
 #include <sys/time.h>
 #include <sys/dkstat.h>
 #include <net/if.h>
-#include <net/if_var.h>
 #include <net/if_dl.h>
 #include <net/if_types.h>
-#if __FreeBSD_version < 600000
-#include <machine/apm_bios.h>
-#endif
 #include <sys/ioctl.h>
 #include <limits.h>
 #include <libc.h>
 #include <bio.h>
+#include <ifaddrs.h>
 #include "dat.h"
 
-/* XXX: #if __FreeBSD_version */
-
 void xapm(int);
 void xloadavg(int);
 void xcpu(int);
@@ -45,7 +40,6 @@ void (*statfn[])(int) =
 static kvm_t *kvm;
 
 static struct nlist nl[] = {
-	{ "_ifnet" },
 	{ "_cp_time" },
 	{ "" }
 };
@@ -86,45 +80,28 @@ kread(ulong addr, char *buf, int size)
 void
 xnet(int first)
 {
+	struct ifaddrs *ifap, *ifa;
 	ulong out, in, outb, inb, err;
-	static ulong ifnetaddr;
-	ulong addr;
-	struct ifnet ifnet;
-	struct ifnethead ifnethead;
-	char name[16];
 
 	if(first)
 		return;
 
-	if(ifnetaddr == 0){
-		ifnetaddr = nl[0].n_value;
-		if(ifnetaddr == 0)
-			return;
-	}
-
-	if(kread(ifnetaddr, (char*)&ifnethead, sizeof ifnethead) < 0)
+	if (getifaddrs(&ifap) != 0)
 		return;
 
 	out = in = outb = inb = err = 0;
-	addr = (ulong)TAILQ_FIRST(&ifnethead);
-	while(addr){
-#if __FreeBSD_version < 500000
-		if(kread(addr, (char*)&ifnet, sizeof ifnet) < 0
-		|| kread((ulong)ifnet.if_name, name, 16) < 0)
-			return;
-#else
-		if(kread(addr, (char*)&ifnet, sizeof ifnet) < 0
-		|| kread((ulong)ifnet.if_dname, name, 16) < 0)
-			return;
-#endif
-		name[15] = 0;
-		addr = (ulong)TAILQ_NEXT(&ifnet, if_link);
-		out += ifnet.if_opackets;
-		in += ifnet.if_ipackets;
-		outb += ifnet.if_obytes;
-		inb += ifnet.if_ibytes;
-		err += ifnet.if_oerrors+ifnet.if_ierrors;
+
+#define	IFA_STAT(s)	(((struct if_data *)ifa->ifa_data)->ifi_ ## s)
+	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
+		if (ifa->ifa_addr->sa_family != AF_LINK)
+			continue;
+		out += IFA_STAT(opackets);
+		in += IFA_STAT(ipackets);
+		outb += IFA_STAT(obytes);
+		inb += IFA_STAT(ibytes);
+		err += IFA_STAT(oerrors) + IFA_STAT(ierrors);
 	}
+	freeifaddrs(ifap);
 	Bprint(&bout, "etherin %lud 1000\n", in);
 	Bprint(&bout, "etherout %lud 1000\n", out);
 	Bprint(&bout, "etherinb %lud 1000000\n", inb);
