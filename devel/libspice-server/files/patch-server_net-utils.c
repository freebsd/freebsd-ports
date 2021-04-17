--- server/net-utils.c.orig	2021-04-21 06:31:14 UTC
+++ server/net-utils.c
@@ -48,7 +48,7 @@
 static inline bool
 darwin_einval_on_unix_socket(int fd, int err)
 {
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
     if (err == EINVAL) {
         union {
             struct sockaddr sa;
