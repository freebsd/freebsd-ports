--- src/pgcluster/pgrp/main.c	16 Apr 2004 10:17:45 -0000	1.1.1.9
+++ src/pgcluster/pgrp/main.c	16 Apr 2004 10:21:06 -0000	1.6
@@ -156,7 +156,7 @@
 	char * query;
 
 	/* set function name */
-	set_function("read_packet");
+	set_function("main::read_packet");
 
 	if (header == NULL)
 	{
@@ -179,7 +179,7 @@
 		}
 		if (r == 0)
 		{
-			show_debug("connection closed");
+			show_debug("connection closed (sock=%d, header=%d, read=%d)", sock, header_size, read_size);
 			return NULL;
 		}
 		read_size += r;
@@ -311,18 +311,18 @@
 	/* set function name */
 	set_function("replicate_packet_send");
 
-	show_debug("cmdSts=%c\n",header->cmdSts);
-	show_debug("cmdType=%c\n",header->cmdType);
-	show_debug("port=%d\n",ntohs(header->port));
-	show_debug("pid=%d\n",ntohs(header->pid));
-	show_debug("except_host=%s\n",header->except_host);
-	show_debug("from_host=%s\n",header->from_host);
-	show_debug("dbName=%s\n",header->dbName);
-	show_debug("userName=%s\n",header->userName);
-	show_debug("recieve sec=%u\n",ntohl(header->tv.tv_sec));
-	show_debug("recieve usec=%u\n",ntohl(header->tv.tv_usec));
-	show_debug("query_size=%d\n",ntohl(header->query_size));
-	show_debug("query=%s\n",query);
+	show_debug("cmdSts=%c",header->cmdSts);
+	show_debug("cmdType=%c",header->cmdType);
+	show_debug("port=%d",ntohs(header->port));
+	show_debug("pid=%d",ntohs(header->pid));
+	show_debug("except_host=%s",header->except_host);
+	show_debug("from_host=%s",header->from_host);
+	show_debug("dbName=%s",header->dbName);
+	show_debug("userName=%s",header->userName);
+	show_debug("recieve sec=%u",ntohl(header->tv.tv_sec));
+	show_debug("recieve usec=%u",ntohl(header->tv.tv_usec));
+	show_debug("query_size=%d",ntohl(header->query_size));
+	show_debug("query=%s",query);
 
 	/*
 	 * loop while registrated cluster DB exist 
@@ -333,8 +333,10 @@
 	show_debug("useFlag[%d]",ptr->useFlag);
 	while(ptr->useFlag != DB_TBL_END)
 	{
+		set_function("replicate_packet_send");
 		same_host = false;
 		sem_num = ptr->hostNum;
+		show_debug("loop: cnt=%d, hostNum=%d, hostName=%s, port=%d, recoveryPort=%d, useFlag=%d", loop_cnt++, ptr->hostNum, ptr->hostName, ptr->port, ptr->recoveryPort, ptr->useFlag);
 		/*
 		 * check the status of the cluster DB
 		 */
@@ -348,7 +350,7 @@
 		 */
 		if (PGRis_master_in_recovery(ptr->hostName, ptr->port) == true)
 		{
-			show_debug("%s skipped\n",ptr->hostName);
+			show_debug("%s skipped",ptr->hostName);
 			ptr ++;
 			continue;
 		}
@@ -371,6 +373,8 @@
 			{
 				snprintf(PGR_Result,PGR_MESSAGE_BUFSIZE,"%d,%u,%u", PGR_SET_CURRENT_TIME_FUNC_NO,(unsigned int)ntohl(header->tv.tv_sec),(unsigned int)ntohl(header->tv.tv_usec));
 			}
+			set_function("replicate_packet_send");
+			show_debug("replicate_packet_send_each_server returns %d (useFlag=%d", rtn, ptr->useFlag);
 			show_debug("sem_lock[%d]",sem_num);
 			if (sem_num > 0)
 				PGRsem_lock(SemID,sem_num);
@@ -483,7 +487,7 @@
 
 		ptr ++;
 		PGR_Response_Inf->current_cluster ++;
-	}	
+	}
 	show_debug("replicate_packet_send end");
 	if (status == STATUS_ABORTED)
 	{
@@ -525,10 +529,10 @@
 	set_function("replicate_packet_send_each_server");
 
 	host = ptr->hostName;
-	show_debug("except:%d@%s host:%d@%s\n",
+	show_debug("except:%d@%s host:%d@%s",
 		ntohs(header->port),header->except_host,
 		ptr->port,ptr->hostName);
-	show_debug("send replicate to:%s\n",host);
+	show_debug("send replicate to:%s",host);
 	/*
 	 * send query to cluster DB
 	 */
@@ -539,6 +543,8 @@
 	}
 
 	rtn = PGRsend_replicate_packet_to_server( ptr, header,query,PGR_Result);
+	set_function("replicate_packet_send_each_server");
+	show_debug("PGRsend_replicate_packet_to_server() returns %d", rtn);
 	/*
 	if ((header->cmdSts == CMD_STS_QUERY ) &&
 		((header->cmdType == CMD_TYPE_INSERT) || 
@@ -597,7 +603,7 @@
 	}
 	send_ptr = PGR_Result;
 	buf_size = PGR_MESSAGE_BUFSIZE;
-	show_debug("%d[%s]",buf_size,send_ptr);
+	show_debug("buf_size=%d[send_ptr=%s]",buf_size,send_ptr);
 	if (buf_size < 1)
 		buf_size = 1;
 
@@ -612,7 +618,7 @@
 	rtn = select(dest+1, (fd_set *)NULL, &wmask, (fd_set *)NULL, &timeout);
 	if (rtn && FD_ISSET(dest, &wmask))
 	{
-		show_debug("return_result[%s]",send_ptr);
+		show_debug("select() and FD_ISSET() [send_ptr=%s]",send_ptr);
 		for (;;)
 		{
 			s = send(dest,send_ptr + send_size,buf_size - send_size ,0);
@@ -634,7 +640,7 @@
 			send_size += s;
 			if (send_size == buf_size)
 			{
-				show_debug("%d send",send_size);
+				show_debug("%d bytes sent",send_size);
 				status = STATUS_OK;
 				if (wait == PGR_WAIT_ANSWER)
 				{
@@ -682,7 +688,7 @@
 		rtn = select(dest+1, &rmask, (fd_set *)NULL, (fd_set *)NULL, &timeout);
 		if (rtn && FD_ISSET(dest, &rmask))
 		{
-			show_debug("read_answer selected");
+			show_debug("read_answer selected (dest=%d)", dest);
 			answer = NULL;
 			answer = read_packet(dest,&header);
 			if (answer == NULL)
@@ -773,6 +779,43 @@
 	return NULL;
 }
 
+static void
+dump_status(int fd)
+{
+  HostTbl *host = Host_Tbl_Begin;
+  while (host->useFlag != DB_TBL_END) {
+    char buf[256];
+    const char *flag = buf;
+    if (host->useFlag == DB_TBL_FREE) {
+      flag = "FREE";
+    } else if (host->useFlag == DB_TBL_INIT) {
+      flag = "INIT";
+    } else if (host->useFlag == DB_TBL_USE) {
+      flag = "USE";
+    } else if (host->useFlag == DB_TBL_ERROR) {
+      flag = "ERROR";
+    } else {
+      snprintf(buf, sizeof(buf), "UNKNOWN(%d)", host->useFlag);
+    }
+    show_debug("%s:%d flag=%s, recoveryPort=%d",
+	       host->hostName, host->port, flag, host->recoveryPort);
+
+    snprintf(buf, sizeof(buf), "hostNum=%d\n", host->hostNum);
+    write(fd, buf, strlen(buf));
+    snprintf(buf, sizeof(buf), "hostName=%s\n", host->hostName);
+    write(fd, buf, strlen(buf));
+    snprintf(buf, sizeof(buf), "port=%d\n", host->port);
+    write(fd, buf, strlen(buf));
+    snprintf(buf, sizeof(buf), "useFlag=%d\n", host->useFlag);
+    write(fd, buf, strlen(buf));
+    snprintf(buf, sizeof(buf), "recoveryPort=%d\n", host->recoveryPort);
+    write(fd, buf, strlen(buf));
+    write(fd, "\n", strlen("\n"));
+
+    host++;
+  }
+}
+
 /*--------------------------------------------------------------------
  * SYMBOL
  *    replicate_loop()
@@ -811,11 +854,11 @@
 	}
 	if (pid == 0)
 	{
-		signal(SIGHUP, quick_exit);	
-		signal(SIGINT, quick_exit);	
-		signal(SIGQUIT, quick_exit);	
-		signal(SIGTERM, quick_exit);	
-		signal(SIGALRM, quick_exit); 
+		signal(SIGHUP, quick_exit);
+		signal(SIGINT, quick_exit);
+		signal(SIGQUIT, quick_exit);
+		signal(SIGTERM, quick_exit);
+		signal(SIGALRM, quick_exit);
 		setpgid(0,pgid);
 
 		/* child loop */
@@ -833,20 +876,27 @@
 			FD_ZERO(&rmask);
 			FD_SET(sock,&rmask);
 			rtn = select(sock+1, &rmask, (fd_set *)NULL, (fd_set *)NULL, &timeout);
+			if (rtn < 0) {
+				show_debug("select() = %d (%s)", rtn, strerror(errno));
+			}
 			if (rtn && FD_ISSET(sock, &rmask))
 			{
-				show_debug("replicate_loop selected\n");
+				show_debug("replicate_loop selected (sock=%d)", sock);
 				query = NULL;
 				query = read_packet(sock,&header);
-				if (query == NULL)
+				if (query == NULL && errno != 0)
 				{
-					show_error("session closed");
+					show_error("read_packet failed (errno=%d)", errno);
 					if (PGR_Cascade == true)
 					{
 						PGRupper_session_closed();
 					}
 					break;
 				}
+				if (header.cmdType == 'o') {
+					dump_status(sock);
+					break;
+				}
 				if (header.cmdSys == CMD_SYS_CASCADE )
 				{
 					PGR_Cascade = true;
@@ -869,7 +919,7 @@
 				gettimeofday(&tv,NULL);
 				header.tv.tv_sec = htonl(tv.tv_sec);
 				header.tv.tv_usec = htonl(tv.tv_usec);
-				show_debug("query :: %s\n",query);
+				show_debug("query :: %s",query);
 
 				RecoveryStatus = PGRget_recovery_status();
 				PGRcheck_recovered_host();
@@ -965,7 +1015,7 @@
 		show_error("fopen failed: (%s)",strerror(errno));
 		return STATUS_ERROR;
 	}
-	show_debug("%s open ok\n",fname);
+	show_debug("%s open ok",fname);
 
 	/*
 	 * read configuration file
@@ -1130,7 +1180,7 @@
 		(LoadBalanceTbl + i)->port = -1;
 		(LoadBalanceTbl + i)->sock = -1;
 	}
-	memset((LoadBalanceTbl + i),0,sizeof(RecoveryTbl));
+	memset((LoadBalanceTbl + i),0,sizeof(RecoveryTbl)); /* kuriyama: needed? */
 	PGR_Free_Conf_Data();
 
 	/* allocate result buffer of query */
@@ -1219,7 +1269,7 @@
 	{
 		PGRreplicate_exit(0);
 	}
-	show_debug("replicate main %d port bind OK \n",Port_Number);
+	show_debug("replicate main %d port bind OK",Port_Number);
 	
 	start_up_replication_server();
 
@@ -1237,11 +1287,14 @@
 		 */
 		FD_ZERO(&rmask);
 		FD_SET(fd,&rmask);
-		show_debug("wait replicate\n");
+		show_debug("wait replicate");
 		rtn = select(fd+1, &rmask, (fd_set *)NULL, (fd_set *)NULL, &timeout);
+		if (rtn < 0) {
+			show_debug("select() = %d (%s)", rtn, strerror(errno));
+		}
 		if (rtn && FD_ISSET(fd, &rmask))
 		{
-			show_debug("replicate main: selected\n");
+			show_debug("replicate main: selected (fd=%d)", fd);
 			/*
 			 * get recovery status.
 			 */
@@ -1597,12 +1650,12 @@
 
 	if (init_server_tbl(PGR_Data_Path) != STATUS_OK)
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
@@ -1614,10 +1667,10 @@
 	}
 	if (pid == 0)
 	{
-		signal(SIGHUP, quick_exit);	
-		signal(SIGINT, quick_exit);	
-		signal(SIGQUIT, quick_exit);	
-		signal(SIGTERM, quick_exit);	
+		signal(SIGHUP, quick_exit);
+		signal(SIGINT, quick_exit);
+		signal(SIGQUIT, quick_exit);
+		signal(SIGTERM, quick_exit);
 		/*
 		 * in child process,
 		 * call recovery module
