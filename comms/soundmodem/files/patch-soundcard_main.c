--- soundcard/main.c.orig	Sun Nov  5 21:44:34 2006
+++ soundcard/main.c	Sun Nov  5 21:44:53 2006
@@ -354,7 +354,7 @@
 		{ "daemonize", 0, 0, 'D' },
 		{ 0, 0, 0, 0 }
 	};
-	char *configname = NULL, *cfgname, *filename = "/etc/ax25/soundmodem.conf";
+	char *configname = NULL, *cfgname, *filename = "%%PREFIX%%/etc/soundmodem.conf";
 	unsigned int verblevel = 2, tosyslog = 0, simd = 1, schedrr = 0, lockmem = 0, daemonize = 0;
         int c, err = 0;
 	xmlDocPtr doc;
