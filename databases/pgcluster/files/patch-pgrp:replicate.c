--- src/pgcluster/pgrp/replicate.c.orig	Thu Jun 24 22:12:48 2004
+++ src/pgcluster/pgrp/replicate.c	Thu Jun 24 22:20:38 2004
@@ -237,6 +237,7 @@
 		show_error("insertTransactionTbl failed");
 		return (TransactionTbl *)NULL;
 	}
+	show_debug("setTransactionTbl return %p (hostIP=%08x, port=%d, srcHostIP=%08x", ptr, work.hostIP, work.port, work.srcHostIP);
 	return ptr;
 }
 
@@ -386,8 +387,10 @@
 	set_function("PGRadd_HostTbl");
 
 	ptr = PGRget_HostTbl(conf_data->hostName, conf_data->port);
+	set_function("PGRadd_HostTbl");
 	if (ptr != (HostTbl*)NULL)
 	{
+		show_debug("found ptr");
 		PGRset_host_status(ptr,useFlag);
 		return ptr;
 	}
@@ -411,6 +414,7 @@
 	{
 		(ptr + 1) -> useFlag = DB_TBL_END;
 	}
+	show_debug("not found, allocate new one");
 	ptr->hostNum = cnt;
 	memcpy(ptr->hostName,conf_data->hostName,sizeof(ptr->hostName));
 	ptr->port = conf_data->port;
@@ -429,14 +433,17 @@
 	set_function("PGRget_master");
 
 	host_tbl = Host_Tbl_Begin;
+	show_debug("start get_master loop");
 	while(host_tbl->useFlag != DB_TBL_END)
 	{
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
 
@@ -451,6 +458,9 @@
 	PGRsem_lock(SemID,SEM_NUM_OF_RECOVERY);
 	if (Recovery_Status_Inf != (RecoveryStatusInf *)NULL)
 	{
+		if (Recovery_Status_Inf->recovery_status != status) {
+			show_debug("status change %d -> %d", Recovery_Status_Inf->recovery_status, status);
+		}
 		Recovery_Status_Inf->recovery_status = status;
 	}
 	PGRsem_unlock(SemID,SEM_NUM_OF_RECOVERY);
@@ -629,6 +639,8 @@
 		if (target != (HostTbl*)NULL)
 		{
 			memcpy((HostTbl *)&(Recovery_Status_Inf->target_host),target,sizeof(HostTbl));
+			set_function("PGRset_recovered_host");
+			show_debug("status=%d", useFlag);
 			PGRset_host_status(target,useFlag);
 		}
 
@@ -845,6 +857,7 @@
 	{
 		return STATUS_ERROR;
 	}
+	show_debug("hostName=%s, port=%d, recoveryPort=%d, hostNum=%d, useFlag=%d", host_ptr->hostName, host_ptr->port, host_ptr->recoveryPort, host_ptr->hostNum, host_ptr->useFlag);
 	if (host_ptr->useFlag != status)
 	{
 		host_ptr->useFlag = status;
@@ -1028,6 +1041,7 @@
 	}
 	conn = transaction_tbl->conn;
 
+	set_function("PGRsend_replicate_packet_to_server");
 	if (conn == NULL)
 	{
 		show_error("[%d@%s] may be down",host_ptr->port,host_ptr->hostName);
@@ -1268,6 +1282,7 @@
 
 	len = strlen(hostName);
 	ptr = Host_Tbl_Begin;
+	show_debug("hostName=%s, port=%d", hostName, port);
 	if (len > sizeof(ptr->hostName))
 	{
 		len = sizeof(ptr->hostName);
@@ -1709,7 +1724,7 @@
 	gettimeofday(&tv,NULL);
 	header->tv.tv_sec = htonl(tv.tv_sec);
 	header->tv.tv_usec = htonl(tv.tv_usec);
-	show_debug("query :: %s\n",query);
+	show_debug("query :: %s",query);
 
 	/* save header for logging */
 	if (is_need_sync_time(header) == true)
@@ -1965,18 +1980,18 @@
 	/* set function name */
 	set_function("PGRreplicate_packet_send");
 
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
@@ -2004,7 +2019,7 @@
 		 */
 		if (is_master_in_recovery(ptr->hostName, ptr->port) == true)
 		{
-			show_debug("%s skipped\n",ptr->hostName);
+			show_debug("%s skipped",ptr->hostName);
 			ptr ++;
 			continue;
 		}
@@ -2228,10 +2243,10 @@
 	set_function("PGRreplicate_packet_send_each_server");
 
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
