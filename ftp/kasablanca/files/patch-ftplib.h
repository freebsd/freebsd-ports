--- src/ftplib.h.orig	Wed Feb  2 23:29:55 2005
+++ src/ftplib.h	Wed Feb  2 23:30:51 2005
@@ -56,6 +56,10 @@
 #include <sys/time.h>
 #include <openssl/ssl.h>
 
+#ifdef __FreeBSD__
+#define off64_t off_t
+#endif
+
 using namespace std;
 
 /**
