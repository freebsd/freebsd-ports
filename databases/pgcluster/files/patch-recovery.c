--- src/pgcluster/pgrp/recovery.c.orig	Fri Feb 20 11:38:40 2004
+++ src/pgcluster/pgrp/recovery.c	Fri Feb 20 16:25:21 2004
@@ -121,7 +121,7 @@
 	int packet_size = 0;
 
 	/* set function name */
-	set_function("read_packet");
+	set_function("recovery::read_packet");
 
 	read_ptr = (char*)packet;
 	packet_size = sizeof(RecoveryPacket);
@@ -140,7 +140,7 @@
 		}
 		read_size += r;
 		if (read_size == packet_size){
-			show_debug("receive packet\n");
+			show_debug("receive packet");
 			show_recovery_packet(packet);
 			return r;
 		}
@@ -166,7 +166,7 @@
 	 */
 	FD_ZERO(&rmask);
 	FD_SET(host->sock,&rmask);
-	show_debug("wait\n");
+	show_debug("wait");
 	for(;;)
 	{
 		rtn = select(host->sock+1, &rmask, (fd_set *)NULL, (fd_set *)NULL, &timeout);
@@ -227,7 +227,7 @@
 		{
 			if (count > MAX_RETRY_TIMES )
 			{
-				show_error("PGR_Create_Socket_Connect failed");
+				show_error("PGR_Create_Socket_Connect(%d, %s, %d) failed", host->sock, host->hostName, host->recoveryPort);
 				return STATUS_ERROR;
 			}
 			count ++;
@@ -331,18 +331,18 @@
 	Target->port = packet->port;
 	Target->recoveryPort = packet->recoveryPort;
 	Target->sock = *sock;
-	show_debug("1st setup target %s\n",Target->hostName);
-	show_debug("1st setup port %d\n",Target->port);
+	show_debug("1st setup target %s",Target->hostName);
+	show_debug("1st setup port %d",Target->port);
 	/*
 	 * check another recovery process 
 	 */
-	show_debug("check another recovery process\n");
+	show_debug("check another recovery process");
 	if (PGRget_recovery_status() != RECOVERY_INIT)
 	{
 		/*
 		 * recovery process is already running
 		 */
-		show_debug(" already recovery job runing\n");
+		show_debug(" already recovery job runing");
 		memset(packet,0,sizeof(packet));
 		packet->packet_no = RECOVERY_ERROR_OCCUPIED ;
 		status = send_packet(Target,packet);
@@ -352,7 +352,7 @@
 	/*
 	 * add recovery target to host table
 	 */
-	show_debug("add recovery target to host table\n");
+	show_debug("add recovery target to host table (%s)", packet->hostName);
 	memcpy(host_tbl.hostName,packet->hostName,sizeof(host_tbl.hostName));
 	host_tbl.port = packet->port;
 	PGRset_recovered_host(&host_tbl,DB_TBL_INIT);
@@ -365,7 +365,7 @@
 	/*
 	 * set RECOVERY_PGDATA_REQ packet data
 	 */
-	show_debug("set RECOVERY_PGDATA_REQ packet data\n");
+	show_debug("set RECOVERY_PGDATA_REQ packet data");
 	memset(packet,0,sizeof(RecoveryPacket));
 	packet->packet_no = RECOVERY_PGDATA_REQ ;
 	master = PGRget_master();
@@ -374,7 +374,7 @@
 		/*
 		 * connection error , master may be down
 		 */
-		show_error("get master info error , master may be down\n");
+		show_error("get master info error , master may be down");
 		packet->packet_no = RECOVERY_ERROR_CONNECTION;
 		status = send_packet(Target, packet);
 		reset_recovery_prepare();
@@ -385,14 +385,14 @@
 	Master->sock = -1;
 	Master->port = master->port;
 	Master->recoveryPort = master->recoveryPort;
-	show_debug("send packet to master %s recoveryPort %d\n",Master->hostName, Master->recoveryPort);
+	show_debug("send packet to master %s recoveryPort %d",Master->hostName, Master->recoveryPort);
 	status = send_packet(Master, packet);
 	if (status != STATUS_OK)
 	{
 		/*
 		 * connection error , master may be down
 		 */
-		show_error("connection error , master may be down\n");
+		show_error("connection error , master may be down");
 		packet->packet_no = RECOVERY_ERROR_CONNECTION;
 		status = send_packet(Target, packet);
 		reset_recovery_prepare();
@@ -409,10 +409,10 @@
 	/*
 	 * wait answer from master server 
 	 */
-	show_debug("wait answer from master server\n");
+	show_debug("wait answer from master server");
 	memset(packet,0,sizeof(RecoveryPacket));
 	read_packet_from_master(Master, packet);
-	show_debug("get answer from master\n");
+	show_debug("get answer from master");
 	if (packet->packet_no == RECOVERY_PGDATA_ANS)
 	{
 		/*
@@ -455,7 +455,7 @@
 	status = PGRwait_transaction_count_clear();
 	if (status != STATUS_OK)
 	{
-		show_error("transaction is too busy, please try again after\n");
+		show_error("transaction is too busy, please try again after");
 		packet->packet_no = RECOVERY_ERROR_CONNECTION;
 		status = send_packet(Target,packet);
 		status = send_packet(Master,packet);
@@ -473,7 +473,7 @@
 		/*
 		 * connection error , master may be down
 		 */
-		show_error("connection error , master may be down\n");
+		show_error("connection error , master may be down");
 		packet->packet_no = RECOVERY_ERROR_CONNECTION;
 		status = send_packet(Target,packet);
 		status = send_packet(Master,packet);
@@ -502,7 +502,7 @@
 	}
 	else
 	{
-		show_debug("failer answer returned\n");
+		show_debug("failer answer returned");
 		packet->packet_no = RECOVERY_ERROR_CONNECTION;
 		status = send_packet(Target,packet);
 		status = send_packet(Master,packet);
@@ -534,20 +534,20 @@
 		show_error("there is no master ");
 		return STATUS_ERROR;
 	}
-	show_debug("master %s - %d\n",master->hostName,master->port);
+	show_debug("master %s - %d",master->hostName,master->port);
 	master_ptr = PGRget_HostTbl(master->hostName,master->port);
 	if (master_ptr == (HostTbl *)NULL)
 	{
-		show_error("master table is null\n");
+		show_error("master table is null");
 		return STATUS_ERROR;
 	}
 	if (target != (RecoveryTbl *)NULL)
 	{
-		show_debug("target %s - %d\n",target->hostName,target->port);
+		show_debug("target %s - %d",target->hostName,target->port);
 		target_ptr = PGRget_HostTbl(target->hostName,target->port);
 		if (target_ptr == (HostTbl *)NULL)
 		{
-			show_error("target table is null\n");
+			show_error("target table is null");
 			return STATUS_ERROR;
 		}
 	}
@@ -590,7 +590,7 @@
 		free(msg_query);
 	}
 	free(msg_header);
-	show_debug("send_queue return status %d\n",status);
+	show_debug("send_queue return status %d",status);
 	return status;
 }
 
@@ -611,7 +611,7 @@
 	set_function("pgrecovery_loop");
 
 	count = 0;
-	show_debug("recovery accept port %d\n",Recovery_Port_Number);
+	show_debug("recovery accept port %d",Recovery_Port_Number);
 	while ((status = PGR_Create_Acception(fd,&sock,"",Recovery_Port_Number)) != STATUS_OK)
 	{
 		show_error("PGR_Create_Acception failed");
@@ -651,7 +651,7 @@
 			continue;
 		}
 
-		show_debug("receive packet no:%d\n",packet.packet_no);
+		show_debug("receive packet no:%d",packet.packet_no);
 
 		switch (packet.packet_no)
 		{
@@ -694,6 +694,7 @@
 				if (status == STATUS_OK)
 				{
 					show_debug("PGRsend_queue ok");
+					memset(&new_host, 0, sizeof(new_host));
 					memcpy(new_host.hostName,Target.hostName,sizeof(new_host.hostName));
 					new_host.port = Target.port;
 					new_host.recoveryPort = Target.recoveryPort;
@@ -708,7 +709,7 @@
 					status = send_packet(&Target,&packet);
 				}
 				/*
-				 * stop queueing, and initiarise recovery status
+				 * stop queueing, and initialise recovery status
 				 */
 				finish_recovery();
 				loop_end = true;
@@ -721,7 +722,7 @@
 				memset((char *)&MasterPacketData,0,sizeof(RecoveryPacket));
 				break;
 			case RECOVERY_ERROR_ANS : 
-				show_debug("recovery error accept. top queueing and initiarse recovery status\n");
+				show_debug("recovery error accept. top queueing and initialise recovery status");
 				status = PGRsend_queue(&Master,NULL);
 				memset(&packet,0,sizeof(RecoveryPacket));
 				packet.packet_no = RECOVERY_ERROR_ANS ;
@@ -776,7 +777,7 @@
 		 */
 		FD_ZERO(&rmask);
 		FD_SET(fd,&rmask);
-		show_debug("wait recovery\n");
+		show_debug("wait recovery");
 		rtn = select(fd+1, &rmask, (fd_set *)NULL, (fd_set *)NULL, &timeout);
 		if (rtn && FD_ISSET(fd, &rmask))
 		{
