
$FreeBSD$

--- tftpd/tftpd.c.orig
+++ tftpd/tftpd.c
@@ -292,7 +292,7 @@
   p = strrchr(argv[0], '/');
   __progname = (p && p[1]) ? p+1 : argv[0];
   
-  openlog(__progname, LOG_PID|LOG_NDELAY, LOG_DAEMON);
+  openlog(__progname, LOG_PID|LOG_NDELAY, LOG_FTP);
   
   while ((c = getopt(argc, argv, "cspvVla:B:u:U:r:t:T:m:")) != -1)
     switch (c) {
