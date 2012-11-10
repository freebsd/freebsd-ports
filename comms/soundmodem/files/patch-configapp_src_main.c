--- configapp/src/main.c.orig	2010-10-30 11:49:09.000000000 -0500
+++ configapp/src/main.c	2012-11-05 17:20:25.000000000 -0500
@@ -359,7 +359,7 @@
 #else /* WIN32 */
 
 static xmlDocPtr doc = NULL;
-static const char *cfgfile = "/etc/ax25/soundmodem.conf";
+static const char *cfgfile = "%%PREFIX%%/etc/soundmodem.conf";
 
 static xmlNodePtr findconfig(const char *newname)
 {
