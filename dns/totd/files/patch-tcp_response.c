diff -ru work/totd-1.3/tcp_response.c work~/totd-1.3/tcp_response.c
--- tcp_response.c.orig	Wed Mar  6 06:56:03 2002
+++ tcp_response.c	Sat Jun 14 22:17:56 2003
@@ -116,7 +116,7 @@
 	cont->wp += len;
 	if (cont->wp < (cont->mesg.p + cont->mesg_len)) {
 		syslog (LOG_DEBUG, "%s: left %d bytes -- continue.", fn,
-			(cont->mesg.p + cont->mesg_len) - cont->wp);
+			(int)((cont->mesg.p + cont->mesg_len) - cont->wp));
 
 		/* SUCCESS */
 		return 0;	/* the processing continues ... */
