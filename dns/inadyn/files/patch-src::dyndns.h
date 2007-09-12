diff -Naur src/dyndns.h.orig src/dyndns.h
--- src/dyndns.h.orig	2007-08-21 18:42:48.000000000 +0000
+++ src/dyndns.h	2007-08-21 18:42:57.000000000 +0000
@@ -44,7 +44,7 @@
 
 /*test values*/
 #define DYNDNS_DEFAULT_DEBUG_LEVEL	1
-#define DYNDNS_DEFAULT_CONFIG_FILE	"/etc/inadyn.conf"
+#define DYNDNS_DEFAULT_CONFIG_FILE	"%%PREFIX%%/etc/inadyn.conf"
 
 #define DYNDNS_MY_USERNAME		"test"
 #define DYNDNS_MY_PASSWD		"test"
