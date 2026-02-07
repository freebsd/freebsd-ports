--- src/modbus-tcp.c.orig	2025-07-03 21:07:28 UTC
+++ src/modbus-tcp.c
@@ -257,7 +257,7 @@ static int _modbus_tcp_set_ipv4_options(int s)
 #endif
 #endif
 
-#ifndef OS_WIN32
+#if !defined(OS_WIN32) && !defined(__FreeBSD__)
     /**
      * Cygwin defines IPTOS_LOWDELAY but can't handle that flag so it's
      * necessary to workaround that problem.
