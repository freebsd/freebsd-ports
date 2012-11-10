--- soundcard/main.c.orig	2010-10-30 11:49:10.000000000 -0500
+++ soundcard/main.c	2012-11-05 17:22:52.000000000 -0500
@@ -358,7 +358,7 @@
 		{ "daemonize", 0, 0, 'D' },
 		{ 0, 0, 0, 0 }
 	};
-	char *configname = NULL, *cfgname, *filename = "/etc/ax25/soundmodem.conf";
+	char *configname = NULL, *cfgname, *filename = "%%PREFIX%%/etc/soundmodem.conf";
 	unsigned int verblevel = 2, tosyslog = 0, simd = 1, schedrr = 0, lockmem = 0, daemonize = 0;
         int c, err = 0;
 	xmlDocPtr doc;
