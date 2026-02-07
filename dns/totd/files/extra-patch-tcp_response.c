--- tcp_response.c.orig	Mon Jul  4 11:09:22 2005
+++ tcp_response.c	Tue Sep 13 21:00:53 2005
@@ -110,7 +110,7 @@
 
 	cont->wp += len;
 	if (cont->wp < (cont->mesg.p + cont->mesg_len)) {
-		syslog (LOG_DEBUG, "%s: left %zd bytes -- continue.", fn,
+		syslog (LOG_DEBUG, "%s: left %td bytes -- continue.", fn,
 			(cont->mesg.p + cont->mesg_len) - cont->wp);
 
 		/* SUCCESS */
