--- host/bsd/bsd-if.c.orig	2003-10-16 02:48:23.000000000 +0000
+++ host/bsd/bsd-if.c	2012-07-07 12:24:22.000000000 +0000
@@ -71,14 +72,15 @@
 
 /* this macro helps us size a struct ifreq: */
 #ifdef HAVE_SOCKADDR_SA_LEN
-#define SIZEOF_IFREQ(ifr) (sizeof(ifr->ifr_name) + ifr->ifr_addr.sa_len)
+#define SIZEOF_IFREQ(ifr) \
+( sizeof(ifr->ifr_name) + (ifr->ifr_addr.sa_len > sizeof(ifr->ifr_ifru) ? ifr->ifr_addr.sa_len : sizeof(ifr->ifr_ifru)) )
 #else  /* !HAVE_SOCKADDR_SA_LEN */
 #define SIZEOF_IFREQ(ifr) (sizeof(ifr->ifr_name) + sizeof(struct sockaddr))
 #endif /* !HAVE_SOCKADDR_SA_LEN */
 
 /* this finds a network interface: */
 int
 tme_bsd_if_find(const char *ifr_name_user, struct ifreq **_ifreq, tme_uint8_t **_if_addr, unsigned int *_if_addr_size)
 {
   int saved_errno;
   int dummy_fd;
@@ -175,7 +192,7 @@
     if (ifr_user == NULL
 	&& (ifr_name_user != NULL
 	    ? !strncmp(ifr->ifr_name, ifr_name_user, sizeof(ifr->ifr_name))
-	    : !(ifr->ifr_flags & IFF_LOOPBACK))) {
+	    : !(saved_flags & IFF_LOOPBACK))) {
       ifr_user = ifr;
     }
   }
