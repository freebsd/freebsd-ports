--- sredird.c.orig	Wed Dec 28 15:35:00 2005
+++ sredird.c	Wed Dec 28 15:39:43 2005
@@ -110,7 +110,12 @@
 #include <fcntl.h>
 #include <syslog.h>
 #include <termios.h>
+#ifndef __FreeBSD__
 #include <termio.h>
+#else
+#include <netdb.h>
+#include <netinet/in_systm.h>
+#endif
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
@@ -196,6 +201,13 @@
 /* Default modem state polling in milliseconds (100 msec should be enough) */
 #define ModemStatePolling 100
 
+#ifdef __FreeBSD__
+struct tms mytms;
+#define times(NULL) times(&mytms)
+#define SOL_TCP getprotobyname("TCP")->p_proto
+#define SOL_IP getprotobyname("IP")->p_proto
+#endif
+
 /* Standard boolean definition */
 typedef enum { False, True } Boolean;
 
@@ -714,8 +726,10 @@
 					return(115200UL);
 				case B230400:
 					return(230400UL);
+#ifndef __FreeBSD__
 				case B460800:
 					return(460800UL);
+#endif
 				default:
 					return(0UL);
 			}
@@ -1094,9 +1108,11 @@
 				case 230400UL:
 					Speed = B230400;
 				break;
+#ifndef __FreeBSD__
 				case 460800UL:
 					Speed = B460800;
 				break;
+#endif
 				default:
 					LogMsg(LOG_WARNING,"Unknwon baud rate requested, setting to 9600.");
 					Speed = B9600;
