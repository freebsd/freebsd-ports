--- echolinux/control.c.orig	Mon Feb  2 22:29:46 2004
+++ echolinux/control.c	Mon Mar  7 15:52:46 2005
@@ -13,7 +13,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/ioctl.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
@@ -24,7 +24,8 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <errno.h>
-#include <wait.h>
+#include <sys/types.h>
+#include <sys/wait.h>
 #include <signal.h>
 #include <string.h>
 #include <sys/time.h>
@@ -354,7 +355,7 @@
     timeout.tv_sec = 10;
     timeout.tv_usec = 0;
     }
-      
+    
     if((i == 0) && (audioPid > 0)){  // timeout & connected 
       connectTimeout++;
       if(connectTimeout == CONNECT_TRY){
@@ -388,28 +389,32 @@
 	  disconnect(FALSE);
       } 
       if(isRTCPSdespacket(inBuffer, length)){
-	if((audioPid > 0) && 
-	   (inAddr.sin_addr.s_addr == destAddr.sin_addr.s_addr)){
-	  sdesItems.nitems = 1;
-	  sdesItems.item[0].r_item = RTCP_SDES_NAME;
-	  sdesItems.item[0].r_text = NULL;
-	  remoteName[0] = 0;
-	  parseSDES(inBuffer, &sdesItems);
-	  if(sdesItems.item[0].r_text != NULL){
-	    copySDESitem(sdesItems.item[0].r_text, &remoteName[2]);
-	  }
-	  remoteName[0] = CONNECT;
-	  remoteName[1] = ' ';
-	  puts(remoteName);
-	  if(atemptingConnect){
-	    atemptingConnect = 0;
-	    fputs("P connect.wav\n", audioOutFd);
-	    fputs("I\n", audioOutFd);
-	  }
-	  connectTimeout = 0;  // reset the counter
-	}
-	else {
-	  if(audioPid<=0){
+	if (audioPid > 0) {
+	  sendto(outControlSocket,
+		 *sdesPacket,
+		 sdesLength,
+		 0,
+		 (struct sockaddr *)&destAddr,
+		 sizeof destAddr);
+	  if(inAddr.sin_addr.s_addr == destAddr.sin_addr.s_addr){
+	    sdesItems.nitems = 1;
+	    sdesItems.item[0].r_item = RTCP_SDES_NAME;
+	    sdesItems.item[0].r_text = NULL;
+	    remoteName[0] = 0;
+	    parseSDES(inBuffer, &sdesItems);
+	    if(sdesItems.item[0].r_text != NULL){
+	      copySDESitem(sdesItems.item[0].r_text, &remoteName[2]);
+	    }
+	    remoteName[0] = CONNECT;
+	    remoteName[1] = ' ';
+	    puts(remoteName);
+	    if(atemptingConnect){
+	      atemptingConnect = 0;
+	      fputs("P connect.wav\n", audioOutFd);
+	      fputs("I\n", audioOutFd);
+	    }
+	    connectTimeout = 0;  // reset the counter
+	  } else { /* audioPid <= 0 */
 	    sdesItems.nitems = 1;
 	    sdesItems.item[0].r_item = RTCP_SDES_NAME;
 	    sdesItems.item[0].r_text = NULL;
@@ -424,8 +429,6 @@
 	    makeConnection(inet_ntoa(inAddr.sin_addr));
 	    fputs("P connect.wav\n", audioOutFd);
 	    fputs("I\n", audioOutFd);
-	  }
-	  else {
 	  }
 	}
       }
