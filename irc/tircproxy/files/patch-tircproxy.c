--- tircproxy.c.orig	Thu May  4 22:53:30 2000
+++ tircproxy.c	Sat Oct 15 07:02:11 2005
@@ -131,9 +131,16 @@
 #	include <netinet/ip_compat.h>
 #  endif
 #  include <netinet/ip_fil.h>
+#  include <netinet/ip_nat.h>
+#  include <netinet/ip_state.h>
 #  include <netinet/ip_proxy.h>
 #  include <netinet/ip_nat.h>
+#  include <netinet/ipl.h>
+#  include <osreldate.h>
 #  define TRANS 1
+#  ifndef IPL_NAT
+#  define IPL_NAT IPNAT_NAME
+#  endif
 #  warning IPF transparent proxying available
 # else
 #  undef IPF
@@ -1066,9 +1073,13 @@
 	struct sockaddr_in			to_addr;
 	int					to_len;
 #if IPF
-	struct sockaddr_in			socketin, sloc;
-	natlookup_t     			natlook;
-	int					fd;
+#if __FreeBSD_version >=600024
+	ipfobj_t        obj;
+#endif
+	struct sockaddr_in                      socketin, sloc;
+	natlookup_t				natlook;
+	natlookup_t                             *natlookp = &natlook;
+	int                                     fd;
 #endif
    
    	/* Give this thing 10 minutes to get started (paranoia).
@@ -1144,6 +1155,13 @@
                 	exit(-1);
                 }
 
+#if __FreeBSD_version >=600024
+		bzero(&obj, sizeof(obj));
+		obj.ipfo_rev = IPFILTER_VERSION;
+		obj.ipfo_size = sizeof(natlook);
+		obj.ipfo_ptr = &natlook;
+		obj.ipfo_type = IPFOBJ_NATLOOKUP;
+#endif
                 bzero((char *)&natlook, sizeof(natlook));
                 natlook.nl_outip = socketin.sin_addr;
                 natlook.nl_inip = sloc.sin_addr;
@@ -1152,9 +1170,13 @@
                 natlook.nl_inport = sloc.sin_port;
 
                 fd = open(IPL_NAT, O_RDONLY);
-                if (ioctl(fd, SIOCGNATL, &natlook) == -1)
+#if __FreeBSD_version >=600024
+		if (ioctl(fd, SIOCGNATL, &obj) == -1)
+#else
+		if (ioctl(fd, SIOCGNATL, &natlookp) == -1)
+#endif
 	     	{
-                	perror("ioctl");
+                	perror("ioctl(SIOCGNATL)");
                 	exit(-1);
                 }
                 close(fd);
@@ -2201,7 +2223,9 @@
 	/* People neither using the CDIR stuff nor running as root probably 
 	 * couldn't care less about ident problems.
 	 */
+#ifdef CDIR_IDENT
 	if (!use_cdir && getuid()) tries = 10;
+#endif
 
 	/* FIXME: dangerous sprintfs */
 #ifdef CDIR
