--- tftpd/tftpd.c.orig	2011-12-11 22:13:52 UTC
+++ tftpd/tftpd.c
@@ -76,7 +76,7 @@ static int ai_fam = AF_INET;
 #define TRIES   6               /* Number of attempts to send each packet */
 #define TIMEOUT_LIMIT ((1 << TRIES)-1)
 
-const char *__progname;
+extern const char *__progname;
 static int peer;
 static unsigned long timeout  = TIMEOUT;        /* Current timeout value */
 static unsigned long rexmtval = TIMEOUT;       /* Basic timeout value */
@@ -389,7 +389,8 @@ int main(int argc, char **argv)
     p = strrchr(argv[0], '/');
     __progname = (p && p[1]) ? p + 1 : argv[0];
 
-    openlog(__progname, LOG_PID | LOG_NDELAY, LOG_DAEMON);
+    tzset();
+    openlog(__progname, LOG_PID | LOG_NDELAY, LOG_FTP);
 
     srand(time(NULL) ^ getpid());
 
@@ -938,7 +939,8 @@ int main(int argc, char **argv)
        syslog daemon gets restarted by the time we get here. */
     if (secure && standalone) {
         closelog();
-        openlog(__progname, LOG_PID | LOG_NDELAY, LOG_DAEMON);
+        tzset();
+	openlog(__progname, LOG_PID | LOG_NDELAY, LOG_FTP);
     }
 
 #ifdef HAVE_TCPWRAPPERS
