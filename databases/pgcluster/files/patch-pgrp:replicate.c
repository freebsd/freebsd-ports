--- src/pgcluster/pgrp/replicate.c	9 May 2004 11:21:36 -0000	1.1.1.10
+++ src/pgcluster/pgrp/replicate.c	9 May 2004 11:51:34 -0000	1.6
@@ -150,7 +150,7 @@
 	ptr = Dbserver_Tbl_Begin;
 	while (ptr != NULL)
 	{
-		show_debug("search host(%d):port(%d):db(%s)",ptr->hostIP,ptr->port,ptr->dbName);
+		show_debug("search host(%08x):port(%d):db(%s)",ptr->hostIP,ptr->port,ptr->dbName);
 		if ((ptr->useFlag == DB_TBL_USE) &&
 			(ptr->hostIP == host) &&
 			(ptr->port == host_ptr->port) &&
@@ -380,6 +380,7 @@
 		show_error("insertTransactionTbl failed");
 		return (TransactionTbl *)NULL;
 	}
+	show_debug("setTransactionTbl return %p (hostIP=%08x, port=%d, srcHostIP=%08x", ptr, work.hostIP, work.port, work.srcHostIP);
 	return ptr;
 }
 
@@ -568,8 +569,10 @@
 	set_function("PGRadd_HostTbl");
 
 	ptr = PGRget_HostTbl(conf_data->hostName, conf_data->port);
+	set_function("PGRadd_HostTbl");
 	if (ptr != (HostTbl*)NULL)
 	{
+		show_debug("found ptr");
 		PGRset_host_status(ptr,useFlag);
 		return ptr;
 	}
@@ -593,6 +596,7 @@
 	{
 		(ptr + 1) -> useFlag = DB_TBL_END;
 	}
+	show_debug("not found, allocate new one");
 	ptr->hostNum = cnt;
 	memcpy(ptr->hostName,conf_data->hostName,sizeof(ptr->hostName));
 	ptr->port = conf_data->port;
@@ -611,19 +615,22 @@
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
 
@@ -638,6 +645,9 @@
 	PGRsem_lock(SemID,SEM_NUM_OF_RECOVERY);
 	if (Recovery_Status_Inf != (RecoveryStatusInf *)NULL)
 	{
+		if (Recovery_Status_Inf->recovery_status != status) {
+			show_debug("status change %d -> %d", Recovery_Status_Inf->recovery_status, status);
+		}
 		Recovery_Status_Inf->recovery_status = status;
 	}
 	PGRsem_unlock(SemID,SEM_NUM_OF_RECOVERY);
@@ -786,7 +796,7 @@
 	{
 		if (Recovery_Status_Inf->useFlag != DB_TBL_FREE)
 		{
-			show_debug("check recovered host %d",Recovery_Status_Inf->useFlag);
+			show_debug("check recovered host (useFlag=%d)",Recovery_Status_Inf->useFlag);
 			ptr = PGRadd_HostTbl((HostTbl *)&(Recovery_Status_Inf->target_host),Recovery_Status_Inf->useFlag);
 			if (ptr == (HostTbl *) NULL)
 			{
@@ -817,6 +827,8 @@
 		if (target != (HostTbl*)NULL)
 		{
 			memcpy((HostTbl *)&(Recovery_Status_Inf->target_host),target,sizeof(HostTbl));
+			set_function("PGRset_recovered_host");
+			show_debug("status=%d", useFlag);
 			PGRset_host_status(target,useFlag);
 		}
 
@@ -1032,6 +1044,7 @@
 	{
 		return STATUS_ERROR;
 	}
+	show_debug("hostName=%s, port=%d, recoveryPort=%d, hostNum=%d, useFlag=%d", host_ptr->hostName, host_ptr->port, host_ptr->recoveryPort, host_ptr->hostNum, host_ptr->useFlag);
 	if (host_ptr->useFlag != status)
 	{
 		host_ptr->useFlag = status;
@@ -1257,6 +1270,7 @@
 		show_debug("send_replicate_packet_to_server query=%s",query);
 	}
 
+	set_function("PGRsend_replicate_packet_to_server");
 	if (conn == NULL)
 	{
 		show_error("[%d@%s] may be down",host_ptr->port,host_ptr->hostName);
@@ -1332,7 +1346,7 @@
 
 	if (res == NULL)
 	{
-		show_error("PQexec error ");
+		show_error("PQexec error");
 		if ( header->cmdSts != CMD_STS_NOTICE )
 		{
 			PGRset_host_status(host_ptr,DB_TBL_ERROR);
@@ -1532,6 +1546,7 @@
 
 	len = strlen(hostName);
 	ptr = Host_Tbl_Begin;
+	show_debug("hostName=%s, port=%d", hostName, port);
 	if (len > sizeof(ptr->hostName))
 	{
 		len = sizeof(ptr->hostName);
