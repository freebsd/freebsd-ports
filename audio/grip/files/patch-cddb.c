--- cddb.c.orig	Mon Jul 16 12:15:32 2001
+++ cddb.c	Mon Jan 21 22:51:21 2002
@@ -27,6 +27,9 @@
 #include <strings.h>
 #endif
 #include <ctype.h>
+#include <fcntl.h>
+#include <pthread.h>
+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
@@ -43,7 +46,7 @@
 extern char *Version;
 
 static int CDDBSum(int val);
-static int CDDBConnect(CDDBServer *server);
+static int CDDBConnect(CDDBServer *server, int ns);
 static void CDDBDisconnect(int sock);
 static void CDDBSkipHTTP(int sock);
 static int CDDBReadLine(int sock,char *inbuffer,int len);
@@ -59,6 +62,81 @@
 			    "data","folk","jazz","misc","newage",
 			    "reggae","rock","soundtrack"};
 
+/* nonblocking connect */
+
+static int
+nonbconnect(int fd, struct sockaddr *pa, socklen_t cba, int ns)
+{
+  int n;
+  int s;
+  int fl;
+  fd_set rfds, wfds;
+  struct timeval tv;
+
+  if (!ns) {
+    n = connect(fd, pa, cba);
+    pthread_testcancel();
+    return n;
+  }
+
+  fl = fcntl(fd, F_GETFL, 0);
+  fcntl(fd, F_SETFL, fl | O_NONBLOCK);
+
+  if ((n = connect(fd, pa, cba)) < 0) {
+    if (errno != EINPROGRESS) {
+      return -1;
+    }
+  } else if (n == 0) {
+    fcntl(fd, F_SETFL, fl);
+    return 0;
+  }
+
+
+  for (s = 0; s < ns; s++) {
+    tv.tv_sec = 1;
+    tv.tv_usec = 0;
+    FD_ZERO(&rfds);
+    FD_SET(fd, &rfds);
+    wfds = rfds;
+    if ((n = select(fd + 1, &rfds, &wfds, 0, &tv)) > 0) {
+      break;
+    } else if (n < 0) {
+      if (errno == EINTR) {
+        s--;
+      } else {
+        return -1;
+      }
+    }
+    pthread_testcancel();
+  }
+      
+  if (n == 0 && s == ns) {
+    errno = ETIMEDOUT;
+    return -1;
+  }
+
+  if (FD_ISSET(fd, &rfds) || FD_ISSET(fd, &wfds)) {
+    int err;
+    int cberr = sizeof(err);
+
+    getsockopt(fd, SOL_SOCKET, SO_ERROR, &err, &cberr);
+    if (err) {
+      errno = err;
+      return -1;
+    }
+    fcntl(fd, F_SETFL, fl);
+    tv.tv_sec = ns; 
+    tv.tv_usec = 0;
+    setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
+    return 0;
+  }
+
+  /* ohshit */
+
+  errno = EIO; /* WTF? */
+  return -1;
+}
+
 /* CDDB sum function */
 
 static int CDDBSum(int val)
@@ -115,7 +193,7 @@
 }
 
 /* Connect to a CDDB server */
-static int CDDBConnect(CDDBServer *server)
+static int CDDBConnect(CDDBServer *server, int ns)
 {
   int sock;
   struct sockaddr_in sin;
@@ -146,8 +224,10 @@
 
   if((sock=socket(AF_INET,SOCK_STREAM,0))<0) return -1;
   
-  if(connect(sock,(struct sockaddr *)&sin,sizeof(sin))<0) return -1;
-  
+  if(nonbconnect(sock,(struct sockaddr *)&sin,sizeof(sin),ns)<0) {
+    close(sock);
+    sock = -1;
+  }
   return sock;
 }
 
@@ -243,7 +323,7 @@
 /* Query the CDDB for the CD currently in the CD-ROM */
 
 gboolean CDDBDoQuery(int cd_desc,CDDBServer *server,
-		     CDDBHello *hello,CDDBQuery *query)
+		     CDDBHello *hello,CDDBQuery *query, int ns)
 {
   int socket;
   int index;
@@ -251,7 +331,7 @@
   char *offset_buffer,*query_buffer,*http_buffer,inbuffer[256];
   int tot_len,len;
 
-  socket=CDDBConnect(server);
+  socket=CDDBConnect(server,ns);
 
   if(socket==-1) return FALSE;
 
@@ -476,14 +556,14 @@
 
 gboolean CDDBRead(int cd_desc,CDDBServer *server,
 		  CDDBHello *hello,CDDBEntry *entry,
-		  DiscData *data)
+		  DiscData *data, int ns)
 {
   int socket;
   int index;
   char outbuffer[256], inbuffer[512],cmdbuffer[256];
   struct disc_info disc;
   
-  socket=CDDBConnect(server);
+  socket=CDDBConnect(server,ns);
   if(socket==-1) return FALSE;
   
   CDStat(cd_desc,&disc,TRUE);
