--- tftp_def.h.orig	2004-02-13 11:16:09.000000000 +0800
+++ tftp_def.h	2013-10-30 13:23:22.000000000 +0800
@@ -19,6 +19,7 @@
 
 #include <sys/time.h>
 #include <sys/times.h>
+#include <netinet/in.h>
 #include <netdb.h>
 
 /* standard return value */
@@ -49,7 +50,7 @@
 
 int timeval_diff(struct timeval *res, struct timeval *t1, struct timeval *t0);
 int print_eng(double value, char *string, int size, char *format);
-inline char *Strncpy(char *to, const char *from, size_t size);
+char *Strncpy(char *to, const char *from, size_t size);
 int Gethostbyname(char *addr, struct hostent *host);
 
 #endif
