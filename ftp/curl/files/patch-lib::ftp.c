--- lib/ftp.c.orig	Thu Jun  6 17:12:12 2002
+++ lib/ftp.c	Thu Jun  6 17:13:28 2002
@@ -1067,13 +1067,13 @@
   }
   freeaddrinfo(res);
   if (portsock < 0) {
-    failf(data, strerror(errno));
+    failf(data, "%s", strerror(errno));
     return CURLE_FTP_PORT_FAILED;
   }
 
   sslen = sizeof(ss);
   if (getsockname(portsock, sa, &sslen) < 0) {
-    failf(data, strerror(errno));
+    failf(data, "%s", strerror(errno));
     return CURLE_FTP_PORT_FAILED;
   }
 
@@ -1370,7 +1370,7 @@
   
   for (modeoff = (data->set.ftp_use_epsv?0:1);
        mode[modeoff]; modeoff++) {
-    result = Curl_ftpsendf(conn, mode[modeoff]);
+    result = Curl_ftpsendf(conn, "%s", mode[modeoff]);
     if(result)
       return result;
     nread = Curl_GetFTPResponse(buf, conn, &ftpcode);
