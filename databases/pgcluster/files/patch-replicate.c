--- src/pgcluster/pgrp/replicate.c.orig	Tue Feb  3 23:36:49 2004
+++ src/pgcluster/pgrp/replicate.c	Tue Feb  3 23:44:28 2004
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
 
@@ -451,12 +451,12 @@
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
 
@@ -606,7 +606,7 @@
 	host_tbl = Host_Tbl_Begin;
 	while(host_tbl->useFlag != DB_TBL_END)
 	{
-		show_debug("name %s flg %d port %d recoveryPort %d \n",
+		show_debug("name %s flg %d port %d recoveryPort %d",
 			host_tbl->hostName,
 			host_tbl->useFlag,
 			host_tbl->port,
@@ -763,7 +763,7 @@
 	{
 		if (Recovery_Status_Inf->useFlag != DB_TBL_FREE)
 		{
-			show_debug("check recovered host %d\n",Recovery_Status_Inf->useFlag);
+			show_debug("check recovered host %d",Recovery_Status_Inf->useFlag);
 			ptr = PGRadd_HostTbl((HostTbl *)&(Recovery_Status_Inf->target_host),Recovery_Status_Inf->useFlag);
 			if (ptr == (HostTbl *) NULL)
 			{
@@ -1144,7 +1144,7 @@
 			/*
 			 * re-use the connection data
 			 */
-			show_debug("find conn in db_server_tbl %d\n",db_server_tbl->conn);
+			show_debug("find conn in db_server_tbl %d",db_server_tbl->conn);
 			if ((db_server_tbl->conn != (PGconn *)NULL) && 
 				(db_server_tbl->conn->sock <= 0) )
 			{
@@ -1153,17 +1153,17 @@
 			}
 		}
 		conn = db_server_tbl->conn;
-		show_debug("send_replicate_packet_to_server query=%s\n",query);
+		show_debug("send_replicate_packet_to_server query=%s",query);
 	}
 
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
@@ -1184,7 +1184,7 @@
 		(header->cmdType == CMD_TYPE_COPY_DATA_END))
 	{
 		/* copy data replication */
-		show_debug("query(%s) size(%d)\n",query,header->query_size);
+		show_debug("query(%s) size(%d)",query,header->query_size);
 		rtn =PQputnbytes(conn, query,header->query_size);
 		if (header->cmdType == CMD_TYPE_COPY_DATA_END)
 		{
@@ -1201,11 +1201,11 @@
 
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
@@ -1258,7 +1258,7 @@
 			}
 		}
 	}
-	show_debug("PQexec end\n");
+	show_debug("PQexec end");
 	if ((! strcmp(database,"template1")) ||
 		(! strcmp(database,"template0")))
 	{
@@ -1337,12 +1337,12 @@
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
