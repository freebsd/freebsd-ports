--- src/gpsd.c~	Fri Apr 19 20:26:14 2002
+++ src/gpsd.c	Thu Jun 27 18:02:12 2002
@@ -78,27 +78,31 @@
 int debug = 0;
 int device_speed = B4800;
 int device_type;
+int nfds;  /* number of file descriptors to select() for */
 char *device_name = 0;
 char *latitude = 0;
 char *longitude = 0;
 char latd = 'N';
 char lond = 'W';
-				/* command line option defaults */
-char *default_device_name = "/dev/gps";
-char *default_latitude = "3600.000";
-char *default_longitude = "-12300.000";
-
-int nfds, dsock;
-int verbose = 1;
-int bincount;
 
-int reopen = 0;
+/* command line option defaults */
+static char *default_device_name = "/dev/gps";
+static char *default_latitude = "3600.000";
+static char *default_longitude = "-12300.000";
+
+static int dsock; /* socket to dpgs server */
+
+/* If set, close (and reopen?) the serial interface. Triggered by SIGUSR1. */
+static int reopen = 0;
+
 
 static int handle_input (int input, fd_set * afds, fd_set * nmea_fds);
-extern int handle_EMinput (int input, fd_set * afds, fd_set * nmea_fds);
 static int handle_request (int fd, fd_set * fds);
-int connectsock (char *host, char *service, char *protocol);
-void em_send_rtcm (unsigned short *rtcmbuf, int rtcmbytes);
+
+extern int handle_EMinput (int input, fd_set * afds, fd_set * nmea_fds);
+extern int connectsock (char *host, char *service, char *protocol);
+extern void em_send_rtcm (unsigned short *rtcmbuf, int rtcmbytes);
+
 
 static void
 onsig (int sig)
@@ -164,16 +168,17 @@
   char *default_service = "gpsd";
   char *default_dgpsserver = "dgps.wsrcc.com";
   char *default_dgpsport = "rtcm-sc104";
-  char *service = 0;
+  char *service = 0; /* port number to listen to */
   char *dgpsport = 0;
   char *dgpsserver = 0;
   struct sockaddr_in fsin;
-  int msock;
+  int msock; /* listening socket fd */
   fd_set rfds;
   fd_set afds;
   fd_set nmea_fds;
   int alen;
-  int fd, input;
+  int fd;
+  int input; /* GPS device fd */
   int need_gps, need_dgps = 0, need_init = 1;
   extern char *optarg;
   int option;
@@ -273,17 +278,18 @@
 	default:
 	  fputs ("usage:  gpsd [options] \n\
   options include: \n\
-  -D integer   [ set debug level ] \n\
+  -D level     [ set debug level. If >= 2, remain in foreground ] \n\
   -L longitude [ set longitude ] \n\
-  -S integer   [ set port for daemon ] \n\
-  -T e         [ earthmate flag ] \n\
-  -h           [ help message ] \n\
   -l latitude  [ set latitude ] \n\
-  -p string    [ set gps device name ] \n\
+  -S port      [ set gpsd listening port ] \n\
+  -T type      [ set DeLorme models. e = Earthmate, t = Tripmate ] \n\
+  -h           [ help message ] \n\
+  -p path      [ set gps device pathname ] \n\
   -s baud_rate [ set baud rate on gps device ] \n\
   -c           [ use dgps service for corrections ] \n\
-  -d host      [ set dgps server ] \n\
-  -r port      [ set dgps rtcm-sc104 port ] \n\
+  -d host      [ set dgps server hostname] \n\
+  -r port      [ set dgps server port ] \n\
+  -n           [ disable setting default values for longitute and latitute ] \n\
 ", stderr);
 	  exit (0);
 	}
@@ -354,8 +360,11 @@
 	  need_dgps = 0;
 	}
     }
-
-  nfds = getdtablesize ();
+#ifndef min
+#define min(a, b) (((a) < (b)) ? (a) : (b))
+#endif
+  /* still wrong, but at least do not coredump */
+  nfds = min (getdtablesize (), FD_SETSIZE);
 
   FD_ZERO (&afds);
   FD_ZERO (&nmea_fds);
@@ -375,10 +384,9 @@
 
   while (1)
     {
-      memcpy ((char *) &rfds, (char *) &afds, sizeof (rfds));
+      memcpy (&rfds, &afds, sizeof (rfds));
 
-      if (select (nfds, &rfds, (fd_set *) 0, (fd_set *) 0,
-		  (struct timeval *) 0) < 0)
+      if (select (nfds, &rfds, NULL, NULL, NULL) < 0)
 	{
 	  if (errno == EINTR)
 	    continue;
@@ -599,6 +607,7 @@
 {
   static unsigned char buf[BUFSIZE];	/* that is more then a sentence */
   static int offset = 0;
+  static int bincount;
   int fd;
 
   while (offset < BUFSIZE)
