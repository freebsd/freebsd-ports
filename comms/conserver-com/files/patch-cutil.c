--- conserver/cutil.c.orig	2010-11-02 12:42:57.000000000 +0900
+++ conserver/cutil.c	2010-11-20 20:32:52.490682415 +0900
@@ -2283,7 +2283,7 @@
 	if ((ifc.ifc_len - r) < sizeof(*ifr))
 	    break;
 #ifdef HAVE_SA_LEN
-	if (sa->sa_len > sizeof(ifr->ifr_ifru))
+	if (sa->sa_len > sizeof(ifr->ifr_addr))
 	    r += sizeof(ifr->ifr_name) + sa->sa_len;
 	else
 #endif
