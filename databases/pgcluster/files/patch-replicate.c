--- src/pgcluster/pgrp/replicate.c.orig	Fri Feb 20 11:38:40 2004
+++ src/pgcluster/pgrp/replicate.c	Sat Feb 21 20:50:01 2004
@@ -133,7 +133,7 @@
 	ptr = Dbserver_Tbl_Begin;
 	while (ptr != NULL)
 	{
-show_debug("search host(%d):port(%d):db(%s)",ptr->hostIP,ptr->port,ptr->dbName);
+show_debug("search host(%08x):port(%d):db(%s)",ptr->hostIP,ptr->port,ptr->dbName);
 		if ((ptr->useFlag == DB_TBL_USE) &&
 			(ptr->hostIP == host) &&
 			(ptr->port == host_ptr->port) &&
@@ -165,7 +165,7 @@
 	hostName = host_ptr->hostName;
 
 
-	show_debug("host:%s dbName:%s\n",hostName,dbName);
+	show_debug("host:%s dbName:%s",hostName,dbName);
 	if ((hostName == NULL ) || (dbName == NULL))
 	{
 		show_error("hostName or dbName is NULL");
@@ -215,7 +215,7 @@
 
 	if ((host_ptr == (HostTbl *)NULL) || (datap == (DBServerTbl*)NULL))
 	{
-		show_error("insertDBServerTbl datap error\n");
+		show_error("insertDBServerTbl datap error");
 		return (DBServerTbl *)NULL;
 	}
 	workp = Dbserver_Tbl_End;
@@ -258,7 +258,7 @@
 	if ((host1[0] == '\0' ) || (host2[0] == '\0') ||
 		(port1 <= 0) || (port2 <= 0))
 	{
-		show_debug("not same host:\n");
+		show_debug("not same host:");
 		return false;
 	}
 	ip1 = get_ip_by_name( host1);
@@ -266,10 +266,10 @@
 
 	if ((ip1 == ip2) && (port1 == port2))
 	{
-		show_debug("same host:%d@%x - %d@%x\n",port1,ip1,port2,ip2);
+		show_debug("same host:%d@%x - %d@%x",port1,ip1,port2,ip2);
 		return true;
 	}
-	show_debug("not same host:%d@%x - %d@%x\n",port1,ip1,port2,ip2);
+	show_debug("not same host:%d@%x - %d@%x",port1,ip1,port2,ip2);
 	return false;
 }
 
@@ -326,7 +326,7 @@
 		}
 		cnt ++;
 	}
-	show_debug("PQsetdbLogin ok!!\n");
+	show_debug("PQsetdbLogin ok!!");
 	return conn;
 }
 
@@ -379,6 +379,7 @@
 		show_error("insertTransactionTbl failed");
 		return (TransactionTbl *)NULL;
 	}
+	show_debug("setTransactionTbl return %p (hostIP=%08x, port=%d, srcHostIP=%08x", ptr, work.hostIP, work.port, work.srcHostIP);
 	return ptr;
 }
 
@@ -451,12 +452,12 @@
 			(!memcmp(ptr->dbName,header->dbName,strlen(ptr->dbName))) &&
 			(ptr->pid == header->pid))
 		{
-			show_debug("hit !! transaction tbl host %s db:%s pid:%d\n",host_ptr->hostName,ptr->dbName,ptr->pid);
+			show_debug("hit !! transaction tbl host %s db:%s pid:%d",host_ptr->hostName,ptr->dbName,ptr->pid);
 			return ptr;
 		}
 		ptr = (TransactionTbl*)ptr->next;
 	}
-	show_debug("not found in transaction tbl host %s db:%s pid:%d\n",header->from_host,header->dbName,header->pid);
+	show_debug("not found in transaction tbl host %s db:%s pid:%d",header->from_host,header->dbName,header->pid);
 	return (TransactionTbl * )NULL;
 }
 
@@ -561,8 +562,10 @@
 	set_function("PGRadd_HostTbl");
 
 	ptr = PGRget_HostTbl(conf_data->hostName, conf_data->port);
+	set_function("PGRadd_HostTbl");
 	if (ptr != (HostTbl*)NULL)
 	{
+		show_debug("found ptr");
 		PGRset_host_status(ptr,useFlag);
 		return ptr;
 	}
@@ -586,6 +589,7 @@
 	{
 		(ptr + 1) -> useFlag = DB_TBL_END;
 	}
+	show_debug("not found, allocate new one");
 	ptr->hostNum = cnt;
 	memcpy(ptr->hostName,conf_data->hostName,sizeof(ptr->hostName));
 	ptr->port = conf_data->port;
@@ -604,19 +608,22 @@
 	set_function("PGRget_master");
 
 	host_tbl = Host_Tbl_Begin;
+	show_debug("start get_master loop");
 	while(host_tbl->useFlag != DB_TBL_END)
 	{
-		show_debug("name %s flg %d port %d recoveryPort %d \n",
+		show_debug("  %s:%d flg %d recoveryPort %d",
 			host_tbl->hostName,
-			host_tbl->useFlag,
 			host_tbl->port,
+			host_tbl->useFlag,
 			host_tbl->recoveryPort);
 		if (host_tbl->useFlag == DB_TBL_USE)
 		{
+			show_debug("found master");
 			return host_tbl;
 		}
 		host_tbl ++;
 	}
+	show_debug("not found master");
 	return (HostTbl *)NULL;
 }
 
@@ -629,6 +636,9 @@
 	PGRsem_lock(SemID,SEM_NUM_OF_RECOVERY);
 	if (Recovery_Status_Inf != (RecoveryStatusInf *)NULL)
 	{
+		if (Recovery_Status_Inf->recovery_status != status) {
+			show_debug("status change %d -> %d", Recovery_Status_Inf->recovery_status, status);
+		}
 		Recovery_Status_Inf->recovery_status = status;
 	}
 	PGRsem_unlock(SemID,SEM_NUM_OF_RECOVERY);
@@ -763,7 +773,7 @@
 	{
 		if (Recovery_Status_Inf->useFlag != DB_TBL_FREE)
 		{
-			show_debug("check recovered host %d\n",Recovery_Status_Inf->useFlag);
+			show_debug("check recovered host (useFlag=%d)",Recovery_Status_Inf->useFlag);
 			ptr = PGRadd_HostTbl((HostTbl *)&(Recovery_Status_Inf->target_host),Recovery_Status_Inf->useFlag);
 			if (ptr == (HostTbl *) NULL)
 			{
@@ -792,6 +802,8 @@
 		if (target != (HostTbl*)NULL)
 		{
 			memcpy((HostTbl *)&(Recovery_Status_Inf->target_host),target,sizeof(HostTbl));
+			set_function("PGRset_recovered_host");
+			show_debug("status=%d", useFlag);
 			PGRset_host_status(target,useFlag);
 		}
 
@@ -961,6 +973,7 @@
 		return STATUS_ERROR;
 	}
 	host_ptr->useFlag = status;
+	show_debug("hostName=%s, port=%d, recoveryPort=%d, hostNum=%d, useFlag=%d", host_ptr->hostName, host_ptr->port, host_ptr->recoveryPort, host_ptr->hostNum, host_ptr->useFlag);
 	switch( host_ptr->useFlag)
 	{
 		case DB_TBL_FREE:
@@ -990,7 +1003,6 @@
 					host_ptr->hostName);
 			break;
 	}
-
 	return STATUS_OK;
 }
 
@@ -1144,7 +1156,7 @@
 			/*
 			 * re-use the connection data
 			 */
-			show_debug("find conn in db_server_tbl %d\n",db_server_tbl->conn);
+			show_debug("find conn in db_server_tbl %d",db_server_tbl->conn);
 			if ((db_server_tbl->conn != (PGconn *)NULL) && 
 				(db_server_tbl->conn->sock <= 0) )
 			{
@@ -1153,17 +1165,18 @@
 			}
 		}
 		conn = db_server_tbl->conn;
-		show_debug("send_replicate_packet_to_server query=%s\n",query);
+		show_debug("send_replicate_packet_to_server query=%s",query);
 	}
 
+	set_function("PGRsend_replicate_packet_to_server");
 	if (conn == NULL)
 	{
-		show_error("conn is null\n");
+		show_error("conn is null");
 		PGRset_host_status(host_ptr,DB_TBL_ERROR);
 		return STATUS_ERROR;
 	}
 
-	show_debug("db:%s port:%s user:%s host:%s query:%s\n",
+	show_debug("db:%s port:%s user:%s host:%s query:%s",
 	database,port,userName,host,query);
 	/*
 	 * execute query
@@ -1184,7 +1197,7 @@
 		(header->cmdType == CMD_TYPE_COPY_DATA_END))
 	{
 		/* copy data replication */
-		show_debug("query(%s) size(%d)\n",query,header->query_size);
+		show_debug("query(%s) size(%d)",query,header->query_size);
 		rtn =PQputnbytes(conn, query,header->query_size);
 		if (header->cmdType == CMD_TYPE_COPY_DATA_END)
 		{
@@ -1201,11 +1214,11 @@
 
 	if (res == NULL)
 	{
-		show_error("PQexec error \n");
+		show_error("PQexec error");
 		PGRset_host_status(host_ptr,DB_TBL_ERROR);
 		return STATUS_ERROR;
 	}
-	show_debug("PQexec send :%s\n",query);
+	show_debug("PQexec send :%s",query);
 
 	str = PQcmdStatus(res);
 	if ((str == NULL) || (*str == '\0'))
@@ -1258,7 +1271,7 @@
 			}
 		}
 	}
-	show_debug("PQexec end\n");
+	show_debug("PQexec end");
 	if ((! strcmp(database,"template1")) ||
 		(! strcmp(database,"template0")))
 	{
@@ -1337,12 +1350,12 @@
 	 * send header data to queue
 	 */
 	rtn = msgsnd(RecoveryMsgid, msg_header, sizeof(ReplicateHeader), IPC_NOWAIT);
-	show_debug("msgsnd header rtn:%d\n",rtn);
+	show_debug("msgsnd header rtn:%d",rtn);
 	/*
 	 * send query data to queue
 	 */
 	rtn = msgsnd(RecoveryMsgid, msg_query, header->query_size, IPC_NOWAIT);
-	show_debug("msgsnd query rtn:%d\n",rtn);
+	show_debug("msgsnd query rtn:%d",rtn);
 
 	/*
 	 * release memory
@@ -1364,6 +1377,7 @@
 
 	len = strlen(hostName);
 	ptr = Host_Tbl_Begin;
+	show_debug("hostName=%s, port=%d", hostName, port);
 	if (len > sizeof(ptr->hostName))
 	{
 		len = sizeof(ptr->hostName);
@@ -1379,10 +1393,12 @@
 	}
 	if (ptr->useFlag != DB_TBL_END)
 	{
+		show_debug("found: %s:%d", ptr->hostName, ptr->port);
 		return ptr;
 	}
 	else
 	{
+		show_debug("not found");
 		return (HostTbl*)NULL;
 	}
 }
@@ -1392,7 +1408,6 @@
 {
 	char buf[256];
 	char log[288];
-	int len1;
 	char * p;
 	va_list ap;
 	time_t t;
@@ -1410,13 +1425,12 @@
 	{
 		*p = ' ';
 	}
-	len1 = strlen(log);
 	va_start(ap,fmt);
 	vsnprintf(buf,sizeof(buf),fmt,ap);
 	va_end(ap);
 	strcat(log,buf);
 	strcat(log,"\n");
-	if (fputs(log,LogFp) > 0)
+	if (fputs(log,LogFp) >= 0)
 	{
 		fflush(LogFp);
 	}
