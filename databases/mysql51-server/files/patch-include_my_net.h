--- include/my_net.h.orig	2013-05-06 10:44:34.000000000 +0200
+++ include/my_net.h	2013-05-06 10:45:11.000000000 +0200
@@ -110,7 +110,7 @@
 				   int buflen, int *h_errnop);
 #define my_gethostbyname_r_free()
 #else
-#define my_gethostbyname_r(A,B,C,D,E) gethostbyname_r((A),(B),(C),(D),(E))
+#define my_gethostbyname_r(A,B,C,D,E) gethostbyname_r((A),(B),(C),(D),(E),NULL)
 #define my_gethostbyname_r_free()
 #endif /* !defined(HAVE_GETHOSTBYNAME_R) */
 
