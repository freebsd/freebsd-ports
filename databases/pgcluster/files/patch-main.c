--- src/pgcluster/pgrp/main.c.orig	Tue Feb  3 23:34:22 2004
+++ src/pgcluster/pgrp/main.c	Tue Feb  3 23:36:10 2004
@@ -258,18 +258,18 @@
 	/* set function name */
 	set_function("replicate_packet_send");
 
-	show_debug("cmdSts=%c\n",header->cmdSts);
-	show_debug("cmdType=%c\n",header->cmdType);
-	show_debug("port=%d\n",header->port);
-	show_debug("pid=%d\n",header->pid);
-	show_debug("except_host=%s\n",header->except_host);
-	show_debug("from_host=%s\n",header->from_host);
-	show_debug("dbName=%s\n",header->dbName);
-	show_debug("userName=%s\n",header->userName);
-	show_debug("recieve sec=%u\n",header->tv.tv_sec);
-	show_debug("recieve usec=%u\n",header->tv.tv_usec);
-	show_debug("query_size=%d\n",header->query_size);
-	show_debug("query=%s\n",query);
+	show_debug("cmdSts=%c",header->cmdSts);
+	show_debug("cmdType=%c",header->cmdType);
+	show_debug("port=%d",header->port);
+	show_debug("pid=%d",header->pid);
+	show_debug("except_host=%s",header->except_host);
+	show_debug("from_host=%s",header->from_host);
+	show_debug("dbName=%s",header->dbName);
+	show_debug("userName=%s",header->userName);
+	show_debug("recieve sec=%u",header->tv.tv_sec);
+	show_debug("recieve usec=%u",header->tv.tv_usec);
+	show_debug("query_size=%d",header->query_size);
+	show_debug("query=%s",query);
 
 	/*
 	 * loop while registrated cluster DB exist 
@@ -291,7 +291,7 @@
 		 */
 		if (PGRis_master_in_recovery(ptr->hostName, ptr->port) == true)
 		{
-			show_debug("%s skipped\n",ptr->hostName);
+			show_debug("%s skipped",ptr->hostName);
 			ptr ++;
 			continue;
 		}
@@ -412,10 +412,10 @@
 	set_function("replicate_packet_send_each_server");
 
 	host = ptr->hostName;
-	show_debug("except:%d@%s host:%d@%s\n",
+	show_debug("except:%d@%s host:%d@%s",
 		header->port,header->except_host,
 		ptr->port,ptr->hostName);
-	show_debug("send replicate to:%s\n",host);
+	show_debug("send replicate to:%s",host);
 	/*
 	 * send query to cluster DB
 	 */
@@ -560,7 +560,7 @@
 		rtn = select(dest+1, &rmask, (fd_set *)NULL, (fd_set *)NULL, &timeout);
 		if (rtn && FD_ISSET(dest, &rmask))
 		{
-			show_debug("read_answer selected\n");
+			show_debug("read_answer selected");
 			answer = NULL;
 			answer = read_packet(dest,&header);
 			show_debug("answer[%s]",answer);
@@ -689,7 +689,7 @@
 			rtn = select(sock+1, &rmask, (fd_set *)NULL, (fd_set *)NULL, &timeout);
 			if (rtn && FD_ISSET(sock, &rmask))
 			{
-				show_debug("replicate_loop selected\n");
+				show_debug("replicate_loop selected");
 				query = NULL;
 				query = read_packet(sock,&header);
 				if (query == NULL)
@@ -708,7 +708,7 @@
 					}
 				}
 				gettimeofday(&(header.tv),NULL);
-				show_debug("query :: %s\n",query);
+				show_debug("query :: %s",query);
 
 				RecoveryStatus = PGRget_recovery_status();
 				PGRcheck_recovered_host();
@@ -781,7 +781,7 @@
 		show_error("fopen failed: (%s)",strerror(errno));
 		return STATUS_ERROR;
 	}
-	show_debug("%s open ok\n",fname);
+	show_debug("%s open ok",fname);
 
 	/*
 	 * read configuration file
@@ -954,13 +954,13 @@
 	/* set function name */
 	set_function("replicate_main");
 
-	show_debug("replicate mail %d port bind\n",Port_Number);
+	show_debug("replicate mail %d port bind",Port_Number);
 	status = PGR_Create_Socket_Bind(&fd, "", Port_Number);
 	if (status != STATUS_OK)
 	{
 		PGRreplicate_exit(0);
 	}
-	show_debug("replicate mail %d port bind OK \n",Port_Number);
+	show_debug("replicate mail %d port bind OK",Port_Number);
 	
 	for (;;)
 	{
@@ -976,11 +976,11 @@
 		 */
 		FD_ZERO(&rmask);
 		FD_SET(fd,&rmask);
-		show_debug("wait replicate\n");
+		show_debug("wait replicate");
 		rtn = select(fd+1, &rmask, (fd_set *)NULL, (fd_set *)NULL, &timeout);
 		if (rtn && FD_ISSET(fd, &rmask))
 		{
-			show_debug("replicate main: selected\n");
+			show_debug("replicate main: selected");
 			/*
 			 * get recovery status.
 			 */
@@ -1315,12 +1315,12 @@
 
 	if (init_server_tbl(path) != STATUS_OK)
 	{
-		show_debug("init_server_tbl error\n");
+		show_debug("init_server_tbl error");
 		PGRreplicate_exit(0);
 	}
 	if (PGRinit_recovery() != STATUS_OK)
 	{
-		show_debug("PGRinit_recovery error\n");
+		show_debug("PGRinit_recovery error");
 		PGRreplicate_exit(0);
 	}
 	pgid = getpgid(0);
