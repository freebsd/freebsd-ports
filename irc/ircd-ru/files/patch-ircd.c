--- src/ircd.c.orig	10 Jun 2003 06:40:53 -0000	1.1.1.5.2.21
+++ src/ircd.c	24 Jul 2003 07:33:40 -0000
@@ -666,6 +666,14 @@
 
 FILE *dumpfp=NULL;
 
+static void prefix_path(char *dst, const char *path)
+{
+    if (path[0] == '/')
+	strlcpy(dst, path, MAXPATHLEN);
+    else
+	snprintf(dst, MAXPATHLEN, "%s/%s", dpath, path);
+}
+
 int main(int argc, char *argv[])
 {
     int			portarg = 0, fd;
@@ -869,33 +877,33 @@
 	exit(1);
     }
 
-    snprintf(HELPFILE, MAXPATHLEN, "%s/%s", dpath, HPATH);
-    snprintf(MOTD, MAXPATHLEN, "%s/%s", dpath, MPATH);
-    snprintf(SHORTMOTD, MAXPATHLEN, "%s/%s", dpath, SMPATH);
-    snprintf(MYNAME, MAXPATHLEN, "%s/%s", dpath, SPATH);
-    snprintf(CONFIGFILE, MAXPATHLEN, "%s/%s", dpath, CPATH);
+    prefix_path(HELPFILE, HPATH);
+    prefix_path(MOTD, MPATH);
+    prefix_path(SHORTMOTD, SMPATH);
+    prefix_path(MYNAME, SPATH);
+    prefix_path(CONFIGFILE, CPATH);
 #ifdef KPATH
-    snprintf(KLINEFILE, MAXPATHLEN, "%s/%s", dpath, KPATH);
+    prefix_path(KLINEFILE, KPATH);
 #endif
-    snprintf(IRCD_PIDFILE, MAXPATHLEN, "%s/%s", dpath, PPATH);
-    snprintf(ENTFILE, MAXPATHLEN, "%s/%s", dpath, EPATH);
-    snprintf(MCFILE, MAXPATHLEN, "%s/%s", dpath, MCPATH);
+    prefix_path(IRCD_PIDFILE, PPATH);
+    prefix_path(ENTFILE, EPATH);
+    prefix_path(MCFILE, MCPATH);
 #if defined(DEBUGMODE) || defined(DNS_DEBUG)
-    snprintf(LOGFILE, MAXPATHLEN, "%s/%s", dpath, LPATH);
+    prefix_path(LOGFILE, LPATH);
 #else
     snprintf(LOGFILE, MAXPATHLEN, "%s", "/dev/null");
 #endif
 #ifdef USE_USERLOGFILE
-    snprintf(ULFILE, MAXPATHLEN, "%s/%s", dpath, FNAME_USERLOG);
+    prefix_path(ULFILE, FNAME_USERLOG);
 #endif
 #ifdef USE_OPERLOGFILE
-    snprintf(OLFILE, MAXPATHLEN, "%s/%s", dpath, FNAME_OPERLOG);
+    prefix_path(OLFILE, FNAME_OPERLOG);
 #endif
 #ifdef USE_SYSLOGFILE
-    snprintf(SLFILE, MAXPATHLEN, "%s/%s", dpath, FNAME_SYSLOG);
+    prefix_path(SLFILE, FNAME_SYSLOG);
 #endif
 #ifdef DUMP_DEBUG
-    snprintf(DUMPFILE, MAXPATHLEN, "%s/%s", dpath, "dump.log");
+    prefix_path(DUMPFILE, "dump.log");
 #endif
 
 #ifdef CHDIRTOROOT
