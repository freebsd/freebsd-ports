
$FreeBSD$

--- mono/io-layer/sockets.c.orig
+++ mono/io-layer/sockets.c
@@ -1290,13 +1290,13 @@
 			keepalivetime /= 1000;
 			if (keepalivetime == 0 || rem >= 500)
 				keepalivetime++;
-			ret = setsockopt (fd, SOL_TCP, TCP_KEEPIDLE, &keepalivetime, sizeof (uint32_t));
+			ret = setsockopt (fd, 6, TCP_KEEPIDLE, &keepalivetime, sizeof (uint32_t));
 			if (ret == 0) {
 				rem = keepaliveinterval % 1000;
 				keepaliveinterval /= 1000;
 				if (keepaliveinterval == 0 || rem >= 500)
 					keepaliveinterval++;
-				ret = setsockopt (fd, SOL_TCP, TCP_KEEPINTVL, &keepaliveinterval, sizeof (uint32_t));
+				ret = setsockopt (fd, 6, TCP_KEEPINTVL, &keepaliveinterval, sizeof (uint32_t));
 			}
 			if (ret != 0) {
 				gint errnum = errno;
