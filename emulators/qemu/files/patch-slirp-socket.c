# 1.6
Index: qemu/slirp/socket.c
@@ -573,6 +573,7 @@
 	addr.sin_port = port;
 	
 	if (((s = socket(AF_INET,SOCK_STREAM,0)) < 0) ||
+	    (setsockopt(s,SOL_SOCKET,SO_REUSEADDR,(char *)&opt,sizeof(int)) < 0) ||
 	    (bind(s,(struct sockaddr *)&addr, sizeof(addr)) < 0) ||
 	    (listen(s,1) < 0)) {
 		int tmperrno = errno; /* Don't clobber the real reason we failed */
@@ -587,7 +588,6 @@
 #endif
 		return NULL;
 	}
-	setsockopt(s,SOL_SOCKET,SO_REUSEADDR,(char *)&opt,sizeof(int));
 	setsockopt(s,SOL_SOCKET,SO_OOBINLINE,(char *)&opt,sizeof(int));
 	
 	getsockname(s,(struct sockaddr *)&addr,&addrlen);
