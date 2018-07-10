--- src/utdns.c.orig	2013-04-17 08:20:51 UTC
+++ src/utdns.c
@@ -622,7 +622,8 @@ static void usage(const char *argv0)
          "   -4 .......... Bind to IPv4 only instead of IP + IPv6.\n"
          "   -b .......... Background process and log to syslog.\n"
          "   -d .......... Set log level to LOG_DEBUG.\n"
-         "   -p <port> ... Set incoming UDP port number.\n",
+         "   -p <port> ... Set incoming UDP port number.\n"
+         "   -P <port> ... Set destination port number.\n",
          argv0);
 }
 
@@ -642,7 +643,8 @@ int main(int argc, char **argv)
    (void) init_log("stderr", debuglevel);
 #endif
 
-   while ((c = getopt(argc, argv, "4bdhp:")) != -1)
+   int dst_port = 53;
+   while ((c = getopt(argc, argv, "4bdhp:P:")) != -1)
    {
       switch (c)
       {
@@ -665,6 +667,10 @@ int main(int argc, char **argv)
          case 'p':
             udp_port = atoi(optarg);
             break;
+
+	 case 'P':
+	    dst_port = atoi(optarg);
+	    break;
       }
    }
 
@@ -674,10 +680,9 @@ int main(int argc, char **argv)
       exit(EXIT_FAILURE);
    }
 
-   // FIXME: this should not be hardcoded
    memset(&in, 0, sizeof(in));
    in.sin_family = AF_INET;
-   in.sin_port = htons(53);
+   in.sin_port = htons(dst_port);
    if (!inet_aton(argv[optind], &in.sin_addr))
    {
       log_msg(LOG_ERR, "could not convert %s to in_addr\n", argv[optind]);
