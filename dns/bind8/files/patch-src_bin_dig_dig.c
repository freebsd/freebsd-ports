--- src/bin/dig/dig.c.Dist	Mon Jun 17 19:26:49 2002
+++ src/bin/dig/dig.c	Sun Nov 17 01:34:37 2002
@@ -1799,7 +1799,7 @@
 		in6->s6_addr[6] & 0x0f, (in6->s6_addr[6] >> 4) & 0x0f,
 		in6->s6_addr[5] & 0x0f, (in6->s6_addr[5] >> 4) & 0x0f,
 		in6->s6_addr[4] & 0x0f, (in6->s6_addr[4] >> 4) & 0x0f,
-		in6->s6_addr[6] & 0x0f, (in6->s6_addr[3] >> 4) & 0x0f,
+		in6->s6_addr[3] & 0x0f, (in6->s6_addr[3] >> 4) & 0x0f,
 		in6->s6_addr[2] & 0x0f, (in6->s6_addr[2] >> 4) & 0x0f,
 		in6->s6_addr[1] & 0x0f, (in6->s6_addr[1] >> 4) & 0x0f,
 		in6->s6_addr[0] & 0x0f, (in6->s6_addr[0] >> 4) & 0x0f);
