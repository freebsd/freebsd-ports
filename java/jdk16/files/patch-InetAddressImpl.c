$FreeBSD$

--- ../src/solaris/native/java/net/InetAddressImpl.c	25 Jan 2003 23:22:26 -0000	1.7
+++ ../src/solaris/native/java/net/InetAddressImpl.c	28 Feb 2003 09:34:18 -0000
@@ -25,6 +25,7 @@
 
 #include "java_net_InetAddressImpl.h"
 
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 /* reentrant BIND includes --billh */
 
 #include <sys/param.h>
@@ -33,14 +34,16 @@
 
 /* forward declarations --billh */
 
+static
 HOST_R_RETURN
-gethostbyname_r(const char *name,  struct hostent *hptr,
-		HOST_R_ARGS);
+__j_gethostbyname_r(const char *name,  struct hostent *hptr,
+		    HOST_R_ARGS);
 
+static
 HOST_R_RETURN
-gethostbyaddr_r(const char *addr, int len, int type,
-		struct hostent *hptr,
-		HOST_R_ARGS);
+__j_gethostbyaddr_r(const char *addr, int len, int type,
+		    struct hostent *hptr, HOST_R_ARGS);
+#endif
 
 /*
 */
@@ -99,6 +102,8 @@
 
 #ifdef __GLIBC__
 	gethostbyname_r(hostname, &res, buf, sizeof(buf), &hp, &h_error);
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+	hp = __j_gethostbyname_r(hostname, &res, buf, sizeof(buf), &h_error);
 #else
 	hp = gethostbyname_r(hostname, &res, buf, sizeof(buf), &h_error);
 #endif
@@ -106,6 +111,9 @@
 #ifdef __GLIBC__
 	    gethostbyaddr_r(hp->h_addr, hp->h_length, AF_INET,
 			    &res2, buf2, sizeof(buf2), &hp, &h_error);
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+	    hp = __j_gethostbyaddr_r(hp->h_addr, hp->h_length, AF_INET,
+				     &res2, buf2, sizeof(buf2), &h_error);
 #else
 	    hp = gethostbyaddr_r(hp->h_addr, hp->h_length, AF_INET,
 				 &res2, buf2, sizeof(buf2), &h_error);
@@ -189,6 +197,8 @@
     /* Try once, with our static buffer. */
 #ifdef __GLIBC__
     gethostbyname_r(hostname, &res, buf, sizeof(buf), &hp, &h_error);
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    hp = __j_gethostbyname_r(hostname, &res, buf, sizeof(buf), &h_error);
 #else    
     hp = gethostbyname_r(hostname, &res, buf, sizeof(buf), &h_error);
 #endif
@@ -203,6 +213,9 @@
 #ifdef __GLIBC__
 	    gethostbyname_r(hostname, &res, tmp, BIG_HENT_BUF_SIZE,
 			    &hp, &h_error);
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+	    hp = __j_gethostbyname_r(hostname, &res, tmp, BIG_HENT_BUF_SIZE,
+				     &h_error);
 #else
 	    hp = gethostbyname_r(hostname, &res, tmp, BIG_HENT_BUF_SIZE,
 				 &h_error);
@@ -283,6 +296,9 @@
 #ifdef __GLIBC__
     gethostbyaddr_r((char *)&addr, sizeof(addr), AF_INET, &hent,
 		    buf, sizeof(buf), &hp, &h_error);
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    hp = __j_gethostbyaddr_r((char *)&addr, sizeof(addr), AF_INET, &hent,
+			     buf, sizeof(buf), &h_error);
 #else
     hp = gethostbyaddr_r((char *)&addr, sizeof(addr), AF_INET, &hent,
 			 buf, sizeof(buf), &h_error);
@@ -297,6 +313,9 @@
 #ifdef __GLIBC__
 	    gethostbyaddr_r((char *)&addr, sizeof(addr), AF_INET,
 			    &hent, tmp, BIG_HENT_BUF_SIZE, &hp, &h_error);
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+	    hp = __j_gethostbyaddr_r((char *)&addr, sizeof(addr), AF_INET,
+				     &hent, tmp, BIG_HENT_BUF_SIZE, &h_error);
 #else
 	    hp = gethostbyaddr_r((char *)&addr, sizeof(addr), AF_INET,
 				 &hent, tmp, BIG_HENT_BUF_SIZE, &h_error);
@@ -335,8 +354,9 @@
 static HOST_R_RETURN 
 copy_hostent(struct hostent *, struct hostent *, HOST_R_COPY_ARGS);
 
+static
 HOST_R_RETURN
-gethostbyname_r(const char *name,  struct hostent *hptr, HOST_R_ARGS) {
+__j_gethostbyname_r(const char *name,  struct hostent *hptr, HOST_R_ARGS) {
 	struct hostent *he = gethostbyname(name);
 
 	HOST_R_ERRNO;
@@ -347,8 +367,9 @@
 	return (copy_hostent(he, hptr, HOST_R_COPY));
 }
 
+static
 HOST_R_RETURN
-gethostbyaddr_r(const char *addr, int len, int type,
+__j_gethostbyaddr_r(const char *addr, int len, int type,
 		struct hostent *hptr, HOST_R_ARGS) {
 	struct hostent *he = gethostbyaddr(addr, len, type);
 
