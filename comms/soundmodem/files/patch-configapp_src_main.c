--- configapp/src/main.c.orig	Sun Nov  5 21:45:29 2006
+++ configapp/src/main.c	Sun Nov  5 21:45:50 2006
@@ -358,7 +358,7 @@
 #else /* WIN32 */
 
 static xmlDocPtr doc = NULL;
-static const char *cfgfile = "/etc/ax25/soundmodem.conf";
+static const char *cfgfile = "%%PREFIX%%/etc/soundmodem.conf";
 
 static xmlNodePtr findconfig(const char *newname)
 {
