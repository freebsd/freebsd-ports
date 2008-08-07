--- dns_mre.c.orig	2008-08-02 01:23:19.000000000 +0900
+++ dns_mre.c	2008-08-02 20:37:50.000000000 +0900
@@ -160,7 +160,6 @@
 	u_int8_t *	udp_pointer = NULL;
 	u_int8_t *	dns_pointer = NULL;
 	int			dns_size;
-	int			i;
 
 	if( !answer_flag )
 		printf("# Preparing query raw packet...");
@@ -195,7 +194,7 @@
 	u_int8_t *	ip4_pointer = NULL;
 	u_int8_t *	udp_pointer = NULL;
 	u_int8_t *	dns_pointer = NULL;
-	int			dns_size;
+	int			dns_size = 0;
 	int			i;
 
 	if( !answer_flag )
@@ -797,6 +796,7 @@
 		"    -x <no_txids>		Number of static Transaction IDs to use (optional; default 15)\n"
 		"    -v					Verbosity\n"
 		, cmd);
+    return 1;
 }
 
 
