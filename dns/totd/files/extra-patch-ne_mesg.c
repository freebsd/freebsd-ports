--- ne_mesg.c.orig	Mon Jul  4 11:09:22 2005
+++ ne_mesg.c	Tue Sep 13 21:02:57 2005
@@ -59,7 +59,7 @@
 
 	/* write qname */
 	if (T.debug > 4)
-		syslog (LOG_DEBUG, "%s: qname offset = %zd", fn, ucp - buf);
+		syslog (LOG_DEBUG, "%s: qname offset = %td", fn, ucp - buf);
 
 	i = dname_copy (qname, ucp, buflen - written_len);
 	if (i < 0)
@@ -70,7 +70,7 @@
 
 	/* write qtype / qclass */
 	if (T.debug > 4)
-		syslog (LOG_DEBUG, "%s: qtype/qclass offset = %zd",
+		syslog (LOG_DEBUG, "%s: qtype/qclass offset = %td",
 			fn, ucp - buf);
 
 	written_len += sizeof (uint16_t) * 2;
@@ -226,13 +226,13 @@
 			*cnt = htons (us);
 
 			if (T.debug > 4)
-				syslog (LOG_DEBUG, "%s: now counter = %zd",
+				syslog (LOG_DEBUG, "%s: now counter = %u",
 					fn, us);
 		}
 	}
 
 	if (T.debug > 4)
-		syslog (LOG_DEBUG, "%s: return %d", fn, *wp - wp_start);
+		syslog (LOG_DEBUG, "%s: return %td", fn, *wp - wp_start);
 
 	return (*wp - wp_start);
 }
