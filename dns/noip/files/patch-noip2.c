--- noip2.c.orig	Tue Feb 20 22:12:22 2007
+++ noip2.c	Sun Feb 25 18:47:38 2007
@@ -176,7 +176,7 @@
 #define CLIENT_IP_PORT		8245
 
 #define VERSION			"2.1.4"
-#define USER_AGENT		"User-Agent: Linux-DUC/"VERSION
+#define USER_AGENT		"User-Agent: FreeBSD-DUC/"VERSION
 #define SETTING_SCRIPT		"settings.php?"
 #define USTRNG			"username="
 #define PWDSTRNG		"&pass="
@@ -283,7 +283,7 @@
 #define CMSG21	"Please select the Internet interface from this list.\n"
 #define CMSG22	"By typing the number associated with it."
 #define CMSG23	"Too many network devices.  Limit is %d"
-#define CMSG24	"\nAuto configuration for Linux client of no-ip.com.\n"
+#define CMSG24	"\nAuto configuration for FreeBSD client of no-ip.com.\n"
 #define CMSG25	"Can't create config file (%s)"
 #define CMSG25a	"Re-run noip, adding '-c configfilename' as a parameter."
 #define CMSG26	"Can't rename config file (%s)"
@@ -490,7 +490,7 @@
         fprintf(stderr, "[ -d][ -D pid]");
 #endif                                                                          
 	fprintf(stderr, "[ -i addr][ -S][ -M][ -h]");
-	fprintf(stderr, "\n\nVersion Linux-%s\n", VERSION);
+	fprintf(stderr, "\n\nVersion FreeBSD-%s\n", VERSION);
 	fprintf(stderr, "Options: -C               create configuration data\n");
 	fprintf(stderr, "         -F               force NAT off\n");
 	fprintf(stderr, "         -Y               select all hosts/groups\n");
@@ -2058,17 +2058,12 @@
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
+			if (ifd->ifi_type == IFT_OTHER
+				 || ifd->ifi_type == IFT_GIF
+				 || ifd->ifi_type == IFT_LOOP
+				 || ifd->ifi_type == IFT_FAITH)
 		 	   continue;
-#endif
 			q = dq;     // add new name into list
 			p = ifa->ifa_name;
 			devnum++;
