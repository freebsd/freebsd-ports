--- ./noip2.c.orig	2008-11-21 23:19:54.000000000 +0100
+++ ./noip2.c	2011-09-12 14:58:30.000000000 +0200
@@ -198,7 +198,7 @@
 #define CLIENT_IP_PORT		8245
 
 #define VERSION			"2.1.9"
-#define USER_AGENT		"User-Agent: Linux-DUC/"VERSION
+#define USER_AGENT		"User-Agent: FreeBSD-DUC/"VERSION
 #define SETTING_SCRIPT		"settings.php?"
 #define USTRNG			"username="
 #define PWDSTRNG		"&pass="
@@ -308,7 +308,7 @@
 #define CMSG21	"Please select the Internet interface from this list.\n"
 #define CMSG22	"By typing the number associated with it."
 #define CMSG23	"Too many network devices.  Limit is %d"
-#define CMSG24	"\nAuto configuration for Linux client of no-ip.com.\n"
+#define CMSG24	"\nAuto configuration for FreeBSD client of no-ip.com.\n"
 #define CMSG25	"Can't create config file (%s)"
 #define CMSG25a	"Re-run noip, adding '-c configfilename' as a parameter."
 #define CMSG26	"Can't rename config file (%s)"
@@ -525,7 +525,7 @@
         fprintf(stderr, "[ -d][ -D pid]");
 #endif                                                                          
 	fprintf(stderr, "[ -i addr][ -S][ -M][ -h]");
-	fprintf(stderr, "\n\nVersion Linux-%s\n", VERSION);
+	fprintf(stderr, "\n\nVersion FreeBSD-%s\n", VERSION);
 	fprintf(stderr, "Options: -C               create configuration data\n");
 	fprintf(stderr, "         -F               force NAT off\n");
 	fprintf(stderr, "         -Y               select all hosts/groups\n");
