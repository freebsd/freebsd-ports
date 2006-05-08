--- libjackoss.h	Mon Mar  6 07:14:48 2006
+++ libjackoss.h	Thu Mar 23 22:22:42 2006
@@ -2,6 +2,11 @@
 #define __LIBJACKOSS_H__
 #include <sys/types.h>
 #include <sys/poll.h>
+#include <sys/param.h>
+
+#if __FreeBSD_version <= 492100
+typedef unsigned int	nfds_t;
+#endif
 
 #ifdef __cplusplus
 extern "C" {
@@ -15,7 +20,7 @@
   int jackoss_select(int  n,  fd_set  *readfds,  
 		       fd_set *writefds, 
 		     fd_set *exceptfds, struct timeval *timeout);
-  int jackoss_poll (struct pollfd *__fds, nfds_t __nfds, int __timeout);
+  int jackoss_poll(struct pollfd *__fds, nfds_t __nfds, int __timeout);
   /* these are mainly need for sox */
 
   FILE * jackoss_fopen (const char *pathname, const char *mode);
