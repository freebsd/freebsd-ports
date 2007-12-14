--- tricky/ircservermanager.c.orig	2007-12-13 01:01:29.000000000 +0100
+++ tricky/ircservermanager.c	2007-12-13 01:01:44.000000000 +0100
@@ -71,7 +71,7 @@
       Error(1,"Server could not be resolved.");
       break;
       }
-   strcpy(ServerAddress,addr2ascii(PF_INET,hostn->h_addr,sizeof(hostn->h_addr),NULL));
+   strcpy(ServerAddress,inet_ntoa(*(struct in_addr *)hostn->h_addr));
    memset((char *)&SrvAddr,0,sizeof(SrvAddr)); 
 
    SrvAddr.sin_family = PF_INET;
