--- log.c.orig	2009-03-05 00:05:59.000000000 +0100
+++ log.c	2011-04-22 13:41:48.193968412 +0200
@@ -160 +160 @@
-	if (getnameinfo(sa, SA_LEN(sa), buf, sizeof(buf), NULL, 0,
+	if (getnameinfo(sa, 0, buf, sizeof(buf), NULL, 0,
