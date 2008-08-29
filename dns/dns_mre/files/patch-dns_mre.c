--- dns_mre.c.orig	2008-08-02 01:23:19.000000000 +0900
+++ dns_mre.c	2008-08-27 21:20:44.000000000 +0900
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
@@ -720,13 +719,6 @@
 		exit(1);
 	}
 
-	/* Connect to the DNS Server */
-	if(  connect(sockfd, (struct sockaddr *) &q_d_addr, sizeof( q_d_addr )) == -1 )
-	{
-		perror("connect()");
-		exit(1);
-	}
-
 	/* Send the DNS Query */
 	if( (numbytes = sendto(sockfd, (char *) payload, payload_size, 0,
 		(struct sockaddr *)&q_d_addr, sizeof( q_d_addr ))) == -1 )
@@ -797,6 +789,7 @@
 		"    -x <no_txids>		Number of static Transaction IDs to use (optional; default 15)\n"
 		"    -v					Verbosity\n"
 		, cmd);
+    return 1;
 }
 
 
