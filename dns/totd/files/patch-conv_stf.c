diff -ru work/totd-1.3/conv_stf.c work~/totd-1.3/conv_stf.c
--- conv_stf.c.orig	Mon Mar  4 04:34:10 2002
+++ conv_stf.c	Sat Jun 14 22:16:03 2003
@@ -94,7 +94,7 @@
 				owner_len, owner, rrl);
 	rr_list_free (rrl);
 
-	syslog (LOG_DEBUG, "%s: rrs_new %x", fn, (unsigned int) rrs_new);
+	syslog (LOG_DEBUG, "%s: rrs_new %p", fn, rrs_new);
 	return (rrs_new);
 }
 
