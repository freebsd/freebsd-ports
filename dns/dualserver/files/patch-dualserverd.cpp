--- dualserverd.cpp	2013-04-21 04:24:14.000000000 +0200
+++ dualserverd.cpp	2013-04-27 18:44:05.000000000 +0200
@@ -22,10 +22,16 @@
 #include <math.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#endif
 #include <limits.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <net/if.h>
+#ifdef __FreeBSD__
+#include <net/if_dl.h>
+#endif
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <unistd.h>
@@ -39,6 +45,9 @@
 #include <syslog.h>
 #include <pthread.h>
 #include <map>
+#ifdef __FreeBSD__
+#include <ifaddrs.h>
+#endif
 using namespace std;
 #include "dualserverd.h"
 
@@ -88,7 +97,11 @@
 //const char send200[] = "HTTP/1.1 200 OK\r\nDate: %s\r\nLast-Modified: %s\r\nContent-Type: text/html\r\nConnection: Close\r\nTransfer-Encoding: chunked\r\n";
 const char line200[] = "<td>%s</td>";
 const char send403[] = "HTTP/1.1 403 Forbidden\r\n\r\n<h1>Forbidden</h1>";
+#ifdef __FreeBSD__
+const char sVersion[] = "Dual DHCP DNS Server Version 6.94 for FreeBSD";
+#else
 const char sVersion[] = "Dual DHCP DNS Server Version 7.01 Linux Build 7018";
+#endif
 const char toprow[] = "<body bgcolor=\"#cccccc\"><table width=640><tr><td align=\"center\"><font size=\"5\"><b>%s</b></font></td></tr><tr><td align=\"right\"><a target=\"_new\" href=\"http://dhcp-dns-server.sourceforge.net\">http://dhcp-dns-server.sourceforge.net</td></tr></table>";
 const data4 opData[] =
     {
@@ -266,7 +279,11 @@
         strcpy(leaFile, "/tmp/dualserver.state");
 
     if (!iniFile[0])
+#ifdef __FreeBSD__
+        strcpy(iniFile, "/usr/local/etc/dualserver.conf");
+#else
         strcpy(iniFile, "/etc/dualserver.ini");
+#endif
 
     strcpy(filePATH, iniFile);
 
@@ -4121,7 +4138,13 @@
 	else if (req->dhcpp.header.bp_broadcast || !req->remote.sin_addr.s_addr || req->reqIP)
 	{
 		req->remote.sin_port = htons(IPPORT_DHCPC);
+#ifdef __FreeBSD__
+    req->remote.sin_addr.s_addr = network.dhcpConn[req->sockInd].addr.sin_addr.s_addr | 
+    (~network.dhcpConn[req->sockInd].mask);
+    //printf("broadcast dhcp response to %s\n",inet_ntoa(req->remote.sin_addr));
+#else
 		req->remote.sin_addr.s_addr = INADDR_BROADCAST;
+#endif
 	}
 	else
 	{
@@ -9371,6 +9394,11 @@
 					newNetwork.dhcpConn[i].broadCastSize = sizeof(newNetwork.dhcpConn[i].broadCastVal);
 
 					setsockopt(newNetwork.dhcpConn[i].sock, SOL_SOCKET, SO_BROADCAST, (char*)&newNetwork.dhcpConn[i].broadCastVal, newNetwork.dhcpConn[i].broadCastSize);
+
+#ifdef __FreeBSD__
+          // See man ip
+          setsockopt(newNetwork.dhcpConn[i].sock,IPPROTO_IP, IP_ONESBCAST,(char*)&newNetwork.dhcpConn[i].broadCastVal, newNetwork.dhcpConn[i].broadCastSize);
+#endif
 					int nRet = bind(newNetwork.dhcpConn[i].sock, (sockaddr*)&newNetwork.dhcpConn[i].addr, sizeof(struct sockaddr_in));
 
 					if (nRet == SOCKET_ERROR)
@@ -9422,7 +9450,11 @@
 					setsockopt(newNetwork.dhcpListener.sock, SOL_SOCKET, SO_REUSEADDR, (char*)&newNetwork.dhcpListener.reUseVal, newNetwork.dhcpListener.reUseSize);
 					newNetwork.dhcpListener.pktinfoVal = true;
 					newNetwork.dhcpListener.pktinfoSize = sizeof(newNetwork.dhcpListener.pktinfoVal);
+#ifdef __FreeBSD__
+					setsockopt(newNetwork.dhcpListener.sock, IPPROTO_IP, IP_RECVIF, &newNetwork.dhcpListener.pktinfoVal, newNetwork.dhcpListener.pktinfoSize);
+#else
 					setsockopt(newNetwork.dhcpListener.sock, IPPROTO_IP, IP_PKTINFO, &newNetwork.dhcpListener.pktinfoVal, newNetwork.dhcpListener.pktinfoSize);
+#endif
 
 					newNetwork.dhcpListener.addr.sin_family = AF_INET;
 					newNetwork.dhcpListener.addr.sin_addr.s_addr = INADDR_ANY;
@@ -10064,6 +10096,12 @@
 
 MYWORD gdmess(data9 *req, MYBYTE sockInd)
 {
+#ifdef __FreeBSD__
+  struct cmsghdr *cmsg;
+  struct sockaddr_dl * isdl;
+  struct sockaddr_in *isin;
+  struct ifaddrs *ifap, *ifa;
+#endif
     //sprintf(logBuff, "Socket=%u", sockInd);
 	//logDHCPMess(logBuff, 1);
     memset(req, 0, sizeof(data9));
@@ -10079,7 +10117,11 @@
         req->msg.msg_name = &req->remote;
         req->msg.msg_namelen = sizeof(sockaddr_in);
         req->msg.msg_control = &req->msgcontrol;
+#ifdef __FreeBSD__
+        req->msg.msg_controllen = sizeof(req->msgcontrol);
+#else
         req->msg.msg_controllen = sizeof(msg_control);
+#endif
         req->msg.msg_flags = msgflags;
 
         int flags = 0;
@@ -10088,6 +10130,45 @@
         if (errno || req->bytes <= 0)
             return 0;
 
+#ifdef __FreeBSD__
+        isdl = NULL;
+        isin = NULL;
+        MYDWORD addr=0;
+        bool found_addr = false;
+
+        if (req->msg.msg_controllen>0){
+          for (cmsg=CMSG_FIRSTHDR(&req->msg);cmsg;cmsg=CMSG_NXTHDR(&req->msg,cmsg)){
+            if (cmsg->cmsg_type==IP_RECVIF) {
+              isdl=(struct sockaddr_dl *)CMSG_DATA(cmsg);
+            }
+          }
+        }
+
+        if (!isdl || getifaddrs(&ifap))
+          return 0;
+
+        for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
+          if(ifa->ifa_addr->sa_family == AF_INET &&
+          strcmp(ifa->ifa_name,isdl->sdl_data) == 0){
+            isin = (struct sockaddr_in *)ifa->ifa_addr;
+            addr = isin->sin_addr.s_addr;
+            for (int i = 0; (i < MAX_SERVERS || !network.dhcpConn[i].server);i++){
+              if (addr == network.dhcpConn[i].server){
+                found_addr = true;
+                req->sockInd = i;
+                break;
+              }
+            }
+          }
+        }
+        freeifaddrs(ifap);
+
+        if(!found_addr) return 0;
+
+        //printf("IF = %s\n", isdl->sdl_data);
+        //printf("RADDR = %s\n", inet_ntoa(isin->sin_addr));
+        
+#else
         //printf("%u\n", req->msg.msg_controllen);
         //msgcontrol = (msg_control*)msg.msg_control;
 
@@ -10101,7 +10182,6 @@
         //printf("LADDR = %s\n", inet_ntoa(req->msgcontrol.pktinfo.ipi_addr));
         //printf("RADDR = %s\n", inet_ntoa(req->msgcontrol.   pktinfo.ipi_spec_dst));
 
-
         MYDWORD addr = req->msgcontrol.pktinfo.ipi_spec_dst.s_addr;
 
         //printf("%s\n",IP2String(tempbuff, addr));
@@ -10119,6 +10199,7 @@
                 break;
             }
         }
+#endif
     }
     else
     {
