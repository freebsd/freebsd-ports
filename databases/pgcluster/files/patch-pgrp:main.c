--- src/pgcluster/pgrp/main.c	9 May 2004 11:21:36 -0000	1.1.1.10
+++ src/pgcluster/pgrp/main.c	9 May 2004 12:57:57 -0000	1.8
@@ -133,6 +133,43 @@
 static void child_wait(SIGNAL_ARGS);
 static void usage(void);
 
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
@@ -170,11 +207,11 @@
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
@@ -192,16 +229,23 @@
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
 				query = PGRread_packet(sock,&header);
-				if (query == NULL)
+				if (query == NULL && errno != 0)
 				{
 					show_error("session closed");
 					break;
 				}
+				if (header.cmdType == 'o') {
+					dump_status(sock);
+					break;
+				}
 				if (header.cmdSts == 0)
 				{
 					break;
@@ -247,7 +291,7 @@
 	}
 }
 
-static void
+void
 startup_replication_server(void)
 {
 	ReplicateHeader  header;
@@ -301,7 +345,7 @@
 	{
 		PGRreplicate_exit(0);
 	}
-	show_debug("replicate main %d port bind OK \n",Port_Number);
+	show_debug("replicate main %d port bind OK",Port_Number);
 	
 	/* cascade start up notice */
 	if (Cascade_Inf->upper != NULL)
@@ -326,11 +370,14 @@
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
@@ -685,12 +732,12 @@
 
 	if (PGRset_Conf_Data(PGR_Data_Path) != STATUS_OK)
 	{
-		show_debug("PGRset_Conf_Data error\n");
+		show_debug("PGRset_Conf_Data error");
 		PGRreplicate_exit(0);
 	}
 	if (PGRinit_recovery() != STATUS_OK)
 	{
-		show_debug("PGRinit_recovery error\n");
+		show_debug("PGRinit_recovery error");
 		PGRreplicate_exit(0);
 	}
 	pgid = getpgid(0);
@@ -702,10 +749,10 @@
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
