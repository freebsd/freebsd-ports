--- noip2.c.orig	2009-11-17 20:23:40.000000000 +0100
+++ noip2.c	2009-11-17 20:27:45.000000000 +0100
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
@@ -2316,17 +2316,14 @@
 	dq = (unsigned char *)devs;     // point at name list
 	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
 		if (ifa->ifa_addr->sa_family == AF_LINK) {
-// FreeBSD doesn't define some of these!
-#ifdef IFT_PFLOG
 			struct if_data *ifd = (struct if_data *) ifa->ifa_data;
-			if (ifd->ifi_type == IFT_PFLOG
-				 || ifd->ifi_type == IFT_PFSYNC
-				 || ifd->ifi_type == IFT_ENC
-				 || ifd->ifi_type == IFT_BRIDGE
-				 || ifd->ifi_type == IFT_OTHER
-				 || ifd->ifi_type == IFT_GIF)
-		 	   continue;
-#endif
+
+			if (ifd->ifi_type == IFT_OTHER
+				|| ifd->ifi_type == IFT_GIF
+				|| ifd->ifi_type == IFT_LOOP
+				|| ifd->ifi_type == IFT_FAITH)
+			continue;
+
 			q = dq;     // add new name into list
 			p = ifa->ifa_name;
 			devnum++;
