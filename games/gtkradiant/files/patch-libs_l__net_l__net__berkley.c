--- libs/l_net/l_net_berkley.c.orig	2006-02-10 22:01:20 UTC
+++ libs/l_net/l_net_berkley.c
@@ -438,7 +438,7 @@ static int PartialIPAddress (char *in, s
 		addr = (addr<<8) + num;
 	}
 	
-	hostaddr->sa_family = AF_INET;
+	((struct sockaddr_in *)hostaddr)->sin_family = AF_INET;
 	((struct sockaddr_in *)hostaddr)->sin_port = htons((u_short)net_hostport);
 	((struct sockaddr_in *)hostaddr)->sin_addr.s_addr = (myAddr & htonl(mask)) | htonl(addr);
 	
@@ -657,7 +657,7 @@ int WINS_StringToAddr(char *string, stru
 	sscanf(string, "%d.%d.%d.%d:%d", &ha1, &ha2, &ha3, &ha4, &hp);
 	ipaddr = (ha1 << 24) | (ha2 << 16) | (ha3 << 8) | ha4;
 
-	addr->sa_family = AF_INET;
+	((struct sockaddr_in *)addr)->sin_family = AF_INET;
 	((struct sockaddr_in *)addr)->sin_addr.s_addr = htonl(ipaddr);
 	((struct sockaddr_in *)addr)->sin_port = htons((u_short)hp);
 	return 0;
@@ -718,7 +718,7 @@ int WINS_GetAddrFromName(char *name, str
 	if (!hostentry)
 		return -1;
 
-	addr->sa_family = AF_INET;
+	((struct sockaddr_in *)addr)->sin_family = AF_INET;
 	((struct sockaddr_in *)addr)->sin_port = htons((u_short)net_hostport);
 	((struct sockaddr_in *)addr)->sin_addr.s_addr = *(int *)hostentry->h_addr_list[0];
 
