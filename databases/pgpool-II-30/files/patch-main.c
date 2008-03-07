--- main.c.orig	2007-11-09 13:37:35.000000000 +0900
+++ main.c	2008-03-03 10:24:27.651654702 +0900
@@ -836,7 +836,13 @@
 	status = bind(fd, (struct sockaddr *)&addr, len);
 	if (status == -1)
 	{
-		pool_error("bind() failed. reason: %s", strerror(errno));
+		char *host = "", *serv = "";
+		char hostname[NI_MAXHOST], servname[NI_MAXSERV];
+		if (getnameinfo(&addr, len, hostname, sizeof(hostname), servname, sizeof(servname), 0) == 0) {
+			host = hostname;
+			serv = servname;
+		}
+		pool_error("bind(%s:%s) failed. reason: %s", host, serv, strerror(errno));
 		myexit(1);
 	}
 
@@ -872,7 +878,7 @@
 	status = bind(fd, (struct sockaddr *)&addr, len);
 	if (status == -1)
 	{
-		pool_error("bind() failed. reason: %s", strerror(errno));
+		pool_error("bind(%s) failed. reason: %s", addr.sun_path, strerror(errno));
 		myexit(1);
 	}
 
@@ -891,6 +897,12 @@
 	return fd;
 }
 
+static void myunlink(const char* path)
+{
+	if (unlink(path) == 0) return;
+	pool_error("unlink(%s) failed: %s", path, strerror(errno));
+}
+
 static void myexit(int code)
 {
 	char path[POOLMAXPATHLEN];
@@ -917,10 +929,10 @@
 		POOL_SETMASK(&UnBlockSig);
 	}
 	
-	unlink(un_addr.sun_path);
-	unlink(pcp_un_addr.sun_path);
+	myunlink(un_addr.sun_path);
+	myunlink(pcp_un_addr.sun_path);
 	snprintf(path, sizeof(path), "%s/%s", pool_config->logdir, PID_FILE_NAME);
-	unlink(path);
+	myunlink(path);
 
 	pool_shmem_exit(code);
 	exit(code);
