--- ./conserver/cutil.c.orig	2015-06-03 02:19:31.000000000 +0900
+++ ./conserver/cutil.c	2015-06-13 18:00:11.685862531 +0900
@@ -1939,7 +1939,7 @@
 	if ((ifc.ifc_len - r) < sizeof(*ifr))
 	    break;
 #  ifdef HAVE_SA_LEN
-	if (sa->sa_len > sizeof(ifr->ifr_ifru))
+	if (sa->sa_len > sizeof(ifr->ifr_addr))
 	    r += sizeof(ifr->ifr_name) + sa->sa_len;
 	else
 #  endif
