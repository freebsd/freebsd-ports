--- src/pgcluster/pgrp/replicate.c	16 Apr 2004 10:17:45 -0000	1.1.1.9
+++ src/pgcluster/pgrp/replicate.c	16 Apr 2004 10:21:06 -0000	1.5
@@ -141,7 +141,7 @@
 	ptr = Dbserver_Tbl_Begin;
 	while (ptr != NULL)
 	{
-		show_debug("search host(%d):port(%d):db(%s)",ptr->hostIP,ptr->port,ptr->dbName);
+		show_debug("search host(%08x):port(%d):db(%s)",ptr->hostIP,ptr->port,ptr->dbName);
 		if ((ptr->useFlag == DB_TBL_USE) &&
 			(ptr->hostIP == host) &&
 			(ptr->port == host_ptr->port) &&
@@ -393,6 +393,7 @@
 		show_error("insertTransactionTbl failed");
 		return (TransactionTbl *)NULL;
 	}
+	show_debug("setTransactionTbl return %p (hostIP=%08x, port=%d, srcHostIP=%08x", ptr, work.hostIP, work.port, work.srcHostIP);
 	return ptr;
 }
 
@@ -581,8 +582,10 @@
 	set_function("PGRadd_HostTbl");
 
 	ptr = PGRget_HostTbl(conf_data->hostName, conf_data->port);
+	set_function("PGRadd_HostTbl");
 	if (ptr != (HostTbl*)NULL)
 	{
+		show_debug("found ptr");
 		PGRset_host_status(ptr,useFlag);
 		return ptr;
 	}
@@ -606,6 +609,7 @@
 	{
 		(ptr + 1) -> useFlag = DB_TBL_END;
 	}
+	show_debug("not found, allocate new one");
 	ptr->hostNum = cnt;
 	memcpy(ptr->hostName,conf_data->hostName,sizeof(ptr->hostName));
 	ptr->port = conf_data->port;
@@ -624,19 +628,22 @@
 	set_function("PGRget_master");
 
 	host_tbl = Host_Tbl_Begin;
+	show_debug("start get_master loop");
 	while(host_tbl->useFlag != DB_TBL_END)
 	{
-		show_debug("name %s flg %d port %d recoveryPort %d ",
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
 
@@ -651,6 +658,9 @@
 	PGRsem_lock(SemID,SEM_NUM_OF_RECOVERY);
 	if (Recovery_Status_Inf != (RecoveryStatusInf *)NULL)
 	{
+		if (Recovery_Status_Inf->recovery_status != status) {
+			show_debug("status change %d -> %d", Recovery_Status_Inf->recovery_status, status);
+		}
 		Recovery_Status_Inf->recovery_status = status;
 	}
 	PGRsem_unlock(SemID,SEM_NUM_OF_RECOVERY);
@@ -799,7 +809,7 @@
 	{
 		if (Recovery_Status_Inf->useFlag != DB_TBL_FREE)
 		{
-			show_debug("check recovered host %d",Recovery_Status_Inf->useFlag);
+			show_debug("check recovered host (useFlag=%d)",Recovery_Status_Inf->useFlag);
 			ptr = PGRadd_HostTbl((HostTbl *)&(Recovery_Status_Inf->target_host),Recovery_Status_Inf->useFlag);
 			if (ptr == (HostTbl *) NULL)
 			{
@@ -830,6 +840,8 @@
 		if (target != (HostTbl*)NULL)
 		{
 			memcpy((HostTbl *)&(Recovery_Status_Inf->target_host),target,sizeof(HostTbl));
+			set_function("PGRset_recovered_host");
+			show_debug("status=%d", useFlag);
 			PGRset_host_status(target,useFlag);
 		}
 
@@ -1027,6 +1039,7 @@
 	{
 		return STATUS_ERROR;
 	}
+	show_debug("hostName=%s, port=%d, recoveryPort=%d, hostNum=%d, useFlag=%d", host_ptr->hostName, host_ptr->port, host_ptr->recoveryPort, host_ptr->hostNum, host_ptr->useFlag);
 	if (host_ptr->useFlag != status)
 	{
 		host_ptr->useFlag = status;
@@ -1251,6 +1264,7 @@
 		show_debug("send_replicate_packet_to_server query=%s",query);
 	}
 
+	set_function("PGRsend_replicate_packet_to_server");
 	if (conn == NULL)
 	{
 		show_error("[%d@%s] may be down",host_ptr->port,host_ptr->hostName);
@@ -1311,7 +1325,7 @@
 
 	if (res == NULL)
 	{
-		show_error("PQexec error ");
+		show_error("PQexec error");
 		if ( header->cmdSts != CMD_STS_NOTICE )
 		{
 			PGRset_host_status(host_ptr,DB_TBL_ERROR);
@@ -1501,6 +1515,7 @@
 
 	len = strlen(hostName);
 	ptr = Host_Tbl_Begin;
+	show_debug("hostName=%s, port=%d", hostName, port);
 	if (len > sizeof(ptr->hostName))
 	{
 		len = sizeof(ptr->hostName);
