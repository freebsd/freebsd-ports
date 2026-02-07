--- net/if_arp.c.orig	2009-05-13 21:36:04 UTC
+++ net/if_arp.c
@@ -35,7 +35,6 @@
 #include "structs/type/array.h"
 
 #include "net/if_util.h"
-#include "net/uroute.h"
 #include "util/typed_mem.h"
 
 #define ROUNDUP(a) \
@@ -91,7 +90,11 @@ if_get_arp(struct in_addr ip, u_char *ether)
 	mib[2] = 0;
 	mib[3] = AF_INET;
 	mib[4] = NET_RT_FLAGS;
+#ifdef RTF_LLINFO
 	mib[5] = RTF_LLINFO;
+#else
+	mib[5] = 0;
+#endif
 	if (sysctl(mib, 6, NULL, &needed, NULL, 0) < 0)
 		return (-1);
 	needed += 128;
@@ -194,9 +197,11 @@ tryagain:
 	sdl = (struct sockaddr_dl *)(void *)
 	    (ROUNDUP(sin->sin_len) + (char *)sin);
 	if (sin->sin_addr.s_addr == sin_m.sin_addr.s_addr) {
-		if (sdl->sdl_family == AF_LINK
-		    && (rtm->rtm_flags & (RTF_LLINFO|RTF_GATEWAY))
-		      == RTF_LLINFO) {
+		if (sdl->sdl_family == AF_LINK &&
+#ifdef RTF_LLINFO
+		    (rtm->rtm_flags & RTF_LLINFO) != 0 &&
+#endif
+		    (rtm->rtm_flags & RTF_GATEWAY) == 0) {
 			switch (sdl->sdl_type) {
 			case IFT_ETHER:
 			case IFT_FDDI:
@@ -245,6 +250,7 @@ arp_delete(int sock, struct in_addr ip)
 	struct rt_msghdr *const rtm = &m_rtmsg.m_rtm;
 	struct sockaddr_dl *sdl;
 
+	sdl_m = zero_sdl;
 	sin_m = zero_sin;
 	sin->sin_addr = ip;
 tryagain:
@@ -253,14 +259,15 @@ tryagain:
 	sin = (struct sockaddr_inarp *)(rtm + 1);
 	sdl = (struct sockaddr_dl *)(void *)
 	    (ROUNDUP(sin->sin_len) + (char *)sin);
-	if (sin->sin_addr.s_addr == sin_m.sin_addr.s_addr) {
-		if (sdl->sdl_family == AF_LINK &&
-		    (rtm->rtm_flags & RTF_LLINFO) &&
-		    !(rtm->rtm_flags & RTF_GATEWAY)) switch (sdl->sdl_type) {
+	if (sdl->sdl_family == AF_LINK &&
+#ifdef RTF_LLINFO
+	    (rtm->rtm_flags & RTF_LLINFO) &&
+#endif
+	    !(rtm->rtm_flags & RTF_GATEWAY)) switch (sdl->sdl_type) {
 		case IFT_ETHER: case IFT_FDDI: case IFT_ISO88023:
 		case IFT_ISO88024: case IFT_ISO88025:
+			sin->sin_addr.s_addr = sin_m.sin_addr.s_addr;
 			goto delete;
-		}
 	}
 	if (sin_m.sin_other & SIN_PROXY) {
 		errno = ENOENT;
@@ -351,42 +358,55 @@ int
 if_flush_arp(void)
 {
 	int errno_save = errno;
-	struct uroute **list;
-	int rtn = 0;
-	int num;
-	int i;
+	int mib[6];
+	size_t needed;
+	char *lim, *buf, *next;
+	struct rt_msghdr *rtm;
+	struct sockaddr_inarp *sin;
+	struct sockaddr_dl *sdl;
+	int sock, rtn = -1;
 
-	/* Get list of routes */
-	if ((num = uroute_get_all(&list, TYPED_MEM_TEMP)) == -1)
+	/* Get socket */
+	if ((sock = socket(PF_ROUTE, SOCK_RAW, 0)) == -1)
 		return (-1);
 
-	/* Delete ARP routes */
-	for (i = 0; i < num; i++) {
-		struct uroute *const route = list[i];
-		const struct sockaddr *dest;
-		const struct sockaddr *gw;
+	/* Get ARP table */
+	mib[0] = CTL_NET;
+	mib[1] = PF_ROUTE;
+	mib[2] = 0;
+	mib[3] = AF_INET;
+	mib[4] = NET_RT_FLAGS;
+#ifdef RTF_LLINFO
+	mib[5] = RTF_LLINFO;
+#else
+	mib[5] = 0;
+#endif
+	if (sysctl(mib, 6, NULL, &needed, NULL, 0) < 0)
+		goto done;
+	needed += 128;
+	if ((buf = MALLOC(TYPED_MEM_TEMP, needed)) == NULL)
+		goto done;
+	if (sysctl(mib, 6, buf, &needed, NULL, 0) < 0) {
+		goto done2;
+	}
 
-		/* Is this an ARP entry? */
-		dest = uroute_get_dest(route);
-		gw = uroute_get_gateway(route);
-		if ((uroute_get_flags(route)
-		      & (RTF_HOST|RTF_LLINFO|RTF_WASCLONED))
-		      != (RTF_HOST|RTF_LLINFO|RTF_WASCLONED)
-		    || dest->sa_family != AF_INET
-		    || gw->sa_family != AF_LINK)
-			continue;
-
-		/* Delete it */
-		if (uroute_delete(route) == -1) {
-			errno_save = errno;
-			rtn = -1;
-		}
+	/* Find desired entry */
+	lim = buf + needed;
+	for (next = buf; next < lim; next += rtm->rtm_msglen) {
+		rtm = (struct rt_msghdr *)(void *)next;
+		sin = (struct sockaddr_inarp *)(rtm + 1);
+		sdl = (struct sockaddr_dl *)(void *)
+		   ((char *)sin + ROUNDUP(sin->sin_len));
+		if (sdl->sdl_alen == 0)
+			break;
+		arp_delete(sock, sin->sin_addr);
 	}
 
-	/* Clean up */
-	while (num > 0)
-		uroute_destroy(&list[--num]);
-	FREE(TYPED_MEM_TEMP, list);
+	rtn = 0;
+done2:
+	FREE(TYPED_MEM_TEMP, buf);
+done:
+	(void)close(sock);
 	errno = errno_save;
 	return (rtn);
 }
