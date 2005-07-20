--- nsping.h.orig	Wed Jul 20 15:23:39 2005
+++ nsping.h	Tue Feb 15 17:29:55 2005
@@ -27,7 +27,7 @@
 #endif
 
 #define QUERY_BACKLOG	1024
-#define DNS_PORT		53
+#define DNS_PORT		"53"
 #define DEFAULT_SECOND_INTERVAL	1
 #define DEFAULT_USECOND_INTERVAL	0
 
@@ -40,11 +40,10 @@
 void summarize(int);
 double trip_time(struct timeval *send_time, struct timeval *rcv);
 struct timeval *timeval_subtract(struct timeval *out, struct timeval *in);
-char *addr_string(u_int32_t address);
-int bind_udp_socket(u_int32_t address, u_int16_t port);
+int bind_udp_socket(char *port);
 void dprintf(char *fmt, ...);
 void usage(void);
 char *xstrdup(char *v);
-u_int32_t resolve(char *name);
+struct addrinfo *resolve(char *name, char *port);
 
 #endif
