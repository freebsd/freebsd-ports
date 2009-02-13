
$FreeBSD$

--- tftpd/tftpd.c.orig
+++ tftpd/tftpd.c
@@ -355,7 +355,10 @@
     p = strrchr(argv[0], '/');
     __progname = (p && p[1]) ? p + 1 : argv[0];
 
-    openlog(__progname, LOG_PID | LOG_NDELAY, LOG_DAEMON);
+    /* syslog in localtime */
+    tzset();
+
+    openlog(__progname, LOG_PID | LOG_NDELAY, LOG_FTP);
 
     srand(time(NULL) ^ getpid());
 
@@ -841,7 +844,7 @@
                        sizeof(bindaddr4.sin_addr));
 #ifdef HAVE_IPV6
             } else if ((from.sa.sa_family == AF_INET6) &&
-              IN6_IS_ADDR_UNSPECIFIED(SOCKADDR_P(&myaddr))) {
+              IN6_IS_ADDR_UNSPECIFIED((struct in6_addr*)SOCKADDR_P(&myaddr))) {
                 memcpy(SOCKADDR_P(&myaddr), &bindaddr6.sin6_addr,
                        sizeof(bindaddr6.sin6_addr));
 #endif
