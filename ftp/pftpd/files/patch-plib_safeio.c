--- plib/safeio.c.orig	2013-07-04 11:10:49 UTC
+++ plib/safeio.c
@@ -448,7 +448,7 @@
     {
 	int err;
 	
-#if defined(__FreeBSD__) && __FreeBSD__ >= 3
+#if (defined(__FreeBSD__) && __FreeBSD__ >= 3) || defined(__DragonFly__)
 	off_t sbytes;
 	while ((err = sendfile(to_fd, from_fd, *start, len,
 			       NULL, &sbytes, 0)) == -1) {
