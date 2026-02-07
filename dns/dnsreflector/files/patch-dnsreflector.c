--- dnsreflector.c.orig	2009-05-30 14:02:43.000000000 +0300
+++ dnsreflector.c	2009-05-30 14:04:31.000000000 +0300
@@ -87,8 +87,7 @@
 
 #define MAXQUERY (PACKETSZ - sizeof(ADDITIONAL) - sizeof(AUTHORITY) - sizeof(ANSWER_AAAA))
 
-static struct syslog_data sdata = SYSLOG_DATA_INIT;
-
+static int daemonize = 0;
 static void
 logit(int level, const char *fmt, ...)
 {
@@ -97,8 +96,8 @@
 
 	va_start(ap, fmt);
 
-	if (sdata.opened) {
-		vsyslog_r(level, &sdata, fmt, ap);
+	if (daemonize) {
+		vsyslog(level, fmt, ap);
 	} else {
 		fprintf(stderr, "%s: ", __progname);
 		vfprintf(stderr, fmt, ap);
@@ -148,7 +147,6 @@
 
 	/* Options and their defaults */
 	char *address = NULL;
-	int daemonize = 0;
 	int port = 53000;
 
 	/* Process commandline arguments */
@@ -186,8 +184,6 @@
 	/* Use syslog if daemonized */
 	if (daemonize) {
 		tzset();
-		openlog_r("dnsreflector", LOG_PID | LOG_NDELAY, LOG_DAEMON,
-		    &sdata);
 	}
 
 	/* Daemonize if requested */
