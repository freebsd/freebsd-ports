--- src/pgcluster/pgrp/recovery.c	16 Apr 2004 10:17:45 -0000	1.1.1.4
+++ src/pgcluster/pgrp/recovery.c	16 Apr 2004 10:21:06 -0000	1.5
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
 	Target->port = ntohs(packet->port);
 	Target->recoveryPort = ntohs(packet->recoveryPort);
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
 		PGRset_recovery_packet_no(packet, RECOVERY_ERROR_OCCUPIED) ;
 		status = send_packet(Target,packet);
@@ -352,7 +352,7 @@
 	/*
 	 * add recovery target to host table
 	 */
-	show_debug("add recovery target to host table\n");
+	show_debug("add recovery target to host table (%s)", packet->hostName);
 	memcpy(host_tbl.hostName,packet->hostName,sizeof(host_tbl.hostName));
 	host_tbl.port = ntohs(packet->port);
 	PGRset_recovered_host(&host_tbl,DB_TBL_INIT);
@@ -365,7 +365,7 @@
 	/*
 	 * set RECOVERY_PGDATA_REQ packet data
 	 */
-	show_debug("set RECOVERY_PGDATA_REQ packet data\n");
+	show_debug("set RECOVERY_PGDATA_REQ packet data");
 	memset(packet,0,sizeof(RecoveryPacket));
 	PGRset_recovery_packet_no(packet, RECOVERY_PGDATA_REQ );
 
@@ -376,7 +376,7 @@
 		/*
 		 * connection error , master may be down
 		 */
-		show_error("get master info error , master may be down\n");
+		show_error("get master info error , master may be down");
 		PGRset_recovery_packet_no(packet, RECOVERY_ERROR_CONNECTION);
 		status = send_packet(Target, packet);
 		reset_recovery_prepare();
@@ -387,14 +387,14 @@
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
 		PGRset_host_status(master,DB_TBL_ERROR);
 		goto retry_connect_master ;
 		/*
@@ -405,7 +405,7 @@
 		return loop_end;
 		*/
 	}
-	
+
 	/*
 	 * start prepare of recovery
 	 *     set recovery status to "prepare start"
@@ -415,10 +415,10 @@
 	/*
 	 * wait answer from master server 
 	 */
-	show_debug("wait answer from master server\n");
+	show_debug("wait answer from master server");
 	memset(packet,0,sizeof(RecoveryPacket));
 	read_packet_from_master(Master, packet);
-	show_debug("get answer from master\n");
+	show_debug("get answer from master");
 	if (ntohs(packet->packet_no) == RECOVERY_PGDATA_ANS)
 	{
 		/*
@@ -461,7 +461,7 @@
 	status = PGRwait_transaction_count_clear();
 	if (status != STATUS_OK)
 	{
-		show_error("transaction is too busy, please try again after\n");
+		show_error("transaction is too busy, please try again after");
 		PGRset_recovery_packet_no(packet, RECOVERY_ERROR_CONNECTION);
 		status = send_packet(Target,packet);
 		status = send_packet(Master,packet);
@@ -479,7 +479,7 @@
 		/*
 		 * connection error , master may be down
 		 */
-		show_error("connection error , master may be down\n");
+		show_error("connection error , master may be down");
 		PGRset_recovery_packet_no(packet, RECOVERY_ERROR_CONNECTION);
 		status = send_packet(Target,packet);
 		status = send_packet(Master,packet);
@@ -508,7 +508,7 @@
 	}
 	else
 	{
-		show_debug("failer answer returned\n");
+		show_debug("failer answer returned");
 		PGRset_recovery_packet_no(packet, RECOVERY_ERROR_CONNECTION);
 		status = send_packet(Target,packet);
 		status = send_packet(Master,packet);
@@ -538,23 +538,23 @@
 
 	if (master == (RecoveryTbl *)NULL)
 	{
-		show_error("there is no master ");
+		show_error("there is no master");
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
@@ -621,7 +621,7 @@
 	{
 		free(msg_header);
 	}
-	show_debug("send_queue return status %d\n",status);
+	show_debug("send_queue return status %d",status);
 	return status;
 }
 
@@ -642,7 +642,7 @@
 	set_function("pgrecovery_loop");
 
 	count = 0;
-	show_debug("recovery accept port %d\n",Recovery_Port_Number);
+	show_debug("recovery accept port %d",Recovery_Port_Number);
 	while ((status = PGR_Create_Acception(fd,&sock,"",Recovery_Port_Number)) != STATUS_OK)
 	{
 		show_error("PGR_Create_Acception failed");
@@ -682,7 +682,7 @@
 			continue;
 		}
 
-		show_debug("receive packet no:%d\n",ntohs(packet.packet_no));
+		show_debug("receive packet no:%d",ntohs(packet.packet_no));
 
 		switch (ntohs(packet.packet_no))
 		{
@@ -739,7 +739,7 @@
 					status = send_packet(&Target,&packet);
 				}
 				/*
-				 * stop queueing, and initiarise recovery status
+				 * stop queueing, and initialise recovery status
 				 */
 				finish_recovery();
 				loop_end = true;
@@ -752,7 +752,7 @@
 				memset((char *)&MasterPacketData,0,sizeof(RecoveryPacket));
 				break;
 			case RECOVERY_ERROR_ANS : 
-				show_debug("recovery error accept. top queueing and initiarse recovery status\n");
+				show_debug("recovery error accept. top queueing and initialise recovery status");
 				status = PGRsend_queue(&Master,NULL);
 				memset(&packet,0,sizeof(RecoveryPacket));
 				PGRset_recovery_packet_no(&packet, RECOVERY_ERROR_ANS);
@@ -807,7 +807,7 @@
 		 */
 		FD_ZERO(&rmask);
 		FD_SET(fd,&rmask);
-		show_debug("wait recovery\n");
+		show_debug("wait recovery");
 		rtn = select(fd+1, &rmask, (fd_set *)NULL, (fd_set *)NULL, &timeout);
 		if (rtn && FD_ISSET(fd, &rmask))
 		{
