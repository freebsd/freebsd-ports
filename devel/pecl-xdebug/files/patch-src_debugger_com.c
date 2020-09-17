--- src/debugger/com.c.orig	2020-09-16 14:14:16 UTC
+++ src/debugger/com.c
@@ -87,7 +87,7 @@ static int xdebug_create_socket_unix(const char *path)
 #if !WIN32 && !WINNT
 
 /* For OSX */
-#if !defined(SOL_TCP) && defined(IPPROTO_TCP) && defined(__APPLE__)
+#if !defined(SOL_TCP) && defined(IPPROTO_TCP) && (defined(__APPLE__) || defined(__FreeBSD__))
 # define SOL_TCP IPPROTO_TCP
 #endif
 #if !defined(TCP_KEEPIDLE) && defined(TCP_KEEPALIVE) && defined(__APPLE__)
