--- conserver/cutil.c.orig	2009-10-22 20:40:33.466802736 +0900
+++ conserver/cutil.c	2009-10-22 20:40:53.459082364 +0900
@@ -2283,7 +2283,7 @@
 	if ((ifc.ifc_len - r) < sizeof(*ifr))
 	    break;
 #ifdef HAVE_SA_LEN
-	if (sa->sa_len > sizeof(ifr->ifr_irfu))
+	if (sa->sa_len > sizeof(ifr->ifr_addr))
 	    r += sizeof(ifr->ifr_name) + sa->sa_len;
 	else
 #endif
